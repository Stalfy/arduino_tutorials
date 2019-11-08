#include "Stepper.h"

#define BAUD_RATE 9600

#define DELAY 500

#define STEPS_PER_REVOLUTION 2048
#define RPM 17

Stepper stepper(STEPS_PER_REVOLUTION, 8, 10, 9, 11);

void setup() {
    stepper.setSpeed(RPM);
    Serial.begin(BAUD_RATE);
}

void loop() {
    Serial.println("Clockwise");
    stepper.step(STEPS_PER_REVOLUTION);
    delay(DELAY);
    
    Serial.println("Counterclockwise");
    stepper.step(-1 * STEPS_PER_REVOLUTION);
    delay(DELAY);
}
