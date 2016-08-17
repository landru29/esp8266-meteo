#include "wifi_connect.h"
#include <ESP8266WiFi.h>
#include <string.h>

#define LED D0
#define HOSTNAME "meteo_by_noopy"

WifiConnect::WifiConnect() {
  this->ledState = LOW;
  pinMode(LED, OUTPUT);
  WiFi.hostname(HOSTNAME);
}

void WifiConnect::pauseConnect() {
  for (int i=0; i<15; i++) {
    digitalWrite(LED, HIGH);
    delay(100);
    digitalWrite(LED, LOW);
    delay(100);
    digitalWrite(LED, HIGH);
    delay(100);
    digitalWrite(LED, LOW);
    delay(400);
  }
  digitalWrite(LED, LOW);
}

void WifiConnect::connectSuccess() {
  Serial.println("SUCCESS");
  for (int i=0; i<20; i++) {
    digitalWrite(LED, HIGH);
    delay(400);
    digitalWrite(LED, LOW);
    delay(100);
  }
  digitalWrite(LED, LOW);
}

void WifiConnect::connectFailed() {
  Serial.println("FAIL");
  for (int i=0; i<20; i++) {
    digitalWrite(LED, HIGH);
    delay(100);
    digitalWrite(LED, LOW);
    delay(400);
  }
  digitalWrite(LED, LOW);
}

void WifiConnect::stepFoolConnect() {
  this->ledState = !this->ledState;
  digitalWrite(LED, this->ledState);
  Serial.print(".");
}

void WifiConnect::startWps() {
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  Serial.println("WPS config start");
}

bool WifiConnect::startWPSPBC() {
  this->startWps();
  
  // WPS works in STA (Station mode) only -> not working in WIFI_AP_STA !!! 
  Serial.printf("Trying to connect to %s with saved config ...", WiFi.SSID().c_str());
  WiFi.mode(WIFI_STA);
  WiFi.begin(WiFi.SSID().c_str(),WiFi.psk().c_str());
  while (WiFi.status() == WL_DISCONNECTED) {
    delay(500);
    this->stepFoolConnect();
  }

  //if ((!internalConf) || (WiFi.status() != WL_CONNECTED)) {
  if (WiFi.status() != WL_CONNECTED) {
      Serial.println("Fail");
      Serial.println("Press WPS button on your router");
      this->pauseConnect();
      digitalWrite(LED, HIGH);
      Serial.print("Trying to connect with WPS ...");
      
      bool wpsSuccess = WiFi.beginWPSConfig();
      if(wpsSuccess) {
          // Well this means not always success :-/ in case of a timeout we have an empty ssid
          String newSSID = WiFi.SSID();
          if(newSSID.length() > 0) {
            // WPSConfig has already connected in STA mode successfully to the new station. 
            Serial.printf("WPS finished. Connected successfull to SSID '%s'\n", newSSID.c_str());
            // save to config and use next time or just use - WiFi.begin(WiFi.SSID().c_str(),WiFi.psk().c_str());
          } else {
            wpsSuccess = false;
          }
      }
      if (wpsSuccess) {
        this->connectSuccess();
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());
        digitalWrite(LED, LOW);
      } else {
        this->connectFailed();
      }
      return wpsSuccess; 
  }
  Serial.println("Done");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  digitalWrite(LED, LOW);
  return true;
}
