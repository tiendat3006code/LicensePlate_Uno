#include "lcd_control.h"

lcd_control::lcd_control(/* args */) {}

void lcd_control::lcdInit() {
   lcd.begin(16, 2);
   lcd.clear();
   lcd.setCursor(2, 0);
   lcd.print("TRUONG THPT");
   lcd.setCursor(2, 1);
   lcd.print("TAN YEN SO 2");
}

void lcd_control::defaultDisplay() {
   lcd.clear();
   lcd.setCursor(2, 0);
   lcd.print("TRUONG THPT");
   lcd.setCursor(2, 1);
   lcd.print("TAN YEN SO 2");
}

void lcd_control::displayPlateAndHello(const String& plate, bool state) {
   lcd.clear();
   lcd.setCursor(3, 0);
   if (state) {
      lcd.print("GOOD BYE");
   } else {
      lcd.print("WELCOME");
   }
   lcd.setCursor(2, 1);
   lcd.print(plate.c_str());
}

void lcd_control::displayInvalidPlate() {
   lcd.clear();
   lcd.setCursor(4, 0);
   lcd.print("INVALID");
}