#include "dht_nonblocking.h"

// Communications
#define BAUD_RATE 9600

// Timer
// R3 Clock Speed is documented to be 16 MHz
#define CLOCK_SPEED 16000000
#define PRESCALER 1024
// The interrupt should be approximately once every 4 second.
#define INTERRUPT_FREQUENCY 0.25
#define COMP_MATCH_REGISTER ((CLOCK_SPEED / (PRESCALER * INTERRUPT_FREQUENCY)) - 1)

// Sensor
#define DHT_SENSOR_TYPE DHT_TYPE_11
#define DHT_SENSOR_PIN 2

DHT_nonblocking dht_sensor = DHT_nonblocking(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

// Interupts
ISR(TIMER1_COMPA_vect) {
    float temperature;
    float humidity;

    if(true == dht_sensor.measure(&temperature, &humidity)) {
        String output = "Temperature = ";
        output.concat(round(temperature));
        output.concat(" deg. C, Humidity = ");
        output.concat(round(humidity));
        output.concat("%");
        Serial.println(output);
    } else {
        Serial.println("Measurement unavailable.");
    }
}

void setup() {
    Serial.begin(BAUD_RATE);
    setupTimerInterrupts();
}

void loop() {}

void setupTimerInterrupts() {
    // Disable interrupts.
    cli();

    // Prepare timer1 for interrupts.
    TCCR1A = 0;
    TCCR1B = 0;
    TCNT1 = 0;

    // Set compare match for timer 1.
    OCR1A = COMP_MATCH_REGISTER;

    // Turn on CTC mode.
    TCCR1B |= (1 << WGM12);

    // Set CS12 bits for a 1024 prescaler.
    TCCR1B |= (1 << CS12) | (1 << CS10);

    // Enable timer 1 compare interrupt.
    TIMSK1 |= (1 << OCIE1A);

    // Enable interrupts.
    sei();
}
