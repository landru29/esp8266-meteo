#include "pressure.h"
#include <Adafruit_BMP085.h>


Adafruit_BMP085 bmp;


Pressure::Pressure() {
}

bool Pressure::init() {
  if (!bmp.begin()) {
    this->canRead = false;
  }
  this->canRead = true;
  return this->canRead;
}

void Pressure::read() {
  this->temperature = 0;
  this->pressure = 0;
  if (!this->canRead) {
    return;
  }
  this->temperature = bmp.readTemperature();
  this->pressure = bmp.readPressure();
}
