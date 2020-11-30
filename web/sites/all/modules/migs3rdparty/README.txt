Commerce MIGS Merchant Module
=============================

A payment method for Drupal Commerce for the MIGS payment gateway.

Used by ANZ eGate, CommWebb, Commonwealth Bank of Australia, Bendigo Bank, 
and other banks worldwide. Payment gateway for EFTPOS in New Zealand.

Based heavily on Ubercart MIGS, Commerce MIGS Merchant, and Commerce DPS

Installation
============

1. Download the module to your contrib module directory and enable.

2. go to admin/commerce/config/payment-methods and enable the 
"MIGS credit card - 3rd Party hosted" rule.

3. When the rule is enabled, hit the 'edit' link, 
then the 'edit' link on the action.

4. Under 'Payment Settings' configure the payment method with 
credentials supplied by your bank.

Other Notes
============

The follwoing rule can be added to set orders to processing on successfull payments to

{ "rules_update_order_status_on_payment" : {
    "LABEL" : "Update Order Status on Payment by 3rd Party MIGS",
    "PLUGIN" : "reaction rule",
    "TAGS" : [ "Commerce Payment" ],
    "REQUIRES" : [ "commerce_payment", "commerce_order" ],
    "ON" : [ "commerce_payment_order_paid_in_full" ],
    "IF" : [
      { "commerce_payment_selected_payment_method" : {
          "commerce_order" : [ "commerce_order" ],
          "method_id" : "commerce_migs_hosted"
        }
      }
    ],
    "DO" : [
      { "commerce_order_update_status" : { "commerce_order" : [ "commerce_order" ], "order_status" : "processing" } }
    ]
  }
} 
