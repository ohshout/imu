// File: MQTTClient.h
/*
  Minimalist MQTT Client using mosquitto_sub and mosquitto_pub
  Assume Mosquitto MQTT server already installed and mosquitto_pub/sub 
  are in search path
*/

#ifndef __MQTTClient_H__
#define __MQTTClient_H__

#include <Arduino.h>
#include <stdio.h>

enum security_mode {OPEN = 0, SSL = 1, PSK = 2};

class MQTTClient {

  public:
    MQTTClient();
    ~MQTTClient();
    void    begin(char * broker, int port, security_mode mode, 
                  char* certificate_file, char *psk_identity, char *psk);
    boolean publish(char *topic, char *message);
    boolean subscribe(char* topic, void (*callback)(char *topic, char* message));
    boolean loop();
    boolean available();
    void    close();

  private:
    void           parseDataBuffer();
    FILE*          spipe;
    char           mqtt_broker[32];
    security_mode  mode;
    char           topicString[64];
    char           certificate_file[64];
    char           psk_identity[32];
    char           psk_password[32];
    int            serverPort;
    char           *topic;
    char           *message;
    boolean         retain_flag;
    void           (*callback_function)(char* topic, char* message);
    char           dataBuffer[256];
};
#endif
