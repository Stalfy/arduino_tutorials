#include "LiquidCrystal.h"

#define LCD_RS_PIN 7
#define LCD_EN_PIN 8
#define LCD_D4_PIN 9
#define LCD_D5_PIN 10
#define LCD_D6_PIN 11
#define LCD_D7_PIN 12

#define LCD_COLS 16
#define LCD_ROWS 2

#define TEMP_PIN 0

LiquidCrystal lcd(LCD_RS_PIN, LCD_EN_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);

String tempK;
String tempC;
String tempF;

void setup() {
    lcd.begin(LCD_COLS, LCD_ROWS);
    lcd.clear();
}

void loop() {
    int tempRead = analogRead(TEMP_PIN);
    double degK = log(10000.0 * ((1024.0 / tempRead - 1)));
    degK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * degK * degK)) * degK);

    double degC = degK - 273.15;
    double degF = (degC * 9.0) / 5.0 + 32.0;

    tempK = "K= " + String(degK, 1);
    tempC = "C= " + String(degC, 1);
    tempF = "F= " + String(degF, 1);

    lcd.setCursor(0, 0);
    lcd.print(tempK);
    
    lcd.setCursor(0, 1);
    lcd.print(tempC);
    
    lcd.setCursor(8, 1);
    lcd.print(tempF);

    delay(500);
}
