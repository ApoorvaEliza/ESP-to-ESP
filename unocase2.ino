#include <SoftwareSerial.h>

const int pin = 12;
const int pin2 = 13;
const int pin3 = 11;
const int pin4 = 10;
SoftwareSerial esp(7,6);

void setup() {
Serial.begin(9600);
esp.begin(9600);
pinMode(pin,OUTPUT);
pinMode(pin2,OUTPUT);
}

void loop() {
if(esp.available()){  
String line = esp.readString();
Serial.print(line);

if(line=="ON1"){
  digitalWrite(pin, HIGH);
  Serial.println("LED1 is ON");
}
if(line=="OFF1"){
  digitalWrite(pin, LOW);
    Serial.println("LED1 is OFF");

}

if(line=="ON0"){
  digitalWrite(pin2, HIGH);
    Serial.println("LED2 is ON");

}
if(line=="OFF0"){
  digitalWrite(pin2,LOW);
    Serial.println("LED2 is OFF");

}
}}
