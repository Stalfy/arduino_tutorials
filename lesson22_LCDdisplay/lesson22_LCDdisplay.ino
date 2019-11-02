#include "LiquidCrystal.h"

#define LCD_RS_PIN 7
#define LCD_EN_PIN 8
#define LCD_D4_PIN 9
#define LCD_D5_PIN 10
#define LCD_D6_PIN 11
#define LCD_D7_PIN 12

#define LCD_COLS 16
#define LCD_ROWS 2

LiquidCrystal lcd(LCD_RS_PIN, LCD_EN_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);

void setup() {
    lcd.begin(LCD_COLS, LCD_ROWS);
    lcd.setCursor(0, 0);
    lcd.print("Hello, World!");
}

void loop() {
    lcd.setCursor(0, 1);
    lcd.print(millis() / 1000);
}
