#define ENABLE_PIN 5
#define DIR_A_PIN  4
#define DIR_B_PIN  3

#define BAUD_RATE 9600

typedef void (*changeSpeed)();
void stop();
void forwardHalfSpeed();
void forwardFullSpeed();

const changeSpeed SPEEDS[3] = {
    stop,
    forwardHalfSpeed,
    forwardFullSpeed
};

void setup() {
    pinMode(ENABLE_PIN, OUTPUT);
    pinMode(DIR_A_PIN, OUTPUT);
    pinMode(DIR_B_PIN, OUTPUT);

    Serial.begin(BAUD_RATE);

    String str = "Select a speed: ";
    str.concat("\n0 = Stop.");
    str.concat("\n1 = Forward (half speed).");
    str.concat("\n2 = Forward (full speed).");

    Serial.println(str);
}

void loop() {
}

void serialEvent() {
    while(Serial.available() > 0) {
        uint8_t c = Serial.read() - '0';
        if(0 <= c && c < 3) {
            SPEEDS[c]();
        }
    }
}

void stop() {
    Serial.println("Stop the motor.");
    digitalWrite(DIR_A_PIN, LOW);
    digitalWrite(DIR_B_PIN, LOW);
    digitalWrite(ENABLE_PIN, LOW);
}

void forwardHalfSpeed() {
    Serial.println("Half speed forward.");
    digitalWrite(ENABLE_PIN, HIGH);
    digitalWrite(DIR_A_PIN, HIGH);
    digitalWrite(DIR_B_PIN, LOW);
    analogWrite(ENABLE_PIN, 128);
}

void forwardFullSpeed() {
    Serial.println("Full speed forward.");
    digitalWrite(ENABLE_PIN, HIGH);
    digitalWrite(DIR_A_PIN, HIGH);
    digitalWrite(DIR_B_PIN, LOW);
    analogWrite(ENABLE_PIN, 255);
}
