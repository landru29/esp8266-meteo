#include "serial_display.h"

void serialDisplay(Pressure myPressure, Humidity myHumidity, Temperature myTemperature) {
  Serial.print("Temperature BMP085 = ");
  Serial.print(myPressure.temperature);
  Serial.println(" *C");

  Serial.print("Temperature DHT11 = ");
  Serial.print(myHumidity.temperature);
  Serial.println(" *C");

  Serial.print("Temperature 18B20 = ");
  Serial.print(myTemperature.temperature);
  Serial.println(" *C");
  
  Serial.print("Pressure = ");
  Serial.print(myPressure.pressure);
  Serial.println(" Pa");

  Serial.print("Humidity = ");
  Serial.print(myHumidity.humidity);
  Serial.println(" %");

  Serial.print("Heat index = ");
  Serial.print(myHumidity.heatIndex);
  Serial.println(" *C ");
  
  Serial.println();
}
