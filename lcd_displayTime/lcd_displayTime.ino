#include <TimeLib.h>
#include <LiquidCrystal.h>


//code adapted from https://www.codeguru.com/IoT/building-a-clock-with-an-arduino.html
//initializing library with interfacing arduino pin numbers 
//i.e. rs, en, d4, d5, d6, d7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void digitalClockDisplay(){
  // Update the Clock
  
  lcd.setCursor(0,1); // Set the cursor to the 1st position (0) on the 2nd line (1)
  
  lcd.print(hour()); // Print the Hour
  
  lcd.print(":"); // Print the colon
  
  if (minute() < 10) // Add a leading zero if its less than 10
    lcd.print(0);
  lcd.print(minute()); // Print the Minute
  
  lcd.print(":"); // Print the colon
  
  if (second() < 10) // Add a leading zero if its less than 10
    lcd.print(0);
  lcd.print(second()); // Print the Second
 
  // Output the current time to the Serial Monitor
  Serial.print("Current Time: ");
  Serial.print(hour());
  Serial.print(":");
  if (minute()<10)
    Serial.print(0);
  Serial.print(minute());
  Serial.print(":");
  if (second()<10)
    Serial.print(0);
  Serial.println(second());
}

void processSyncMessage() {
  // If Unix Timestamp is provided over serial, parse the timestamp
  while(Serial.available() >=  TIME_MSG_LEN ){  // Ensure it contains at least 10 characters
    char c = Serial.read() ; // Capture the Serial Header
    Serial.print(c);  // Print it out
    if( c == TIME_HEADER ) { // Make sure its the right header
      time_t pctime = 0; // Clear the time
      for(int i=0; i < TIME_MSG_LEN -1; i++){   
        c = Serial.read();          
        if( c >= '0' && c <= '9'){   
          pctime = (10 * pctime) + (c - '0') ; // convert digits to a number    
        }
      }   
      setTime(pctime);   // Sync the Arduino clock with the Unix Timestamp
    }  
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Start serial connection
  
  lcd.begin(16, 2); // Set up the LCD library. 16 Characters x 2 Lines
  
  lcd.print("Clock Starting"); // Print a startup message to the LCD
}

void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()) {
    processSyncMessage(); // If incoming serial, start syncing clock
  }
  
  if(timeStatus() == timeNotSet) {
    // Time is not set, say so on the display
    
    lcd.setCursor(0,0); // Set cursor tells the library where to start writing
    lcd.print("Waiting for Sync"); // print sends text to the display at the above location
    Serial.println("Waiting for Sync"); // Print to the serial monitor
  
  }else{     
      // Time is set, display the current time!
      
      lcd.setCursor(0,0);
      lcd.print("Current Time:   "); // There are extra spaces at the end to clear out previous text
      
      digitalClockDisplay(); 
  } 
  delay(1000); // Update every 1 second
}
