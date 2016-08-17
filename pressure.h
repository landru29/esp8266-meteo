#ifndef __PRESSURE__H__
#define __PRESSURE__H__


class Pressure {
  public:
    long pressure;
    float temperature;
    bool canRead;

    Pressure();
    void read();
    bool init();
};


#endif
