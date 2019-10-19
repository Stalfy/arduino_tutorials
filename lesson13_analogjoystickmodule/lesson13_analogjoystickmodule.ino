#define BAUD_RATE 9600

#define JOYSTICK_X_PIN  0
#define JOYSTICK_Y_PIN  1
#define JOYSTICK_SW_PIN 2

void setup() {
    pinMode(JOYSTICK_SW_PIN, INPUT);
    digitalWrite(JOYSTICK_SW_PIN, HIGH);
    Serial.begin(BAUD_RATE);
}

void loop() {
    String info = "";

    info.concat("Switch: ");
    info.concat(digitalRead(JOYSTICK_SW_PIN));
    info.concat("\nX-axis: ");
    info.concat(analogRead(JOYSTICK_X_PIN));
    info.concat("\nY-axis: ");
    info.concat(analogRead(JOYSTICK_Y_PIN));
    info.concat("\n=====\n");

    Serial.println(info);
    delay(1000);
}
