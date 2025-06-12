#ifndef MQTTSETUP_H
#define MQTTSETUP_H

#include <PubSubClient.h>

void setupMQTT(PubSubClient& client, const char* server, void (*callback)(char*, byte*, unsigned int));
void reconnect(PubSubClient& client);

#endif
