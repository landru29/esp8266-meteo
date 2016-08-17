#include "humidity.h"
#include "pressure.h"
#include "temperature.h"
#include "wifi_connect.h"
#include "meteo_server.h"
#include "serial_display.h"


Pressure pressure;
Humidity humidity;
Temperature temperature;

WifiConnect wifiConnect;
MeteoServer server(&humidity, &pressure, &temperature);

  
void setup() {
  Serial.begin(115200);
  
  if (!pressure.init()) {
    Serial.println("Could not find a valid BMP085 sensor, check wiring!");
  }

  humidity.init();
    
  if (!temperature.init()) {
    Serial.println("Could not find a valid 18B20 sensor, check wiring!");
  }

  if (!wifiConnect.startWPSPBC()) {
    Serial.println("Could not connect to the local wifi");
  }
}
  
void loop() {
  /*delay(2000);
  
  pressure.read();
  humidity.read();
  temperature.read();

  serialDisplay(pressure, humidity, temperature);*/
  server.run();

}
