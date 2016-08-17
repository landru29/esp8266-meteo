#ifndef __METEO_SERVER__H__
#define __METEO_SERVER__H__

#include "humidity.h"
#include "pressure.h"
#include "temperature.h"


class MeteoServer {
  public:
    MeteoServer(Humidity* humidity, Pressure* pressure, Temperature* temperature);
    void run();
    static void handleRoot();
    static Pressure* pressure;
    static Humidity* humidity;
    static Temperature* temperature;
};

//void handleRoot();


#endif
