#include <SoftwareSerial.h>

int states[]={HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};
SoftwareSerial esp(2,3);

void setup() {
	Serial.begin(9600);
	esp.begin(9600);
  	for(int i=0; i<9; i++)
    	pinMode(i+4, INPUT_PULLUP);
}

void loop() {
	for(int i=0; i<9; i++){
		int tempState = digitalRead(i+4);
		if(tempState != states[i]){
			states[i] = tempState;
			esp.write(
				'#' +
				(char)(i+1) +
				states[i]==1?"Y":"N"
			);
		}
	}
}
