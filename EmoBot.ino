#include <WiFi.h>
#include <HTTPClient.h>

const char *ssid = "PQN";
const char *password = "MKwifilagi";

void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  Serial.print("Connecting to WiFi ...\n");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }

  Serial.print("\n");
  Serial.println(WiFi.localIP());
}

void getTemp(){
  HTTPClient http;
  String server = "http://api.openweathermap.org/data/2.5/weather?q=Ho%20Chi%20Minh&appid=YOUR_API_KEY&units=metric";

  http.begin(server);
  int httpCode = http.GET();
  if (httpCode > 0){
    String payload = http.getString();
    Serial.println(payload);
  }
  else{
    Serial.println("Error on HTTP request");
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  initWiFi();
  Serial.print("RRSI: ");
  Serial.println(WiFi.RSSI());
}

void loop() {
  getTemp();
  delay(1000);
}