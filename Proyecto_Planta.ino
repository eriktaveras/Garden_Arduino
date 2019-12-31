#include <LiquidCrystal.h>
int tempPin = 0;
int redValue;
int greenValue;
int blueValue;
const int sensorPin = A1;

#define BLUE 3
#define GREEN 5
#define RED 6

//                BS  E  D4 D5  D6 D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
void setup()
{
 pinMode(2,OUTPUT);
  
  Serial.begin(9600);
  lcd.begin(16, 2);
pinMode(RED, OUTPUT);
pinMode(GREEN, OUTPUT);
pinMode(BLUE, OUTPUT);
digitalWrite(RED, HIGH);
digitalWrite(GREEN, LOW);
digitalWrite(BLUE, LOW);
}
void loop()
{
    int humedad = analogRead(sensorPin);
   Serial.print(humedad);
  
   if(humedad < 500)
   {
      Serial.println("Encendido");  
      //hacer las acciones necesarias
   }
   delay(1000);
  int tempReading = analogRead(tempPin);
  // This is OK
  double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK );       //  Temp Kelvin
  float tempC = tempK - 273.15;            // Convert Kelvin to Celcius
  float tempF = (tempC * 9.0)/ 5.0 + 32.0; // Convert Celcius to Fahrenheit

  // Display Temperature in C
  lcd.setCursor(0, 0);
  //lcd.print("Temp         C  ");
  // Display Temperature in F
  lcd.print("Temp:        F  ");
  lcd.setCursor(6, 0);
  // Display Temperature in C
  lcd.print(tempC);
  lcd.setCursor(0, 1);
 // lcd.print("Status :         ");
  lcd.setCursor(0, 1);
  if (humedad > 500) {
    lcd.print("Humedad  :  NO");
    digitalWrite(2,LOW);
   
   }
  else {
    lcd.print("Humedad  :  OK");
     
 digitalWrite(2,HIGH);
  }

  delay(500);
#define delayTime 10 // fading time between colors

redValue = 255; // choose a value between 1 and 255 to change the color.
greenValue = 0;
blueValue = 0;


for(int i = 0; i < 255; i += 1) // fades out red bring green full when i=255
{
redValue -= 1;
greenValue += 1;
// The following was reversed, counting in the wrong directions
// analogWrite(RED, 255 - redValue);
// analogWrite(GREEN, 255 - greenValue);
analogWrite(RED, redValue);
analogWrite(GREEN, greenValue);
delay(delayTime);
}

redValue = 0;
greenValue = 255;
blueValue = 0;

for(int i = 0; i < 255; i += 1) // fades out green bring blue full when i=255
{
greenValue -= 1;
blueValue += 1;

analogWrite(GREEN, greenValue);
analogWrite(BLUE, blueValue);
delay(delayTime);
}

redValue = 0;
greenValue = 0;
blueValue = 255;

for(int i = 0; i < 255; i += 1) // fades out blue bring red full when i=255
{
blueValue -= 1;
redValue += 1;

analogWrite(BLUE, blueValue);
analogWrite(RED, redValue);




}
}
