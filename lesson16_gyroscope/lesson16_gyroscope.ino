#include "Wire.h"

#define MPU_ADDR         0x68 // I2C address of the MPU-6050.
#define MPU_PWR_MGMT_REG 0x6B
#define MPU_WAKE         0x00

#define ACCL_REG 0x3B
#define TEMP_REG 0x41      
#define GYRO_REG 0x43

#define BAUD_RATE 9600 
#define READ_INTERVAL 1000

void setup() {
    Wire.begin();
    Wire.beginTransmission(MPU_ADDR);
    Wire.write(MPU_PWR_MGMT_REG);
    Wire.write(MPU_WAKE);
    Wire.endTransmission(true);

    Serial.begin(BAUD_RATE);
}

void loop() {
    Serial.println("\n>>>>>>>>>>>>");
    Serial.println(threeDimRead(ACCL_REG,    "Accel registers: "));
    Serial.println(threeDimRead(GYRO_REG,    "Gyro registers:  "));    
    Serial.println(readTemperature(TEMP_REG, "MPU Temperature: "));
    Serial.println("<<<<<<<<<<<<\n");

    delay(READ_INTERVAL);
}

String threeDimRead(int8_t reg, String str) { 
    int16_t x, y, z;

    Wire.beginTransmission(MPU_ADDR);
    Wire.write(reg);
    Wire.endTransmission(true);

    // Request 6 registers from the starting address.
    Wire.requestFrom(MPU_ADDR, 6, true);
    x = Wire.read() << 8 | Wire.read();
    y = Wire.read() << 8 | Wire.read();
    z = Wire.read() << 8 | Wire.read();

    str.concat("X = ");
    str.concat(x);
    str.concat(" | Y = ");
    str.concat(y);
    str.concat(" | Z = ");
    str.concat(z);

    return str;
}

String readTemperature(int8_t reg, String str) {
    int16_t temp;

    Wire.beginTransmission(MPU_ADDR);
    Wire.write(TEMP_REG);
    Wire.endTransmission(true);

    // Request the 6 acceleration registers.
    Wire.requestFrom(MPU_ADDR, 6, true);
    temp = Wire.read() << 8 | Wire.read();

    // Conversion to celsius from datasheet.
    temp = temp / 340.00 + 36.53;

    str.concat(temp);
    str.concat(" Celsius");
    return str;
}
