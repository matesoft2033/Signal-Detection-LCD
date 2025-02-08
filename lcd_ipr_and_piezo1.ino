#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

int signal;

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  lcd.begin(16,2);
}

void loop()
{
  signal = digitalRead(3);
  if (signal == 1){
    
    digitalWrite(6, LOW);
    digitalWrite(2, HIGH);
    
    lcd.setCursor(2,0);
    lcd.print("Unidentified");
    lcd.print("    ");
    
    for (int i = 0;i < 10;i++) {
    	digitalWrite(4,HIGH);
      	delay(100);
      	digitalWrite(4, LOW);
      	delay(100);
    }
  }
  else {
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
    digitalWrite(6, HIGH);
    lcd.clear();
    lcd.setCursor(2,0);
  	lcd.print("All Fine");
    lcd.print("    ");
    
  }
}