#include <LiquidCrystal.h>
#include <stdio.h>

//initializing library with interfacing arduino pin numbers 
//i.e. rs, en, d4, d5, d6, d7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
long timer = 30l;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd.begin(16, 2);
lcd.print("Hey Afua!");
delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
long time = long(millis());
int time_diff = timer - (time/1000l);
 Serial.println(time);
 Serial.println(time_diff);
lcd.setCursor(0, 0);

if (timer - (time/1000l) <= 0l){
  lcd.clear();
  lcd.print("Your time is up");
  delay(300);
}
else {  

//lcd.print("You have %i seconds remaining", (millis()));
lcd.print("You have ");
lcd.print(time_diff);
delay(400);

lcd.setCursor(0, 1);
lcd.print("seconds more");
delay(300);
}
}
