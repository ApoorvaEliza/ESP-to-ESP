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
  
String line = esp.readStringUntil('\r');
Serial.print(line);

if(line=="ON1"){
  digitalWrite(pin, HIGH);
}
if(line=="OFF1"){
  digitalWrite(pin, LOW);
}

if(line=="ON0"){
  digitalWrite(pin2, HIGH);
}
if(line=="OFF0"){
  digitalWrite(pin2,LOW);
}
}
