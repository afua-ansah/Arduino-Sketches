#include <LiquidCrystal.h>

//initializing library with interfacing arduino pin numbers 
//i.e. rs, en, d4, d5, d6, d7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // put your setup code here, to run once:
//  prints message to screen on first line
lcd.begin(16, 2);
lcd.print("Hey Afua!");
delay(4000);

//prints message to screen on second line
lcd.setCursor(0, 1);
lcd.print("You know what?");

//clear screen after 3s 
delay(3000);
lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
// prints message to screen at set time
if (millis()/1000 >= 5){
  lcd.setCursor(0, 0);
  lcd.print("It's about time ");
}
if (millis()/1000 >= 10){
  lcd.setCursor(0, 1);
  lcd.print("you went skiing!");
}
}
