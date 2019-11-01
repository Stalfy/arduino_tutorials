#define BAUD_RATE 9600

#define ANALOG_IN_PIN  0
#define DIGITAL_IN_PIN 7

int analogIn = 0;
int digitalIn = 0;

void setup() {
    Serial.begin(BAUD_RATE);
    pinMode(DIGITAL_IN_PIN, INPUT);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    analogIn = analogRead(ANALOG_IN_PIN);
    digitalIn = digitalRead(DIGITAL_IN_PIN);

    Serial.print("Analog in = ");
    Serial.println(analogIn);

    digitalWrite(LED_BUILTIN, digitalIn);

    delay(100);
}
