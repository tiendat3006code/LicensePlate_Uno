#include "sensor_control.h"

sensor_control::sensor_control(/* args */)
    : detectVehicleIn{2}, detectVehicleOut{3} {}

void sensor_control::sensorInit() {
   pinMode(detectVehicleIn, INPUT_PULLUP);
   pinMode(detectVehicleOut, INPUT_PULLUP);
}

bool sensor_control::isDetectVehicleIn() {
   return digitalRead(detectVehicleIn) == LOW;
}

bool sensor_control::isDetectVehicleOut() {
   return digitalRead(detectVehicleOut) == LOW;
}