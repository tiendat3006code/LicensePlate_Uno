#ifndef SENSOR_CONTROL_H
#define SENSOR_CONTROL_H

#include <Arduino.h>

class sensor_control {
  public:
   sensor_control(/* args */);
   ~sensor_control() = default;
   void sensorInit();
   bool isDetectVehicleIn();
   bool isDetectVehicleOut();

  private:
   const int detectVehicleIn;
   const int detectVehicleOut;
};

#endif  // SENSOR_CONTROL_H