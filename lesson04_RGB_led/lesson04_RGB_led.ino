#define R_PWM_PIN 3
#define G_PWM_PIN 5
#define B_PWM_PIN 6

#define TIMEOUT 15
#define MASK 0x8000

#define R_IDX 0
#define G_IDX 1
#define B_IDX 2

const short WHITE[3] = { 200, 200, 200 };
const short BLACK[3] = { 0, 0, 0 };
const short RED[3]   = { 200, 0, 0 };
const short GREEN[3] = { 0, 200, 0 };
const short BLUE[3]  = { 0, 0, 200 };

short currentColor[3] = { 0, 0, 0 };

void colorChange(short * color);
void colorChangeProgressive(short * targetColor);

void setup() {
    pinMode(R_PWM_PIN, OUTPUT);
    pinMode(G_PWM_PIN, OUTPUT);
    pinMode(B_PWM_PIN, OUTPUT);

    digitalWrite(R_PWM_PIN, LOW);
    digitalWrite(G_PWM_PIN, LOW);
    digitalWrite(B_PWM_PIN, LOW);

    colorChange(WHITE);
}

void loop() {
    short r = random(0, 201);
    short g = random(0, 201 - r);
    short b = random(0, 201 - r - g);

    colorChangeProgressive(r, g, b);
}

void colorChange(short * color) {
    analogWrite(R_PWM_PIN, color[R_IDX]);
    analogWrite(G_PWM_PIN, color[G_IDX]);
    analogWrite(B_PWM_PIN, color[B_IDX]);

    currentColor[R_IDX] = color[R_IDX];
    currentColor[G_IDX] = color[G_IDX];
    currentColor[B_IDX] = color[B_IDX];
}

void colorChangeProgressive(byte r, byte g, byte b) {
    short rOffset = r - currentColor[R_IDX];
    short gOffset = g - currentColor[G_IDX];
    short bOffset = b - currentColor[B_IDX];

    short isNegative;
    while (0 != rOffset || 0 != gOffset || 0 != bOffset) {
        isNegative = (rOffset & MASK) >> 15;
        currentColor[R_IDX] += pow(-1, isNegative) * (ceil(abs(rOffset) / 200.0));

        isNegative = (gOffset & MASK) >> 15;
        currentColor[G_IDX] += pow(-1, isNegative) * (ceil(abs(gOffset) / 200.0));

        isNegative = (bOffset & MASK) >> 15;
        currentColor[B_IDX] += pow(-1, isNegative) * (ceil(abs(bOffset) / 200.0));

        analogWrite(R_PWM_PIN, currentColor[R_IDX]);
        analogWrite(G_PWM_PIN, currentColor[G_IDX]);
        analogWrite(B_PWM_PIN, currentColor[B_IDX]);

        rOffset = r - currentColor[R_IDX];
        gOffset = g - currentColor[G_IDX];
        bOffset = b - currentColor[B_IDX];

        delay(TIMEOUT);
    }
}
