<?php

/**
 * Generate a MIGS Digital Order URL
 *
 * @param array $args with details of transaction
 * @return string URL for redirect
 */
function _uc_migs_migs_do_url($args) {
  $md5HashData = $args['secure_secret'] . $args['vpc_AccessCode'] . $args['vpc_Amount'] . 'pay' . $args['vpc_Locale'] . $args['vpc_MerchTxnRef'] . $args['vpc_Merchant'] . $args['vpc_OrderInfo'] . $args['vpc_ReturnURL'] . $args['vpc_Version'];
  $url = variable_get('uc_migs_base_url', UC_MIGS_BASE_URL) . '?' .
    'vpc_AccessCode='   . urlencode($args['vpc_AccessCode']) .
    '&vpc_Amount='      . urlencode($args['vpc_Amount']) .
    '&vpc_Command='     . urlencode('pay') .
    '&vpc_Locale='      . urlencode($args['vpc_Locale']) .
    '&vpc_MerchTxnRef=' . urlencode($args['vpc_MerchTxnRef']) .
    '&vpc_Merchant='    . urlencode($args['vpc_Merchant']) .
    '&vpc_OrderInfo='   . urlencode($args['vpc_OrderInfo']) .
    '&vpc_ReturnURL='   . urlencode($args['vpc_ReturnURL']) .
    '&vpc_Version='     . urlencode($args['vpc_Version']) .
    '&vpc_SecureHash='  . strtoupper(md5($md5HashData));
  return $url;
}

/**
 * Process a MIGS Digital Receipt request
 *
 * @param string $secure_secret
 * @return integer MIGS response code
 */
function _uc_migs_validate_transaction($secure_secret) {
  // Standard Receipt Data
  $amount          = (isset($_GET['vpc_Amount'])) ? $_GET['vpc_Amount'] : NULL;
  $locale          = (isset($_GET['vpc_Locale'])) ? $_GET['vpc_Locale'] : NULL;
  $batchNo         = (isset($_GET['vpc_BatchNo'])) ? $_GET['vpc_BatchNo'] : NULL;
  $command         = (isset($_GET['vpc_Command'])) ? $_GET['vpc_Command'] : NULL;
  $message         = (isset($_GET['vpc_Message'])) ? $_GET['vpc_Message'] : NULL;
  $version         = (isset($_GET['vpc_Version'])) ? $_GET['vpc_Version'] : NULL;
  $cardType        = (isset($_GET['vpc_Card'])) ? $_GET['vpc_Card'] : NULL;
  $orderInfo       = (isset($_GET['vpc_OrderInfo'])) ? $_GET['vpc_OrderInfo'] : NULL;
  $receiptNo       = (isset($_GET['vpc_ReceiptNo'])) ? $_GET['vpc_ReceiptNo'] : NULL;
  $merchantID      = (isset($_GET['vpc_Merchant'])) ? $_GET['vpc_Merchant'] : NULL;
  $authorizeID     = (isset($_GET['vpc_AuthorizeId'])) ? $_GET['vpc_AuthorizeId'] : NULL;
  $merchTxnRef     = (isset($_GET['vpc_MerchTxnRef'])) ? $_GET['vpc_MerchTxnRef'] : NULL;
  $transactionNo   = (isset($_GET['vpc_TransactionNo'])) ? $_GET['vpc_TransactionNo'] : NULL;
  $acqResponseCode = (isset($_GET['vpc_AcqResponseCode'])) ? $_GET['vpc_AcqResponseCode'] : NULL;
  $txnResponseCode = check_plain((isset($_GET['vpc_TxnResponseCode'])) ? $_GET['vpc_TxnResponseCode'] : NULL);
  $plain_message   = check_plain((isset($_GET['vpc_Message'])) ? $_GET['vpc_Message'] : NULL);

  // 3-D Secure Data
  $verType         = array_key_exists('vpc_VerType', $_GET)          ? $_GET['vpc_VerType']          : "No Value Returned";
  $verStatus       = array_key_exists('vpc_VerStatus', $_GET)        ? $_GET['vpc_VerStatus']        : "No Value Returned";
  $token           = array_key_exists('vpc_VerToken', $_GET)         ? $_GET['vpc_VerToken']         : "No Value Returned";
  $verSecurLevel   = array_key_exists('vpc_VerSecurityLevel', $_GET) ? $_GET['vpc_VerSecurityLevel'] : "No Value Returned";
  $enrolled        = array_key_exists('vpc_3DSenrolled', $_GET)      ? $_GET['vpc_3DSenrolled']      : "No Value Returned";
  $xid             = array_key_exists('vpc_3DSXID', $_GET)           ? $_GET['vpc_3DSXID']           : "No Value Returned";
  $acqECI          = array_key_exists('vpc_3DSECI', $_GET)           ? $_GET['vpc_3DSECI']           : "No Value Returned";
  $authStatus      = array_key_exists('vpc_3DSstatus', $_GET)        ? $_GET['vpc_3DSstatus']        : "No Value Returned";

  $vpc_Txn_Secure_Hash = isset($_GET['vpc_SecureHash']) ? $_GET['vpc_SecureHash'] : '';
  $errorExists = FALSE ;

  if ( $txnResponseCode != 7 && $txnResponseCode != '' ) {
    $md5HashData = $secure_secret;
    // sort all the incoming vpc response fields and leave out any
    // with no value, or which are "vpc_SecureHash" or "q"
    foreach($_GET as $key => $value) {
      if ($key != "vpc_SecureHash" && $key != "q" && strlen($value) > 0) { // strlen()>0 not empty() because of '0'
        $md5HashData .= $value;
      }
    }
    // validate secure hash
    if (strtoupper($vpc_Txn_Secure_Hash) != strtoupper(md5($md5HashData))) {
      return UC_MIGS_TRANSACTION_BADHASH;
    }
    else {
      // validation success; fall thru to next phase
    }
  } else {
    // Secure Hash was not validated, none there to validate
    return UC_MIGS_TRANSACTION_NOHASH;
  }

  $order = uc_order_load($orderInfo);
  if ($order === FALSE) {
    return UC_MIGS_TRANSACTION_NOORDER;
  }

  switch (uc_order_status_data($order->order_status, 'state')) {
    case 'in_checkout' :
      watchdog('uc_migs', 'MIGS payment notification received for order @order_id.', array('@order_id'=>$orderInfo));
      break ;
    case 'post_checkout' :
      return UC_MIGS_TRANSACTION_ORDERPOSTCHECKOUT;
    default:
      if (variable_get('uc_migs_repeat_checkouts', FALSE)) {
        watchdog('uc_migs', 'MIGS payment repeat notification received for order @order_id.', array('@order_id'=>$orderInfo));
        drupal_set_message('Permitting repeat checkout via MIGS.'); // it's for debug! localize the nag away if you must.
        break ;
      }
      return UC_MIGS_TRANSACTION_ORDERNOTYETINCHECKOUT;
  }

  if ( $txnResponseCode != "0") {
    return UC_MIGS_TRANSACTION_PAYMENTERROR;
  } else {
    return UC_MIGS_TRANSACTION_SUCCESS;
  }
}

