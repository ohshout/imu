#!/bin/bash

while [ true ]
do
	read MSG
	mosquitto_pub -t test -m "$MSG"
	echo "$MSG"
done
