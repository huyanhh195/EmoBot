#include "utils.h"

#define MY_WIFI
// #define DEBUG

#ifdef MY_WIFI
const char *ssid = "PQN";
const char *password = "MKwifilagi";
#else
const char *ssid = "Legno";
const char *password = "legno1867";
#endif

const char *addr_open_weather_map = "http://api.openweathermap.org/data/2.5/weather?q=Ho%20Chi%20Minh&appid=2ae22b8b21080a4934d24064bf3ed3c0&units=metric";

void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi ...\n");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }

  Serial.print("\n");
#ifdef DEBUG
  Serial.println(WiFi.localIP());
#endif
}

DynamicJsonDocument getJsonFromHttp(const char *addr) {
  HTTPClient http;
  String server = addr;
  DynamicJsonDocument doc(2048);

  http.begin(server);
  int httpCode = http.GET();
  if (httpCode > 0) {
    String data = http.getString();

#ifdef DEBUG
    Serial.println(data);
#endif
    DeserializationError error = deserializeJson(doc, data);
    if (error) {
      // println(F"deserializeJson() failed!");
      // return -1;
    }
  } else {
    Serial.println("Error on HTTP request");
  }
  http.end();
  return doc;
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  initWiFi();
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    DynamicJsonDocument data = getJsonFromHttp(addr_open_weather_map);
    if (data != NULL) {
      long timezone = data["timezone"];
      long dt = data["dt"];
      time_t local_time = timezone + dt;

      struct tm *timeinfo = gmtime(&local_time);
      
      Serial.print(timeinfo->tm_hour);
      Serial.print(":");
      Serial.print(timeinfo->tm_min);
      Serial.print(":");
      Serial.println(timeinfo->tm_sec);
    }
  }
  delay(1000);
}