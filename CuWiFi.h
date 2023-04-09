#ifndef CuWiFi_h
#define CuWiFi_h

#include <WiFi.h>

class CuWiFi {
  public:
    void connect(const char* ssid, const char* password) {
      WiFi.begin(ssid, password);
      Serial.print("Connecting to WiFi");
      while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
      }
      Serial.println("WiFi connected");
    }
};

#endif
