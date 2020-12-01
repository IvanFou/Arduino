#include <LiquidCrystal_I2C.h> // Debe descargar la Libreria que controla el I2C
#include<Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int humo;
int alarma = 10;
int rojo = 11;
int amarillo = 12;
int verde = 13; 
int relay = 8;

void setup(){
 lcd.init();
 lcd.backlight();
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Bienvenido ");
 delay(3000);
Serial.begin(9600);
pinMode(rojo,OUTPUT);  
pinMode(amarillo,OUTPUT);
pinMode(verde,OUTPUT);
pinMode(alarma,OUTPUT);
pinMode(relay,OUTPUT);
  
}

void loop(){
humo = analogRead(A3);
Serial.println(humo);
delay(100);
  
if (humo<400)
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("No Alcohol");

digitalWrite(relay,HIGH);
digitalWrite(verde,HIGH);
digitalWrite(amarillo,LOW);  
digitalWrite(rojo,LOW);
noTone(alarma);   
}    
  
if ((humo>400) and (humo<430))
{
 lcd.clear();  
lcd.setCursor(0,0);
lcd.print("Hay alcohol");

digitalWrite(relay,LOW);
digitalWrite(verde,LOW);
digitalWrite(amarillo,HIGH);  
digitalWrite(rojo,LOW);
tone(alarma,440); 
delay(500);
tone(alarma,440);
delay(1000);   
tone(alarma,440);
delay(900);   
  
}
  
if (humo>431)
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Mucho Alcohol");

digitalWrite(relay,LOW);
digitalWrite(verde,LOW);
digitalWrite(amarillo,LOW);  
digitalWrite(rojo,HIGH);
tone(alarma,440);  
}    
delay(100);
}
