#define BAUD_RATE 9600

#define PIR_PIN 7

String msg;

void setup() {
    pinMode(PIR_PIN, INPUT);
    Serial.begin(BAUD_RATE);
}

void loop() {
    msg = "Motion is ";
    if(HIGH == digitalRead(PIR_PIN)) {
        msg.concat("detected.");
    } else {
        msg.concat("not detected");
    }

    Serial.println(msg);
}
