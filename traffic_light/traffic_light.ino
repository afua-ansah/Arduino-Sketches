int red = 3;
int yellow = 5;
int green = 7;

void setup() {
  // put your setup code here, to run once:
pinMode(red, OUTPUT);
pinMode(yellow, OUTPUT);
pinMode(green, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//turn red light on
activateLED(red, 19500);

//turn green on
activateLED(green, 20000);

//turn yellow on momentarily
activateLED(yellow, 10000);
}

void activateLED(int color, int time) {
//function to determine which LED is switched on 
//the duration for which it is on  
digitalWrite(color, HIGH);
delay(time);
digitalWrite(color, LOW);

}
