#ifndef __HUMIDITY__H__
#define __HUMIDITY__H__


class Humidity {
  public:
    float humidity;
    float temperature;
    float heatIndex;
    Humidity();
    void read();
    void init();
};


#endif
