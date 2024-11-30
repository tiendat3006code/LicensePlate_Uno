#include <Arduino.h>
#include "lcd_control.h"
#include "sensor_control.h"
#include "servo_control.h"

sensor_control* sensor = new sensor_control();
servo_control* servo = new servo_control();
lcd_control* lcd = new lcd_control();
bool isVehicleIn{false};
bool isVehicleOut{false};
long long lastTimeBarieIn{0};
long long lastTimeBarieOut{0};

// put function declarations here:
void setTimerIn(void (*callback)(), long interval, long long& startTime) {
   if ((millis() - startTime) >= interval) {
      callback();
   }
}

void setTimerOut(void (*callback)(), long interval, long long& startTime) {
   if ((millis() - startTime) >= interval) {
      callback();
   }
}

void closeBarieIn() {
   servo->closeBarieIn();
   lcd->defaultDisplay();
}

void closeBarieOut() {
   servo->closeBarieOut();
   lcd->defaultDisplay();
}

void setup() {
   // put your setup code here, to run once:
   Serial.begin(9600);
   sensor->sensorInit();
   servo->servoInit();
   lcd->lcdInit();
}

void loop() {
   // put your main code here, to run repeatedly:
   if (sensor->isDetectVehicleIn() && !servo->getBarieInState()) {
      Serial.print("00");
      isVehicleIn = true;
   } else {
      isVehicleIn = false;
   }
   if (sensor->isDetectVehicleOut() && !servo->getBarieOutState()) {
      Serial.print("11");
      isVehicleOut = true;
   } else {
      isVehicleOut = false;
   }
   if (Serial.available() > 0) {
      String dataReceived = Serial.readString();
      if (dataReceived == "Invalid") {
         lcd->displayInvalidPlate();
         delay(500);
         lcd->defaultDisplay();
      } else if (dataReceived == "IN_OPEN") {
         servo->openBarieIn();
         lastTimeBarieIn = millis();
      } else if (dataReceived == "OUT_OPEN") {
         servo->openBarieOut();
         lastTimeBarieOut = millis();
      } else {
         String state = dataReceived.substring(13, 15);
         if (state == "00" && sensor->isDetectVehicleIn()) {
            lcd->displayPlateAndHello(dataReceived.substring(0, 13), false);
            servo->openBarieIn();
            lastTimeBarieIn = millis();
         } else if (state == "11" && sensor->isDetectVehicleOut()) {
            lcd->displayPlateAndHello(dataReceived.substring(0, 13), true);
            servo->openBarieOut();
            lastTimeBarieOut = millis();
         }
      }
   }
   if (servo->getBarieInState()) {
      setTimerIn(closeBarieIn, 5000, lastTimeBarieIn);
   }
   if (servo->getBarieOutState()) {
      setTimerOut(closeBarieOut, 5000, lastTimeBarieOut);
   }
   delay(100);
}

// put function definitions here:
