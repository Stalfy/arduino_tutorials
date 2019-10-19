#include <Keypad.h>

#define BAUD_RATE 9600
#define ROWS 4
#define COLS 4

const char HEXA_KEYS[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

const byte ROW_PINS[ROWS] = {9, 8, 7, 6};
const byte COL_PINS[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(HEXA_KEYS), ROW_PINS, COL_PINS, ROWS, COLS);

void setup() {
    Serial.begin(BAUD_RATE);
}

void loop() {
    char key = keypad.getKey();

    if (key) {
        Serial.println(key);
    }
}
