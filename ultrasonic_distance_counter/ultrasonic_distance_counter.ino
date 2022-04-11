/*adapted from elegoo.com*/

#include "SR04.h"

#define TRIG_PIN 1
#define ECHO_PIN 0

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);//Initialization of Serial Port
   delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  a=sr04.Distance();
   Serial.print(a);
   Serial.println("cm");//The difference between "Serial.print" and "Serial.println" 
                        //is that "Serial.println" can change lines.
   delay(1000);
}
