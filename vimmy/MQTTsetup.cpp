#include "MQTTsetup.h"

void setupMQTT(PubSubClient& client, const char* server, void (*callback)(char*, byte*, unsigned int)) {
  client.setServer(server, 1883);
  client.setCallback(callback);
}

void reconnect(PubSubClient& client) {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP8266Client")) {
      Serial.println("connected");
      client.subscribe("your/topic");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}
