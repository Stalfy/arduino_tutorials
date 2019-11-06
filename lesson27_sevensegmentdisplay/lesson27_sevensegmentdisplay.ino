#define DELAY 1000

#define CLOCK_PIN 9
#define LATCH_PIN 11
#define DATA_PIN  12

const uint8_t DIGITS[10] = {
    0b11111100, // 0
    0b01100000, // 1
    0b11011010, // 2
    0b11110010, // 3
    0b01100110, // 4
    0b10110110, // 5
    0b10111110, // 6
    0b11100000, // 7
    0b11111110, // 8
    0b11100110  // 9
};

void setup() {
    pinMode(LATCH_PIN, OUTPUT);
    pinMode(DATA_PIN, OUTPUT);
    pinMode(CLOCK_PIN, OUTPUT);
    blinkSevenSegDisplay();
}

void loop() {
    for(uint8_t i = 0; i < 10; i++) {
        updateSevenSegDisplay(DIGITS[i]);
    } 
}

void blinkSevenSegDisplay() {
    updateSevenSegDisplay(0b11111111);
    updateSevenSegDisplay(0b00000000);
}

void updateSevenSegDisplay(uint8_t leds) {
    digitalWrite(LATCH_PIN, LOW);
    shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, leds);
    digitalWrite(LATCH_PIN, HIGH);
    delay(DELAY);
}
