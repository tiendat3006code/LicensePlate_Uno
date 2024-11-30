#ifndef LCD_CONTROL_H
#define LCD_CONTROL_H

#include "rgb_lcd.h"

class lcd_control {
  public:
   lcd_control(/* args */);
   ~lcd_control() = default;

   void lcdInit();
   void defaultDisplay();
   void displayPlateAndHello(const String& plate, bool state);
   void displayInvalidPlate();

  private:
   rgb_lcd lcd;
};

#endif  // LCD_CONTROL_H