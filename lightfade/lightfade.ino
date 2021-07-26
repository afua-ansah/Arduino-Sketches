int led = 9;
int brightness = 0;
int fade = 5;

void setup() {
  // put your setup code here, to run once:
pinMode(led, OUTPUT); //set PWM pin as output pin
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(led, brightness);

brightness += fade;
if (brightness <= 0 || brightness >= 255)
  fade = -fade;

delay(100);
}
