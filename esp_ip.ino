#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <SoftwareSerial.h>
 
const char* ssid = "Danjo";
const char* password = "Openadaa";
HTTPClient http; 
SoftwareSerial toduino(0,2);

void setup () { 
  Serial.begin(115200);
  toduino.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print("Connecting..");
  }
  Serial.print("Connected");
}
 
void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    if(toduino.available()){
      http.begin("http://192.168.43.33/"+toduino.read()+toduino.read()+toduino.read());
      int httpCode = http.GET();
      Serial.println(httpCode);
      http.end();
    }
  }
}
