#define SWITCH_PIN 2
#define LED_PIN 8

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(SWITCH_PIN, INPUT);
}

void loop() {
    int inputValue = digitalRead(SWITCH_PIN);
    digitalWrite(LED_PIN, inputValue);
}
