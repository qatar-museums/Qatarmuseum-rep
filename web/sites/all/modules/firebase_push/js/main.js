/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
(function ($) {
  Drupal.behaviors.firebase_push = {
    attach: function (context, settings) {
      $('body', context).once('firebase_push', function () {
        var service_worker_path = Drupal.settings.service_worker;
        // Initialize Firebase.
        var config = JSON.parse(Drupal.settings.sw_config);
        firebase.initializeApp(config);
        navigator.serviceWorker.register(service_worker_path)
          .then((registration) => {
            var messaging = firebase.messaging();
            var firebasednd = getCookie('firebasednd');
            if ((firebasednd !== 1 || firebasednd === 'undefine')) {
              messaging.useServiceWorker(registration);
              messaging.requestPermission()
               .then(function () {
                console.log('have permission');
                return messaging.getToken();
              })
              .then(function (token) {
                  sendSubscriptionToServer (token, 'POST');
                  console.log(token);
              })
              .catch(function (err) {
                // On denay ask again after one day.
                setcookies(1);
                console.log('error permission ' + err.message);
              });
            }
            else {
              console.log('Token already register');
            }
            messaging.onMessage(function (payload) {
              console.log('onMessage1:', payload);
            });
          });

        /**
         *  Send subscription to server.
         **/
        function sendSubscriptionToServer (token, method) {
          var d = new Date();
           $.post('/firebase_push/subscription?' + d.getTime(),
            JSON.stringify({
              registration_id: token,
              type: 'web'
            }),
            function () {
            setcookies(365);
          });
        }

        /**
         * function to set cookies by expairy time.
         **/
        function setcookies (exdays) {
          var d = new Date();
          d.setTime(d.getTime() + (exdays * 24 * 60 * 60 * 1000));
          var expires = 'expires=' + d.toUTCString();
          document.cookie = 'firebasednd=1;domain=' + document.domain + ';' + expires + ';path=/ ';
        }

        /**
         * function to read cookie by name.
         **/
        function getCookie(cname) {
          var name = cname + '=';
          var decodedCookie = document.cookie;
          var ca = decodedCookie.split(';');
          for (var i = 0; i < ca.length; i++) {
            var c = ca[i];
            while (c.charAt(0) === ' ') {
              c = c.substring(1);
            }
            if (c.indexOf(name) === 0) {
              return c.substring(name.length, c.length);
            }
          }
          return 'undefine';
        }
      });
    }
  };
})(jQuery);