/**
 * This method uses the QSI Response code retrieved from the Digital
 * Receipt and returns an appropriate description for the QSI Response Code
 *
 * @param $responseCode String containing the QSI Response Code
 *
 * @return String containing the appropriate description
 */
function _uc_migs_get_response_description($responseCode) {
  switch ($responseCode) {
    case '0' :
      $result = "Transaction Successful";
      break;
    case '?' :
      $result = "Transaction status is unknown";
      break;
    case '1' :
      $result = "Transaction could not be processed";
      break;
    case '2' :
      $result = "Bank Declined Transaction";
      break ;
    case '3' :
      $result = "No Reply from Bank";
      break ;
    case '4' :
      $result = "Expired Card";
      break ;
    case '5' :
      $result = "Insufficient funds";
      break ;
    case '6' :
      $result = "Error Communicating with Bank";
      break ;
    case '7' :
      $result = "Payment Server System Error";
      break ;
    case '8' :
      $result = "Transaction Type Not Supported";
      break ;
    case '9' :
      $result = "Bank declined transaction (Do not contact Bank)";
      break ;
    case 'A' :
      $result = "Transaction Aborted";
      break ;
    case 'C' :
      $result = "Transaction Cancelled";
      break ;
    case 'D' :
      $result = "Deferred transaction has been received and is awaiting processing";
      break ;
    case 'F' :
      $result = "3D Secure Authentication failed";
      break ;
    case 'I' :
      $result = "Card Security Code verification failed";
      break ;
    case 'L' :
      $result = "Shopping Transaction Locked (Please try the transaction again later)";
      break ;
    case 'N' :
      $result = "Cardholder is not enrolled in Authentication scheme";
      break ;
    case 'P' :
      $result = "Transaction has been received by the Payment Adaptor and is being processed";
      break ;
    case 'R' :
      $result = "Transaction was not processed - Reached limit of retry attempts allowed";
      break ;
    case 'S' :
      $result = "Duplicate SessionID (OrderInfo)";
      break ;
    case 'T' :
      $result = "Address Verification Failed";
      break ;
    case 'U' :
      $result = "Card Security Code Failed";
      break ;
    case 'V' :
      $result = "Address Verification and Card Security Code Failed";
      break ;
    default  :
      $result = "Unable to be determined";
  }
  return $result;
}

