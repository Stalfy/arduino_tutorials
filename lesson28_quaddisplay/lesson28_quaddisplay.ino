#define DELAY 1000

#define CLOCK_PIN 9
#define LATCH_PIN 11
#define DATA_PIN  12

const uint8_t DIGITS[10] = {
    0x3F,
    0x06,
    0x5B,
    0x4F,
    0x66,
    0x6D,
    0x7D,
    0x07,
    0x7F,
    0x6F
};

void setup() {
    pinMode(LATCH_PIN, OUTPUT);
    pinMode(DATA_PIN, OUTPUT);
    pinMode(CLOCK_PIN, OUTPUT);
    clearDisplay();
}

void loop() {
    for(uint8_t i = 0; i < 10; i++) {
        updateDisplay(DIGITS[i]);
    }
}

void clearDisplay() {
    updateDisplay(0x00);
}

void updateDisplay(uint8_t segments) {
    digitalWrite(LATCH_PIN, LOW);
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, segments);
    digitalWrite(LATCH_PIN, HIGH);
    delay(DELAY);
}
