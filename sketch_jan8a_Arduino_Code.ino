#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int IR_Sensor1=2;
const int IR_Sensor2=7;
double startMillis; 
double endMillis;
double free_fall_time;
double h = 1.41; 
double g,v;
int activate=0;

void setup() { 

//Pin 2 is connected to the output of proximity sensor
lcd.backlight();
pinMode(IR_Sensor1,INPUT);
pinMode(IR_Sensor2,INPUT);
lcd.init();
lcd.setCursor(0, 0);
lcd.print("T:");
lcd.setCursor(8, 0);
lcd.print("V:");
lcd.setCursor(0, 1);
lcd.print("Gravity:");
}

void loop() {
if(digitalRead(IR_Sensor1)==LOW)
{
//lcd.clear();
startMillis = millis(); 
activate=0;
}
if(digitalRead(IR_Sensor2)==LOW) //Check the sensor output
if (activate==0){
{
endMillis = millis(); 
free_fall_time = (endMillis-startMillis)/1000;
lcd.setCursor(2, 0);
lcd.print(free_fall_time);
lcd.setCursor(6, 0);
lcd.print("s");
g = 2*h/pow(free_fall_time, 2); // gravity
v = g*free_fall_time; // free fall velocity
lcd.setCursor(10, 0);
lcd.print(v);
lcd.setCursor(13, 0);
lcd.print("m/s");
lcd.setCursor(8, 1);
lcd.print(g);
lcd.setCursor(12, 1);
lcd.print("m/s2");
activate=1;
}
} 
}