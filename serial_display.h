#ifndef __SERIAL_DISPLAY__H__
#define __SERIAL_DISPLAY__H__

#include "humidity.h"
#include "pressure.h"
#include "temperature.h"

void serialDisplay(Pressure myPressure, Humidity myHumidity, Temperature myTemperature);

#endif
