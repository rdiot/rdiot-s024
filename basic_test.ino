/* Key Switch Module (KY-004) [S024] : http://rdiot.tistory.com/127 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004
int R = 2;
byte lastButton = HIGH;
byte nowButton = HIGH;

void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");
  pinMode(R, INPUT);
  digitalWrite(R, HIGH);

  delay(1000);

  lcd.clear();
}

void loop()
{
 
  lcd.setCursor(0,0);
  lcd.print("S024:KY-004KeySwitch");

  byte nowButton = digitalRead(R);

  lcd.setCursor(0,1);
  lcd.print("value="+(String)nowButton);

  if (HIGH == lastButton)
  {
    if (LOW == nowButton)
    {
     lcd.setCursor(0,2);
     lcd.print("pushed  ");
    }
  }
  else
  {
    if (HIGH == nowButton)
    {
     lcd.setCursor(0,2);
     lcd.print("released");
    }
  }
 
 lastButton = digitalRead(R);
 delay(100);

}
