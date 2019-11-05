#define CLOCK_PIN 9
#define LATCH_PIN 11
#define DATA_PIN  12

#define LIGHT_PIN 0

void setup() {
    pinMode(LATCH_PIN, OUTPUT);
    pinMode(DATA_PIN, OUTPUT);
    pinMode(CLOCK_PIN, OUTPUT);
    updateShiftRegister(0);
}

void loop() {
    uint16_t light = analogRead(LIGHT_PIN);
    uint8_t leds = getLeds(light);
    updateShiftRegister(leds);
}

uint8_t getLeds(uint16_t reading) {
    uint8_t ledsToLight = reading / 113.0;  
    
    uint8_t leds = 0;
    if(0 < ledsToLight) {
        leds = 1 << (ledsToLight - 1);
        leds = leds | (leds - 1);
    }

    return leds;
}

void updateShiftRegister(uint8_t leds) {
    digitalWrite(LATCH_PIN, LOW);
    shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, leds);
    digitalWrite(LATCH_PIN, HIGH);
}
