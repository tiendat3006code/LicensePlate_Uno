#ifndef SERVO_CONTROL_H
#define SERVO_CONTROL_H

#include <Arduino.h>
#include "Servo.h"

class servo_control {
  public:
   servo_control(int delayTimeSecond = 0);
   ~servo_control() = default;
   void servoInit();
   void openBarieIn();
   void openBarieOut();
   void closeBarieIn();
   void closeBarieOut();
   bool getBarieInState();
   bool getBarieOutState();

  private:
   Servo m_servoIn;
   Servo m_servoOut;
   const int m_barieIn;
   const int m_barieOut;
   const int m_delayTimeSecond;
   bool m_isBarieInOpened;
   bool m_isBarieOutOpened;
};

#endif  // SERVO_CONTROL_H