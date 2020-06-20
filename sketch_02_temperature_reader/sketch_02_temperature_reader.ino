#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int sensorPin = A0;

void setup(){
  // open a serial port between arduino and the computer
  // communication speed=9600 bits per second
  Serial.begin(9600);
  // initialize LCD
  lcd.begin(16, 2); // tell how large the screen is
}

void loop(){
  // get analog input (0-1023)
  int analogValue = analogRead(sensorPin); 
  // convert analog input to voltage (0-5V)
  float voltage = (analogValue/1024.0)*5.0;
  // convert voltage to degrees C
  float tempC = (voltage-0.5)*100.0;
  float tempF = tempC*9.0/5.0+32.0;

  // display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: " + String(tempC) + "C :)");
  lcd.setCursor(0, 1);
  lcd.print("Temp: " + String(tempF) + "F");
  
  delay(500);
}
