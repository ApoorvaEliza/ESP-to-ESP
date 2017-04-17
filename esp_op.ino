#include <SoftwareSerial.h>

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

SoftwareSerial toduino(0,2); // rx,tx!!
const char* ssid = "Danjo";
const char* password = "Openadaa";
MDNSResponder mdns;
ESP8266WebServer server(80);

void handleRoot() {
  server.send(200, "text/plain", "hello from esp8266!");
}


 
void setup(void){
  toduino.begin(9600);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  
  
  if (mdns.begin("esp8266", WiFi.localIP())) {
    Serial.println("MDNS responder started");
  }
  
  server.on("/", handleRoot);
  
  server.on("/1/y", [](){
  server.send(200, "text/plain", "Okay -- Light is ON!");
  toduino.println("ON1");
  });
   server.on("/0/y", [](){
  server.send(200, "text/plain", "Okay -- Light is ON!");
  toduino.println("ON0");
  });
  server.on("/0/n", [](){
  server.send(200, "text/plain", "Okay -- Light is OFF!");
  toduino.println("OFF1");
  });
  server.on("/1/n", [](){
  server.send(200, "text/plain", "Okay -- Light is OFF!");
  toduino.println("OFF0");
  });
   server.on("/2/y", [](){
  server.send(200, "text/plain", "Okay -- Light is ON!");
  toduino.println("ON2");
  });
  server.on("/2/n", [](){
  server.send(200, "text/plain", "Okay -- Light is OFF!");
  toduino.println("OFF2");
  });
   server.on("/3/y", [](){
  server.send(200, "text/plain", "Okay -- Light is ON!");
  toduino.println("ON3");
  });
  server.on("/3/n", [](){
  server.send(200, "text/plain", "Okay -- Light is OFF!");
  toduino.println("OFF3");
  });

  
  
  server.begin();
  Serial.println("HTTP server started");
}
 
void loop(void){
  server.handleClient();
}
