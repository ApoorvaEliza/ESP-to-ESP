#include <SoftwareSerial.h>

int state = 0;
SoftwareSerial esp(2,3);

void setup() {
	Serial.begin(9600);
	esp.begin(9600);
	for(int i=0; i<9; i++)
		pinMode(i+4, OUTPUT);
}

void loop() {
	while(esp.available()){
		switch(esp.read()){
			case '#' : 
				while(esp.available()<2);
				digitalWrite(
					(int)esp.read(),
					esp.read()=='Y'?HIGH:LOW
				);
			break;
			default :
				Serial.println('Flushing');
			break;
		}
	}
	delay(10);
}
