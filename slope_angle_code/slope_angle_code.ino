const int xpin = 1;                  // x-axis of the accelerometer
const int ypin = 2;                  // y-axis
const int zpin = 3;                  // z-axis (only on 3-axis models)
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup()
{
 Serial.begin(9600);

    lcd.init(); 
  lcd.backlight();
}
void loop()
{
 int x = analogRead(xpin); 
 
 int y = analogRead(ypin);  
 
 int z = analogRead(zpin);  
 
float zero_G = 512.0;
float scale = 102.3;  
Serial.print(((float)x - 331.5)/65*9.8);
Serial.print("\t");
Serial.print(((float)y - 329.5)/68.5*9.8); 
Serial.print("\t");
Serial.print(((float)z - 340)/68*9.8); 
Serial.print("\t");
Serial.print((acos((((float)z - 340)/68*9.8)/9.8))*180/3.14);
Serial.print("\n");

  lcd.setCursor(0, 0);         
  lcd.print("Angle in degrees :");        
  lcd.setCursor(2, 1);       
  if( ((float)z - 340)/68*9.8 <= 9.8)
    lcd.print((acos((((float)z - 340)/68*9.8)/9.8))*180/3.14); 
  else 
    lcd.print(0);
delay(500);
}
