#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
 
const char* ssid = "Danjo";
const char* password = "Openadaa";
const int PIN = 2; //RELAY
const int PIN0 = 0;
 int p1= HIGH;
 int p0= HIGH;
    HTTPClient http; 
 
void setup () {
 
  Serial.begin(115200);
  WiFi.begin(ssid, password);

    pinMode(PIN, INPUT);
  pinMode(PIN0, INPUT);
 
  while (WiFi.status() != WL_CONNECTED) {
 
    delay(1000);
    Serial.print("Connecting..");
 
  }Serial.print("Connected");
 
 
}
 
void loop() {
 
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
 
 //Declare an object of class HTTPClient
 if ((digitalRead(PIN)==HIGH)&&(p1== LOW)){
  p1=HIGH;
    Serial.println("2 is high");
    http.begin("http://192.168.43.33/#1Y");  //Specify request destination
    int httpCode = http.GET();   
    Serial.println(httpCode);//Send the request
 
    if (httpCode > 0) { //Check the returning code
 
      String payload = http.getString();   //Get the request response payload
      Serial.println(payload);                     //Print the response payload
 
    }
 
    http.end(); }  //Close connection
    if ((digitalRead(PIN)==LOW)&&(p1==HIGH)){ 
      p1=LOW;
      Serial.println("2 is low");
    http.begin("http://192.168.43.33/#1N");  //Specify request destination
   int httpCode = http.GET();                                                                  //Send the request
     Serial.println(httpCode);//Send the request

    if (httpCode > 0) { //Check the returning code
 
      String payload = http.getString();   //Get the request response payload
      Serial.println(payload);                     //Print the response payload
 
    }
 
    http.end();  } //Close connection
if ((digitalRead(PIN0)==HIGH)&&(p0== LOW)){ 
  p0=HIGH;
  Serial.println("0 is high");
    http.begin("http://192.168.43.33/#0Y");  //Specify request destination
    int httpCode = http.GET();                                                                  //Send the request
     Serial.println(httpCode);//Send the request

    if (httpCode > 0) { //Check the returning code
 
      String payload = http.getString();   //Get the request response payload
      Serial.println(payload);                     //Print the response payload
 
    }
 
    http.end();   }//Close connection
    if ((digitalRead(PIN0)==LOW)&&(p0== HIGH)){ 
      p0=LOW;
      Serial.println("0 is low");
    http.begin("http://192.168.43.33/#0N");  //Specify request destination
   int httpCode = http.GET();                                                                  //Send the request
     Serial.println(httpCode);//Send the request

    if (httpCode > 0) { //Check the returning code
 
      String payload = http.getString();   //Get the request response payload
      Serial.println(payload);                     //Print the response payload
 
    }
 
    http.end();  } //Close connection
 
 
  }
 
  //Send a request every 30 seconds
 
}
