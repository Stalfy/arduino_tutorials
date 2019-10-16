#include "Servo.h"

#define SERVO_PIN 9
#define SERVO_DELAY 500

Servo servo;

void setup() {
    servo.attach(SERVO_PIN);
    servo.write(0);
}

void loop() {
    servo.write(0);
    delay(SERVO_DELAY);
    servo.write(180);
    delay(SERVO_DELAY);
}
