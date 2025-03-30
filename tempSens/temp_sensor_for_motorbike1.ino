#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int potPin = A1;
const int pwmPin = 9;
const int tmpSensPin = A0;
const float refVol = 5.0;
const float adcRes = 1023.0;

void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(pwmPin, OUTPUT);
  
  lcd.print("heleu");
  delay(2000);
  lcd.clear();
  
}

void loop()
{
  int potRead = analogRead(potPin);
  int tmpRead = analogRead(tmpSensPin);
  float tmpVolt = tmpRead * (refVol / adcRes);
  float temp = (tmpVolt - 0.5) * 100.0;
  int pwmVal = map(potRead, 0, 1023, 0, 100);
  
  analogWrite(pwmPin, pwmVal);
  
  lcd.clear();
  lcd.print("temp: ");
  lcd.print(temp, 1);
  delay(20000);
}

//lcd: 1. setup
//	   2. print values

//pot: 1. setup
//	   2. map values 

//tmp: 1. setup
//	   2. alg for temp
//	   3. passing to lcd
