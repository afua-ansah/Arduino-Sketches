
/*adapted from 
 *
 * (C) 2015 Ole Wolf <wolf@blazingangles.com>
 * 
 */

#include <dht_nonblocking.h>
#include <LiquidCrystal.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11

/*initializing library with interfacing arduino pin numbers 
 i.e. rs, en, d4, d5, d6, d7*/
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

static const int DHT_SENSOR_PIN = 2;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );
int buzzer = 3;
int analogIn = A0;
int led = 5;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd.begin(16, 2);
pinMode(buzzer, OUTPUT);
pinMode(analogIn, INPUT);
pinMode(led, OUTPUT);
}

/*
 * Poll for a measurement, keeping the state machine alive.  Prints
 * to display if a measurement is available.
 */
static void measure_environment( float *temperature, float *humidity )
{
  static unsigned long measurement_timestamp = millis( );

  /* Measure once every four seconds. */
  if( millis( ) - measurement_timestamp > 3000ul )
  {
    if( dht_sensor.measure( temperature, humidity ) == true )
    {
      measurement_timestamp = millis( );
    lcd.print( "T = " );
    lcd.print( *temperature, 1 );
    lcd.print( " deg. C " );
    lcd.setCursor(0, 1);
    lcd.print( "H = " );
    lcd.print( *humidity, 1 );
    lcd.print( "%" );
    lcd.setCursor(0, 0);
    
    Serial.print( "T = " );
    Serial.print( *temperature, 1 );
    Serial.print( " deg. C, H = " );
    Serial.print( *humidity, 1 );
    Serial.println( "%" );
    }
    /*part of code adapted from ELEGOO active*/
    if (*temperature <= 24) {
      for (unsigned char i = 0; i < 80; i ++) {
      digitalWrite(buzzer,HIGH);
      delay(1);//wait for 1ms
      digitalWrite(buzzer,LOW);
      delay(1);//wait for 1ms 
      }
    }
  }

}


void loop() {
  // put your main code here, to run repeatedly:
float temperature;
  float humidity;

  /* Measure temperature and humidity.  If the functions returns
     true, then a measurement is available. */
measure_environment( &temperature, &humidity); 
int val = analogRead(analogIn);
if (val >= 10 0 && val <= 1023){ 
  digitalWrite(led, LOW);
}
else { 
  digitalWrite(led, HIGH);
}
}
