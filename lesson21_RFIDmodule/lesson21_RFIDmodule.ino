#include <SPI.h>
#include "MFRC522.h"

#define RESET_PIN    9
#define SPI_SDA_PIN  10
#define SPI_MOSI_PIN 11
#define SPI_MISO_PIN 12
#define SPI_SCK_PIN  13

#define BAUD_RATE 9600

MFRC522 mfrc(SPI_SDA_PIN, RESET_PIN);
MFRC522::MIFARE_Key key;

void setup() {
    Serial.begin(BAUD_RATE);
    SPI.begin();
    mfrc.PCD_Init();
}

void loop() {
    // Actively wait for a card.
    if(!mfrc.PICC_IsNewCardPresent() || !mfrc.PICC_ReadCardSerial()) {
        return;
    }

    Serial.println("Card detected.");
    printCardUID(mfrc.uid);
    Serial.println();

    mfrc.PICC_HaltA();
}

void printCardUID(MFRC522::Uid uid) {
    String cardUID = "Card UID: ";
    
    for(byte i = 0; i < uid.size; i++) {
        cardUID.concat(String(uid.uidByte[i], HEX));
    }

    Serial.println(cardUID);
}
