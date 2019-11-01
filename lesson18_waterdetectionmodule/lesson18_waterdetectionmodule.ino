#define BAUD_RATE 9600

#define WATER_LEVEL_PIN 0
#define TOLERANCE 10

int previous = 0;
int current = 0;

char buf[35];

void setup() {
    Serial.begin(BAUD_RATE);
}

void loop() {
    current = analogRead(WATER_LEVEL_PIN);
    if(TOLERANCE < abs(previous - current)) {
        sprintf(buf, "Water level changed from %d to %d.", previous, current);
        Serial.println(buf);
        previous = current;
    }
}
