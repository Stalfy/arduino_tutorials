#define IC_ENABLE_PIN 5
#define IC_IN1_PIN    4
#define IC_IN2_PIN    3

#define DELAY 1000

void setup() {
    pinMode(IC_ENABLE_PIN, OUTPUT);
    pinMode(IC_IN1_PIN, OUTPUT);
    pinMode(IC_IN2_PIN, OUTPUT);
    digitalWrite(IC_ENABLE_PIN, HIGH);
}

void loop() {
    digitalWrite(IC_IN1_PIN, HIGH);
    digitalWrite(IC_IN2_PIN, LOW);
    delay(1000);
    digitalWrite(IC_IN1_PIN, LOW);
    digitalWrite(IC_IN2_PIN, HIGH);
    delay(1000);
}
