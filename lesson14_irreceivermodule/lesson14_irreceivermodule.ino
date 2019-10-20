#include "IRremote.h"
#include "RemoteKeys.h"

#define BAUD_RATE 9600
#define RECEIVER_PIN 11

IRrecv receiver(RECEIVER_PIN);
decode_results results;

void setup() {
    Serial.begin(BAUD_RATE);
    receiver.enableIRIn();
}

void loop() {
    if(receiver.decode(&results)) {
        unsigned long signal = results.value;
        logSignal(signal);
        receiver.resume();
    }

}

void logSignal(unsigned long value) {
    switch(value) {
        case BTN_POWER:         Serial.println("POWER");        break;
        case BTN_FUNC_STOP:     Serial.println("FUNC/STOP");    break;
        case BTN_VOL_UP:        Serial.println("VOL+");         break;
        case BTN_REWIND:        Serial.println("FAST BACK");    break;
        case BTN_PAUSE:         Serial.println("PAUSE");        break;
        case BTN_FAST_FORWARD:  Serial.println("FAST FORWARD"); break;
        case BTN_DN:            Serial.println("DOWN");         break;
        case BTN_VOL_DN:        Serial.println("VOL-");         break;
        case BTN_UP:            Serial.println("UP");           break;
        case BTN_EQ:            Serial.println("EQ");           break;
        case BTN_ST_REPT:       Serial.println("ST/REPT");      break;
        case BTN_0:             Serial.println("0");            break;
        case BTN_1:             Serial.println("1");            break;
        case BTN_2:             Serial.println("2");            break;
        case BTN_3:             Serial.println("3");            break;
        case BTN_4:             Serial.println("4");            break;
        case BTN_5:             Serial.println("5");            break;
        case BTN_6:             Serial.println("6");            break;
        case BTN_7:             Serial.println("7");            break;
        case BTN_8:             Serial.println("8");            break;
        case BTN_9:             Serial.println("9");            break;
        case REPEAT:            Serial.println("REPEAT");       break;  

        default: Serial.println("Unknown signal.");
    }

    // Prevent immediate repeats.
    delay(500);
}
