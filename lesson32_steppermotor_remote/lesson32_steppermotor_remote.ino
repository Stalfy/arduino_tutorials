#include "IRremote.h"
#include "RemoteKeys.h"
#include "Stepper.h"

#define BAUD_RATE 9600

#define STEPS_PER_REVOLUTION 2048
#define RPM 17

#define IR_RECEIVER_PIN 12

Stepper stepper(STEPS_PER_REVOLUTION, 8, 10, 9, 11);

IRrecv receiver(IR_RECEIVER_PIN);
decode_results results;

void setup() {
    stepper.setSpeed(RPM);
    receiver.enableIRIn();

    Serial.begin(BAUD_RATE);
}

void loop() {
    if(receiver.decode(&results)) {
        switch(results.value) {
            case BTN_VOL_UP:
                Serial.println("Clockwise");
                stepper.step(STEPS_PER_REVOLUTION);
                break;
            case BTN_VOL_DN:
                Serial.println("Counterclockwise");
                stepper.step(-1 * STEPS_PER_REVOLUTION);
                break;
        }

        receiver.resume();
    }
}
