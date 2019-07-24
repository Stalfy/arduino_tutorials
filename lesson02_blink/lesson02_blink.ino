#define TIMEOUT 1000

void blink(int timeout);

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    blink(TIMEOUT);
}

void blink(int timeout) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(timeout);
    digitalWrite(LED_BUILTIN, LOW);
    delay(timeout);
}
