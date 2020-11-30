<?php

/**
 * Generate a MIGS Digital Order URL
 *
 * @param array $args with details of transaction
 * @return string URL for redirect
 */
function commerce_migs_hosted_build_url($args,$settings) {
  
  
  $md5HashData = $args['secure_secret'] . 
  $args['access_code'] . 
  $args['amount'] .
  'pay' . 
  $args['locale'] . 
  $args['merchant_reference'] .
  $args['merchant_id'] . 
  $args['order_info'] . 
  $args['return_url'] .
  $args['version'].
  $args['card_type'] ;
  
  $url =  $settings['commerce_migs_hosted_payment_url'] . '?' .
    'vpc_AccessCode='   . urlencode($args['access_code']) .
    '&vpc_Amount='      . urlencode($args['amount']) .
    '&vpc_Command='     . urlencode('pay') .
    '&vpc_Locale='      . urlencode($args['locale']) .
    '&vpc_MerchTxnRef=' . urlencode($args['merchant_reference']) .
    '&vpc_Merchant='    . urlencode($args['merchant_id']) .
    '&vpc_OrderInfo='   . urlencode($args['order_info']) .
    '&vpc_ReturnURL='   . urlencode($args['return_url']) .
    '&vpc_Version='     . urlencode($args['version']) .
	'&vpc_Card='		. urlencode($args['card_type']) .
    '&vpc_SecureHash='  . strtoupper(md5($md5HashData));
  


  
  return $url;
}


/**
 * Process a MIGS Digital Receipt request
 *
 * @param string $secure_secret
 * @return integer MIGS response code
 */
function commerce_migs_hosted_validate_transaction($secure_secret) {
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
      return 'TRANSACTION_BADHASH';
    }
    else {
      // validation success; fall thru to next phase
    }
  } else {
    // Secure Hash was not validated, none there to validate
    return 'TRANSACTION_NOHASH';
  }
  
  //$order = uc_order_load($orderInfo);
  /*if ($order === FALSE) {
    return 'TRANSACTION_NOORDER';
  }*/

  // checking order status - bit late to do that here we have already paid
  /*
  switch (uc_order_status_data($order->order_status, 'state')) {
    case 'in_checkout' :
      watchdog('uc_migs', 'MIGS payment notification received for order @order_id.', array('@order_id'=>$orderInfo));
      break ;
    case 'post_checkout' :
      return 'TRANSACTION_ORDERPOSTCHECKOUT';
    default:
      if (variable_get('commerce_migs_repeat_checkouts', FALSE)) {
        watchdog('commerce_migs', 'MIGS payment repeat notification received for order @order_id.', array('@order_id'=>$orderInfo));
        drupal_set_message('Permitting repeat checkout via MIGS.'); // it's for debug! localize the nag away if you must.
        break ;
      }
      return 'TRANSACTION_ORDERNOTYETINCHECKOUT';
  }*/

  if ( $txnResponseCode != "0") {
    return 'TRANSACTION_PAYMENTERROR';
  } else {
    return 'TRANSACTION_SUCCESS';
  }
}