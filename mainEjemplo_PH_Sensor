#include <ph_sensor.h>

const int PO = A0;
PH_Sensor phSensor(PO);

void setup() {
  phSensor.comenzar();
}

void loop() {
  phSensor.medir();
  float pHVol = phSensor.obtenerVoltaje();
  float pH = phSensor.obtenerPH();

  Serial.print("Voltaje mV = ");
  Serial.println(pHVol);
  Serial.print("Valor de pH = ");
  Serial.println(pH);
  delay(100);
}
