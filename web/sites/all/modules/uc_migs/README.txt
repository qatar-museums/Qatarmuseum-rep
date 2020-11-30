Installation
------------
See INSTALL.txt in this directory.

Configuration
-------------
If you are a developer and do not have a live MIGS account, contact the bank
you are setting up the site for, and request a set of development
credentials for testing.

Contact details will be provided in your bank documentation.

ANZ Australia & New Zealand -
 * http://www.anz.com/australia/business/merchant/pdf/MIGSProductGuide.pdf
 * http://www.anz.com/australia/business/merchant/pdf/VPC-Dev-Kit-Integration-Notes.pdf

(feel free to submit docs URLs for other banks)

Themeing
--------
Some banks have various requirements for deployment. 

For example, ANZ / EFTPOS NZ requirements <http://www.eftpos.co.nz/developer> 
state that the VISA flag logo must be in full colour, and that the Verified by
VISA and MasterCard SecureCode logos must be displayed.

As this practice may vary from bank to bank and site to site, you will probably
need to make some theme modifications to suit.

The uc_migs module provides theme functions for you to implement your bank's 
requirements on your own site.


Feedback
--------
Improvements to this documentation are welcome, preferably in the form of a
patch submitted or issue submitted via http://drupal.org/project/uc_migs


Contributors
------------
Maintained by Chris Burgess (@grobot)

Thanks to previous authors & contributors -
  T-Rex Art    - http://www.trexart.com.au
  Open Web Lab - http://www.openweblab.com


Sponsors
--------
Thanks to Morgan <www.morgan.net.au> for sponsoring development of the 7.x-2.x
release of this module!