# 🚨 LCD Security Alert System  

An Arduino-powered **security alert system** that uses an **Adafruit LCD display** to show status messages based on a detected signal. It includes **LED alerts** to indicate warnings.

## 📸 Circuit Diagram  
Here’s the circuit setup for this project:  

![Circuit Diagram](circuit_image.png)

## 🔧 Features  
✅ **Real-time status display** using `Adafruit_LiquidCrystal`  
✅ **Signal detection** using a digital sensor  
✅ **Alert system** with LED blinking  
✅ **Automatic LCD updates**  

## 🛠 Components Used  
- **Arduino Board** (Uno/Nano)  
- **Adafruit LCD Display**  
- **LED** (for alert system)  
- **Resistors & jumper wires**  
- **Signal sensor (e.g., IR sensor, motion detector, etc.)**  

## 🚀 How It Works  
1. **Connect the Circuit**: Follow the diagram above.  
2. **Upload the Code**: Load `lcd_alert.ino` to your Arduino.  
3. **Power On**:  
   - If a signal is detected, the LCD displays **"Unidentified"**, and the LED blinks.  
   - If no signal is detected, the LCD displays **"All Fine"**, and the LED turns off.  

## 📜 Code  
```cpp
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

int signal;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  lcd.begin(16,2);
}

void loop() {
  signal = digitalRead(3);
  if (signal == 1) {
    digitalWrite(6, LOW);
    digitalWrite(2, HIGH);
    lcd.setCursor(2,0);
    lcd.print("Unidentified");
    for (int i = 0; i < 10; i++) {
      digitalWrite(4, HIGH);
      delay(100);
      digitalWrite(4, LOW);
      delay(100);
    }
  } else {
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
    digitalWrite(6, HIGH);
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("All Fine");
  }
}
