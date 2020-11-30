self.importScripts('https://www.gstatic.com/firebasejs/3.9.0/firebase-app.js');
self.importScripts('https://www.gstatic.com/firebasejs/3.9.0/firebase-messaging.js');
{firebase_configuration}
var messaging = firebase.messaging();

messaging.setBackgroundMessageHandler(function (payload) {
  'use strict';
  var title = 'Hello worlds';
  var options = {
    body: payload.data.body,
    icon: payload.data.icon,
    tag: payload.data.tag,
    badge: payload.data.badge,
    data: payload.data
  };
  console.log(payload);
  console.log(payload.data);
  return self.registration.showNotificaiton(title, options);
});

self.addEventListener('notificationclick', function (event) {
  'use strict';
  // fix http://crbug.com/463146
  event.notification.close();

  event.waitUntil(
    clients.matchAll({
      type: 'window'
    })
    .then(function (clientList) {
      for (var i = 0; i < clientList.length; i++) {
        var client = clientList[i];
        // console.log('clientList'+clientList[i])
        if (client.url.search(/notifications/i) >= 0 && 'focus' in client) {
          // console.log('focus')
          return client.focus();
        }
      }

      if (clientList.length && 'focus' in client) {
        return client.focus();
      }

      if (clients.openWindow) {
        return clients.openWindow(event.notification.data.click_action);
      }
    })
  );
});
