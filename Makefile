mqtt: mqttclient.cpp mqtttest.cpp Arduino.cpp
	gcc -g -I. -o mqtttest $^
	
clean:
	rm -rf mqtttest

.PHONY: mqtt clean
