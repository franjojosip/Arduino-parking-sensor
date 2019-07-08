#include <LiquidCrystal.h>

#define trigPin 8
#define echoPin 9
#define buzzPin 6

long duration, distance;
LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  

  lcd.begin(16,2);
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(buzzPin,OUTPUT);

}

void loop(){
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  
  if(distance <= 40){
    tone(buzzPin,1000);   
  }
  if(distance > 40 && distance <= 60){
    buzzOn(200,50);
  }
  if(distance > 60 && distance <= 80){
    buzzOn(300,100);
  }
  if(distance > 80 && distance <= 110){
    buzzOn(400,200);
  }
  if(distance > 110 && distance <= 140){
    buzzOn(500,300);
  }
  if(distance > 140 && distance <= 200){
    buzzOn(700,400);
  }
  if(distance > 200){
    noTone(buzzPin);
  }
  lcd.setCursor(0,0);
  lcd.print("Distance: ");
  lcd.print(distance); 
  lcd.print(" cm  ");

  delay(5);
}
  
void buzzOn(int on, int off){
  tone(buzzPin,1000);
  delay(on);
  noTone(buzzPin);
  delay(off);
 }

  
