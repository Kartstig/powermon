#include "EmonLib.h"
EnergyMonitor emon1;

#define CALIBARTION_CURRENT 60
#define CURRENT_PIN 1
#define SAMPLES 1480

const float Voltage = 120.0;

void setup() {
  Serial.begin(9600);

  emon1.current(CURRENT_PIN, CALIBARTION_CURRENT);
}

void loop() {
  double Irms = emon1.calcIrms(SAMPLES);
  double wattage = Irms*Voltage;

  Serial.print("Amps: ");
  Serial.print(Irms);
  Serial.print("\t");
  Serial.print("Wattage: ");
  Serial.print(wattage);
  Serial.print("\n");
  delay(10);
}
