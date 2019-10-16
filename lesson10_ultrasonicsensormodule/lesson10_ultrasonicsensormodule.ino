#include <stdio.h>
#include "SR04.h"

#define ECHO_PIN 11
#define TRIG_PIN 12

#define SERIAL_BAUD_RATE 9600

SR04 sensor = SR04(ECHO_PIN, TRIG_PIN);
long distance;

String formattedDistance;

void setup() {
    Serial.begin(SERIAL_BAUD_RATE);
    delay(1000);
}

void loop() {
    formattedDistance = "";

    distance = sensor.Distance();
    formattedDistance.concat(distance);    
    formattedDistance.concat(" cm.");    
    Serial.println(formattedDistance);

    delay(1000);
}
