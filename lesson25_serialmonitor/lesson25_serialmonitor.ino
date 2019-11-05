#include "hashmap.h"

#define CLOCK_PIN 9
#define LATCH_PIN 11
#define DATA_PIN  12

#define BAUD_RATE 9600

class H : public KeyHash<uint8_t> {
    public:
        uint32_t operator() (uint8_t key) {
            return key;
        }
};

class C : public KeyComparator<uint8_t> {
    public:
        bool operator() (uint8_t keyA, uint8_t keyB) {
            return keyA == keyB;
        }
};

HashMap<uint8_t, uint8_t, H, C>* hmap = new HashMap<uint8_t, uint8_t, H, C>(9);
uint8_t v;

void setup() {
    Serial.begin(BAUD_RATE);

    pinMode(LATCH_PIN, OUTPUT);
    pinMode(DATA_PIN, OUTPUT);
    pinMode(CLOCK_PIN, OUTPUT);

    updateShiftRegister(0);

    hmap->put(0, 0b00000000);
    hmap->put(1, 0b00000001);
    hmap->put(2, 0b00000010);
    hmap->put(3, 0b00000100);
    hmap->put(4, 0b00001000);
    hmap->put(5, 0b00010000);
    hmap->put(6, 0b00100000);
    hmap->put(7, 0b01000000);
    hmap->put(8, 0b10000000);

    Serial.println("Enter the led ID you wish to light up. 0 to turn them all off.");
}

void loop() {}

void serialEvent() {
    while(Serial.available() > 0) {
        uint8_t c = Serial.read() - '0';

        if(hmap->get(c, &v)) {
            Serial.println(c, HEX);
            updateShiftRegister(v);
        }
    }
}

void updateShiftRegister(uint8_t leds) {
    digitalWrite(LATCH_PIN, LOW);
    shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, leds);
    digitalWrite(LATCH_PIN, HIGH);
}
