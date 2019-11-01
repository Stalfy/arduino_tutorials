#include <Wire.h>
#include "DS3231.h"

#define BAUD_RATE 9600

DS3231 clock;
RTCDateTime dt;

char buf[25];

void setup() {
    Serial.begin(BAUD_RATE);
    clock.begin();
    clock.setDateTime(__DATE__, __TIME__);
}

void loop() {
    dt = clock.getDateTime();

    sprintf(buf, "%4d-%02d-%02d %02d:%02d:%02d",
            dt.year, dt.month, dt.day, dt.hour, dt.minute, dt.second);

    Serial.println(buf); 

    delay(1000);
}
