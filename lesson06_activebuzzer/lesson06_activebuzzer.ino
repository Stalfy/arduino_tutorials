#define BUZZER_PIN 12

void setup() {
    pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
    byte i;

    while(true) {
        for(i = 0; i < 200; i++) {
            digitalWrite(BUZZER_PIN, HIGH);
            delay(1);

            digitalWrite(BUZZER_PIN, LOW);
            delay(1);
        }

        for(i = 0; i < 100; i++) {
            digitalWrite(BUZZER_PIN, HIGH);
            delay(2);

            digitalWrite(BUZZER_PIN, LOW);
            delay(2);
        }
    }
}
