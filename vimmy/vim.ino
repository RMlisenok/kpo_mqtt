#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "WIFIsetup.h"
#include "MQTTsetup.h"
#include "DisplaySetup.h"
#include "TouchButton.h"

const char* ssid = "your-SSID";
const char* password = "your-PASSWORD";
const char* mqtt_server = "your-mqtt-broker-address";

WiFiClient espClient;
PubSubClient client(espClient);
int emotion = 0;

void callback(char* topic, byte* payload, unsigned int length) {
  String message = "";
  for (unsigned int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  Serial.println(message);
  
  // Обработка сообщений и обновление дисплея
  emotion = message.toInt();
  displayEmotion(emotion);
}

void setup() {
  Serial.begin(115200);
  setupWiFi(ssid, password);
  setupDisplay();
  setupTouchButton();
  setupMQTT(client, mqtt_server, callback);
}

void loop() {
  if (!client.connected()) {
    reconnect(client);
  }
  client.loop();

  if (isButtonPressed()) {
    Serial.println("Button pressed");
    emotion = (emotion + 1) % 7; // Всего семь эмоций
    displayEmotion(emotion);
    delay(200);  // Задержка для предотвращения дребезга
  }
}
