#include "LedControl.h"

#define DIN_PIN 12
#define CS_PIN  11
#define CLK_PIN 10
#define ATTACHED_DEVICES 1

#define DEVICE_ID 0

#define NORMAL_OP false

LedControl lc = LedControl(DIN_PIN, CLK_PIN, CS_PIN, ATTACHED_DEVICES);

void setup() {
    lc.shutdown(DEVICE_ID, NORMAL_OP);
    lc.setIntensity(DEVICE_ID, 5);
    lc.clearDisplay(DEVICE_ID);
}

void loop() {
    animatePinwheel();
}

void animatePinwheel() {
    byte states = 5;
    byte rows = 8;
    byte ledRows[states][rows] = {
        { 0b10000001, 0b01000010, 0b00100100, 0b00011000,
          0b00011000, 0b00100100, 0b01000010, 0b10000001 },
        { 0b01000000, 0b00100001, 0b00100110, 0b00011000,
          0b00011000, 0b01100100, 0b10000100, 0b00000010 },
        { 0b00010000, 0b00010000, 0b00010000, 0b00011111,
          0b11111000, 0b00001000, 0b00001000, 0b00001000 },
        { 0b00001000, 0b00001000, 0b00001000, 0b11111000,
          0b00011111, 0b00010000, 0b00010000, 0b00010000 },
        { 0b00000010, 0b10000100, 0b01100100, 0b00011000,
          0b00011000, 0b00100110, 0b00100001, 0b01000000 }
    };

    for(int state = 0; state < states; state++) {
        for(int row = 0; row < rows; row++) {
            lc.setRow(DEVICE_ID, row, ledRows[state][row]);
        }

        delay(40);
    }
}
