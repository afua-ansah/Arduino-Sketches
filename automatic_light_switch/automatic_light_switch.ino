int analog = A0;
int led = 9;

void setup() {
  // put your setup code here, to run once:
pinMode(analog, INPUT);
pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int val = analogRead(analog);
if (val <= 150 && val <= 1023){ 
  digitalWrite(led, LOW);
}
else { 
  digitalWrite(led, HIGH);
}
}
