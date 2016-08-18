#include "meteo_server.h"
#include <ESP8266WebServer.h>


ESP8266WebServer _server_(80);

Humidity* MeteoServer::humidity = 0;
Pressure* MeteoServer::pressure = 0;
Temperature* MeteoServer::temperature = 0;

MeteoServer::MeteoServer(Humidity* myHumidity, Pressure* myPressure, Temperature* myTemperature) {
  MeteoServer::humidity = myHumidity;
  MeteoServer::pressure = myPressure;
  MeteoServer::temperature = myTemperature;
  _server_.on("/", MeteoServer::handleRoot);
  _server_.begin();
}

void MeteoServer::handleRoot() {
  MeteoServer::pressure->read();
  MeteoServer::humidity->read();
  MeteoServer::temperature->read();

  String content = "{";

  content += String("\"bmp-temperature\":\"") + String(MeteoServer::pressure->temperature) + String("\",");
  content += String("\"dht-temperature\":\"") + String(MeteoServer::humidity->temperature) + String("\",");
  content += String("\"ds-temperature\":\"") + String(MeteoServer::temperature->temperature) + String("\",");
  content += String("\"bmp-pressure\":\"") + String(MeteoServer::pressure->pressure) + String("\",");
  content += String("\"dht-humidity\":\"") + String(MeteoServer::humidity->humidity) + String("\",");
  content += String("\"dht-heat-index\":\"") + String(MeteoServer::humidity->heatIndex) + String("\"");

  content += "}";

  _server_.send(200, "application/json", content);
}

void MeteoServer::run() {
  _server_.handleClient();
}
