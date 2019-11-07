#define IC_ENABLE_12_PIN 5
#define IC_ENABLE_34_PIN 3
#define IC_IN_1_PIN      6
#define IC_IN_4_PIN      4

#define BAUD_RATE 9600

typedef void (*changeSpeed)();
void stop();
void forwardHalfSpeed();
void forwardFullSpeed();
void reverseHalfSpeed();
void reverseFullSpeed();

const changeSpeed SPEEDS[5] = {
    stop,
    forwardHalfSpeed,
    forwardFullSpeed,
    reverseHalfSpeed,
    reverseFullSpeed
};

void setup() {
    pinMode(IC_ENABLE_12_PIN, OUTPUT);
    pinMode(IC_ENABLE_34_PIN, OUTPUT);
    pinMode(IC_IN_1_PIN, OUTPUT);
    pinMode(IC_IN_4_PIN, OUTPUT);

    Serial.begin(BAUD_RATE);
    stop();

    String str = "Select a speed: ";
    str.concat("\n0 = Stop.");
    str.concat("\n1 = Forward (half speed).");
    str.concat("\n2 = Forward (full speed).");
    str.concat("\n3 = Reverse (half speed).");
    str.concat("\n4 = Reverse (full speed).");

    Serial.println(str);
}

void loop() {
}

void serialEvent() {
    while(Serial.available() > 0) {
        uint8_t c = Serial.read() - '0';
        if(0 <= c && c < 5) {
            SPEEDS[c]();
        }
    }
}

void stop() {
    Serial.println("Stop the motor.");
    digitalWrite(IC_ENABLE_12_PIN, LOW);
    digitalWrite(IC_ENABLE_34_PIN, LOW);
}

void forwardHalfSpeed() {
    Serial.println("Half speed forward.");
    digitalWrite(IC_IN_1_PIN, HIGH);
    digitalWrite(IC_IN_4_PIN, LOW);
    analogWrite(IC_ENABLE_12_PIN, 128);
    digitalWrite(IC_ENABLE_34_PIN, HIGH);
}

void forwardFullSpeed() {
    Serial.println("Full speed forward.");
    digitalWrite(IC_IN_1_PIN, HIGH);
    digitalWrite(IC_IN_4_PIN, LOW);
    digitalWrite(IC_ENABLE_12_PIN, HIGH);
    digitalWrite(IC_ENABLE_34_PIN, HIGH);
}

void reverseHalfSpeed() {
    Serial.println("Half speed reverse.");
    digitalWrite(IC_IN_1_PIN, LOW);
    digitalWrite(IC_IN_4_PIN, HIGH);
    digitalWrite(IC_ENABLE_12_PIN, HIGH);
    analogWrite(IC_ENABLE_34_PIN, 128);
}

void reverseFullSpeed() {
    Serial.println("Full speed reverse.");
    digitalWrite(IC_IN_1_PIN, LOW);
    digitalWrite(IC_IN_4_PIN, HIGH);
    digitalWrite(IC_ENABLE_12_PIN, HIGH);
    digitalWrite(IC_ENABLE_34_PIN, HIGH);
}