/**
 * This method uses the QSI Response code retrieved from the Digital
 * Receipt and returns an appropriate description for the QSI Response Code
 *
 * @param $statusResponse String containing the QSI Response Code
 *
 * @return string containing the appropriate description
 */
function _uc_migs_get_status_description($statusResponse) {
  if ($statusResponse == '' || $statusResponse == 'No Value Returned') {
    $result = "3DS not supported or there was no 3DS data provided";
  } else {
    switch ($statusResponse) {
      case 'Y' :
        $result = "The cardholder was successfully authenticated.";
        break;
      case 'E' :
        $result = "The cardholder is not enrolled.";
        break;
      case 'N' :
        $result = "The cardholder was not verified.";
        break;
      case 'U' :
        $result = "The cardholder's Issuer was unable to authenticate due to some system error at the Issuer.";
        break;
      case 'F' :
        $result = "There was an error in the format of the request from the merchant.";
        break;
      case 'A' :
        $result = "Authentication of your Merchant ID and Password to the ACS Directory Failed.";
        break;
      case 'D' :
        $result = "Error communicating with the Directory Server.";
        break;
      case 'C' :
        $result = "The card type is not supported for authentication.";
        break;
      case 'S' :
        $result = "The signature on the response received from the Issuer could not be validated.";
        break;
      case 'P' :
        $result = "Error parsing input from Issuer.";
        break;
      case 'I' :
        $result = "Internal Payment Server system error.";
        break;
      default  :
        $result = "Unable to be determined";
        break;
    }
  }
  return $result;
}

function _uc_migs_select_transaction_results(&$element) {
  $prefix = substr($element['#value'], 0, strlen($element['#value'])-2);
  $element['#title'] = 'MIGS Transaction Debug';
  $element['#description'] = t('Disable transaction debugging at !link » !title » !select_return_codes', array('!link' => l('Payment method settings', 'admin/store/settings/payment/edit/methods'), '!title' => t('MIGS 3rd party settings'), '!select_return_codes' => t(UC_MIGS_SELECT_RETURN_CODES)));
  $element['#type'] = 'select';
  unset($element['#value']);
  $element['#default_value'] = $prefix.'00';
  $element['#options'] = array(
    $prefix.'00' => 'Approved',
    $prefix.'10' => 'Could not be processed',
    $prefix.'05' => 'Declined - contact bank',
    $prefix.'68' => 'No reply',
    $prefix.'33' => 'Expired',
    $prefix.'51' => 'No Credit',
  );
}

/**
 * Helper function to return a structured array of supported card
 * types MIGS offers.
 */
function _uc_migs_card_types() {
  $card_types = array(
    'mastercard' => array(
      'name' => 'MasterCard',
      'logo_remote' => 'https://migs.mastercard.com.au/res/svr/default/images/cards/card_sm_masterc.gif',
      'logo_local' => variable_get('uc_migs_logo_mastercard', variable_get('file_public_path', conf_path() . '/files') . '/uc_migs/mastercard.gif'),
    ),
    'visa' => array(
      'name' => 'VISA',
      'logo_remote' => 'https://migs.mastercard.com.au/res/svr/default/images/cards/card_sm_visa.gif',
      'logo_local' => variable_get('uc_migs_logo_visa', variable_get('file_public_path', conf_path() . '/files') . '/uc_migs/visa.gif'),
    ),
    'amex' => array(
      'name' => 'American Express',
      'logo_remote' => 'https://migs.mastercard.com.au/res/svr/default/images/cards/card_sm_amex.gif',
      'logo_local' => variable_get('uc_migs_logo_amex', variable_get('file_public_path', conf_path() . '/files') . '/uc_migs/amex.gif'),
    ),
    'jcb' => array(
      'name' => 'JCB',
      'logo_remote' => 'https://migs.mastercard.com.au/res/svr/default/images/cards/card_sm_jcb.gif',
      'logo_local' => variable_get('uc_migs_logo_jcb', variable_get('file_public_path', conf_path() . '/files') . '/uc_migs/jcb.gif'),
    ),
    'diners' => array(
      'name' => 'Diners Club',
      'logo_remote' => 'https://migs.mastercard.com.au/res/svr/default/images/cards/card_sm_dinersclub.gif',
      'logo_local' => variable_get('uc_migs_logo_diners', variable_get('file_public_path', conf_path() . '/files') . '/uc_migs/diners.gif'),
    ),
  );
  foreach ($card_types as &$card_type) {
    $card_type['logo'] = (file_exists($card_type['logo_local'])) ? $card_type['logo_local'] : $card_type['logo_remote'];
  }
  return $card_types;
}
