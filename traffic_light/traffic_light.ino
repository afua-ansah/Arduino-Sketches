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
digitalWrite(red, HIGH); //turn red light on
delay(19500); // remains on for 19.5 s
digitalWrite(red, LOW); //turn red light off

//turn green on
digitalWrite(green, HIGH);
delay(20000);
digitalWrite(green, LOW);

//turn yellow on momentarily
digitalWrite(yellow, HIGH);
delay(10000);
digitalWrite(yellow,LOW);



}
