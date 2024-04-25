#ifndef PH_SENSOR_H
#define PH_SENSOR_H

#include "Arduino.h"

class PH_Sensor {
  public:
    PH_Sensor(int pin);
    void comenzar();
    void medir();
    float obtenerVoltaje();
    float obtenerPH();
  private:
    int _pin;
    int _buf[10];
    int _temp;
    unsigned long int _val;
};

#endif
