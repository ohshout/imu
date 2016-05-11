mqtt: mqttclient.cpp mqtttest.cpp Arduino.cpp
	gcc -g -I. -o mqtttest $^

imu: example.c SFE_LSM9DS0.c
	gcc -o imutest $^ -lmraa
	
clean:
	rm -rf mqtttest imutest

.PHONY: mqtt clean imu
