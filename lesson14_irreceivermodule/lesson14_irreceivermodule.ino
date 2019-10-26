#include "IRremote.h"
#include "RemoteKeys.h"
#include "hashmap.h"

#define BAUD_RATE 9600
#define RECEIVER_PIN 11

IRrecv receiver(RECEIVER_PIN);
decode_results results;

/**
 * Hash map elements.
 */
class H : public KeyHash<uint32_t> {
    public:
        // https://github.com/skeeto/hash-prospector
        uint32_t operator() (uint32_t key) {
            key ^= key >> 17;
            key *= 0xed5ad4bb;
            key ^= key >> 11;
            key *= 0xac4c1b51;
            key ^= key >> 15;
            key *= 0x31848bab;
            key ^= key >> 14;
            return key;
        }
};

class C : public KeyComparator<uint32_t> {
    public:
        bool operator() (uint32_t keyA, uint32_t keyB) {
            return keyA == keyB;
        }
};

HashMap<uint32_t, String, H, C>* hmap = new HashMap<uint32_t, String, H, C>(31);

/**
 * Methods.
 */ 
void setup() {
    Serial.begin(BAUD_RATE);
    receiver.enableIRIn();

    hmap->put(BTN_POWER, "POWER");
    hmap->put(BTN_FUNC_STOP, "FUNC/STOP");
    hmap->put(BTN_VOL_UP, "VOL+");
    hmap->put(BTN_REWIND, "FAST BACK");
    hmap->put(BTN_PAUSE, "PAUSE");
    hmap->put(BTN_FAST_FORWARD, "FAST FORWARD");
    hmap->put(BTN_DN, "DOWN");
    hmap->put(BTN_VOL_DN, "VOL-");
    hmap->put(BTN_UP, "UP");
    hmap->put(BTN_EQ, "EQ");
    hmap->put(BTN_ST_REPT, "ST/REPT");
    hmap->put(BTN_0, "0");
    hmap->put(BTN_1, "1");
    hmap->put(BTN_2, "2");
    hmap->put(BTN_3, "3");
    hmap->put(BTN_4, "4");
    hmap->put(BTN_5, "5");
    hmap->put(BTN_6, "6");
    hmap->put(BTN_7, "7");
    hmap->put(BTN_8, "8");
    hmap->put(BTN_9, "9");
    hmap->put(REPEAT, "REPEAT"); 
}

void loop() {
    if(receiver.decode(&results)) {
        uint32_t signal = results.value;
        logSignal(signal);
        receiver.resume();
    }
}

void logSignal(uint32_t value) {
    String msg = "Unknown signal.";
    hmap->get(value, &msg);
    Serial.println(msg);

    // Prevent immediate repeats.
    delay(500);
}
