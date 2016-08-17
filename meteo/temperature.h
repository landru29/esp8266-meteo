#ifndef __TEMPERATURE__H__
#define __TEMPERATURE__H__

#include <OneWire.h>

class Temperature {
  public:
    float temperature;
    Temperature();
    /**
     * Get a temperature sensor address
     * @return True if an address was found, False if no more address
     */
    bool init();
    
    /**
     * Launch a measure on a sensor
     * @return Temperature in celcius
     */
    float read();
    
    /**
     * True if at least one sensor was found
     * @return True if found
     */
    bool sensorFound();
  private:
    byte addr[8] = {0, 0, 0, 0, 0, 0, 0, 0};
};



#endif
