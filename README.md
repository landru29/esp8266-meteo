# Meteo station

This is a cheap meteo station, on your local wifi network

## Features

This meteo station embed :
* Temperature sensor **DS18B20**
* Humidity sensor **DHT22**
* Pressure sensor **BMP085**
* Wifi chip **ESP8266** (Wemos D1 mini)

## Schematic

![Meteo Station](sch/schematic.png?raw=true)

## PCB

### Top copper

![Top copper](pcb/meteo_etch_copper_top.png?raw=true)

### Bottom copper

![bottom copper](pcb/meteo_etch_copper_bottom.png?raw=true)

## How to use

### Connect to local wifi

The meteo station support WPS connection. After power on, the LED will:
* Send a first flash: *device is powered*
* Blink 10 seconds: *Try to connect with previous parameters (previous successful WPS)*
* If failed, double blink 10 seconds: *You must press WPS button on your router*
    * Continuous light: *Try to connect with WPS*
* If success flash blink 10 seconds: *Connection success*
* switch off: *The meteo station is ready*

### Get meteo data

Send an HTTP GET request: http://meteo_by_noopy/

You will get a json object
````
{
    "bmp-temperature": "20.30"
    "dht-temperature": "20.40"
    "ds-temperature": "20.36"
    "bmp-pressure": "10240"
    "dht-humidity": "19.60"
    "dht-headt-index": "22.10"
}
````
