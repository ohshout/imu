#include <mqttclient.h>
#define SAMPLING_PERIOD   100
#define PUBLISH_INTERVAL  30000

MQTTClient mqttClient;

void setup() {
   mqttClient.begin(“localhost”,1833,PSK,NULL,”psk_user”,”psk_password”);
   mqttClient.subscribe(“edison/#”,myCallBack);
}

void myCallBack(char* topic, char* message) {
   // scan for matching topic, scan for matching command, do something useful
}

unsigned long publishTime = millis();
void loop() {
   mqttClient.loop();        // check for new message
   if (millis() > publishTime) {
       publishTime = millis() + PUBLISH_INTERVAL;
       mqttClient.publish(“edison/sensor1”,”sensor1value”);
       mqttClient.publish(“edison/sensor2”,”sensor2value”);
   }
   delay(SAMPLING_PERIOD);
}
