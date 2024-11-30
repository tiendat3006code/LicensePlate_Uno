#include "servo_control.h"

servo_control::servo_control(int delayTimeSecond)
    : m_barieIn{10},
      m_barieOut{9},
      m_delayTimeSecond{delayTimeSecond},
      m_isBarieInOpened{false},
      m_isBarieOutOpened{false} {}

void servo_control::servoInit() {
   m_servoIn.attach(m_barieIn);
   m_servoIn.write(0);
   m_servoOut.attach(m_barieOut);
   m_servoOut.write(0);
}

void servo_control::openBarieIn() {
   m_servoIn.write(30);
   delay(100);
   m_servoIn.write(60);
   delay(100);
   m_servoIn.write(90);
   m_isBarieInOpened = true;
}

void servo_control::openBarieOut() {
   m_servoOut.write(30);
   delay(100);
   m_servoOut.write(60);
   delay(100);
   m_servoOut.write(90);
   m_isBarieOutOpened = true;
}

void servo_control::closeBarieIn() {
   m_servoIn.write(60);
   delay(100);
   m_servoIn.write(30);
   delay(100);
   m_servoIn.write(0);
   m_isBarieInOpened = false;
}

void servo_control::closeBarieOut() {
   m_servoOut.write(60);
   delay(100);
   m_servoOut.write(30);
   delay(100);
   m_servoOut.write(0);
   m_isBarieOutOpened = false;
}

bool servo_control::getBarieInState() {
   return m_isBarieInOpened;
}

bool servo_control::getBarieOutState() {
   return m_isBarieOutOpened;
}
