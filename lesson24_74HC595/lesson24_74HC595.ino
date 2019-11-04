#define DELAY 2000

#define CLOCK_PIN 9
#define LATCH_PIN 11
#define DATA_PIN  12

void setup() {
    pinMode(LATCH_PIN, OUTPUT);
    pinMode(DATA_PIN, OUTPUT);
    pinMode(CLOCK_PIN, OUTPUT);
    updateShiftRegister(0);
}

void loop() {
    byte leds = random(0, 256);
    updateShiftRegister(leds);
}

void updateShiftRegister(byte leds) {
    digitalWrite(LATCH_PIN, LOW);
    shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, leds);
    digitalWrite(LATCH_PIN, HIGH);
    delay(DELAY);
}
