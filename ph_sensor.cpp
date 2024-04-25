#include "ph_sensor.h"

PH_Sensor::PH_Sensor(int pin) {
  _pin = pin;
}

void PH_Sensor::comenzar() {
  Serial.begin(9600);
}

void PH_Sensor::medir() {
  for (int i = 0; i < 10; i++) {
    _buf[i] = analogRead(_pin);
    delay(10);
  }

  for (int i = 0; i < 9; i++) {
    for (int j = i + 1; j < 10; j++) {
      if (_buf[i] > _buf[j]) {
        _temp = _buf[i];
        _buf[i] = _buf[j];
        _buf[j] = _temp;
      }
    }
  }

  _val = 0;
  for (int i = 2; i < 8; i++) {
    _val += _buf[i];
  }
}

float PH_Sensor::obtenerVoltaje() {
  float PHVol = (float)_val * 100 * 5 / 1024 / 6;
  return PHVol;
}

float PH_Sensor::obtenerPH() {
  // Ajustar según la calibración específica
  float pH = 7 - (obtenerVoltaje() - 1.75) / 0.18;
  return pH;
}
