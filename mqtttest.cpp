#include <mqttclient.h>
#include <string.h>
#include <unistd.h>

#define SAMPLING_PERIOD   100
#define PUBLISH_INTERVAL  30000

mqttclient client;
void myCallBack(char*, char*); 

void setup() {
   //mqttClient.begin(“localhost”, 1833, OPEN, NULL, NULL, NULL);
   client.begin("155.41.121.14", 1883, OPEN, NULL, NULL, NULL);
   client.subscribe("test", myCallBack);
}

void myCallBack(char* topic, char* message) {
   // scan for matching topic, scan for matching command, do something useful
   //printf("%s: %s", topic, message);
	 ssize_t bytes = write(1, message, strlen(message));
	 if (bytes <= 0)
		 perror("myCallBack");
}

unsigned long publishTime = millis();

int main() {
	setup();
	while (1) client.loop();        // check for new message
  //if (millis() > publishTime) {
  //    publishTime = millis() + PUBLISH_INTERVAL;
  //    client.publish("edison/sensor1","sensor1value");
  //    client.publish("edison/sensor2","sensor2value");
  //} 
  //delay(SAMPLING_PERIOD);
  return 0;
}

