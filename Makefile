mqtt: mqttclient.cpp mqtttest.cpp Arduino.cpp
	gcc -g -I. -o mqtttest $^

imu: SparkFun_9DOF_Edison_Block_Example.cpp SFE_LSM9DS0.cpp
	g++ -std=c++11 -x c++ -o imutest $^ -lmraa
	
clean:
	rm -rf mqtttest imutest

.PHONY: mqtt clean imu
