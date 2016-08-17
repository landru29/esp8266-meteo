#include "humidity.h"
#include "DHT.h"


DHT dht(D7, DHT22);


Humidity::Humidity() {
}

void Humidity::init() {
  dht.begin();
}

void Humidity::read() {
  this->temperature = dht.readTemperature();
  this->humidity = dht.readHumidity();
  this->heatIndex = 0;

  if (!isnan(this->humidity) && !isnan(this->temperature)) {
    this->heatIndex = dht.computeHeatIndex(this->temperature, this->humidity, false);
  }
}

