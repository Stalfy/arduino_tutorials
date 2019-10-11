#define LED_PIN 5
#define ON_BTN_PIN 2
#define OFF_BTN_PIN 3

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(ON_BTN_PIN, INPUT_PULLUP);
    pinMode(OFF_BTN_PIN, INPUT_PULLUP);

    attachInterrupt(digitalPinToInterrupt(ON_BTN_PIN), turnLedOn, FALLING);
    attachInterrupt(digitalPinToInterrupt(OFF_BTN_PIN), turnLedOff, FALLING);
}

void loop() {}

void turnLedOn() {
    digitalWrite(LED_PIN, HIGH);
}

void turnLedOff() {
    digitalWrite(LED_PIN, LOW);
}
