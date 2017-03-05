#include <Servo.h>
#include "TimerOne.h"
//#define STOP_TIMER 0

const int trig = 2;
const int echo = 4;
const int leftForward = 5;
const int leftBackward = 6;
const int rightForward = 10;
const int rightBackward = 9;
int duration = 0;
int distance = 0;
int v1;
int v2;
int v3;
int v4;
void right(void);
Servo servo;
void setup(void) 
{
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  pinMode(leftForward , OUTPUT);
  pinMode(leftBackward , OUTPUT);
  pinMode(rightForward , OUTPUT);
  pinMode(rightBackward , OUTPUT);
  Timer1.initialize(150000);
  servo.attach(11);
  Serial.begin(9600);

}

void loop() 
{
   digitalWrite(trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig , LOW);
  duration = pulseIn(echo , HIGH);
  distance = (duration/2) / 28.5 ;
  Serial.println(distance);
  if(distance<50)
  {
    digitalWrite(leftForward , LOW);
    digitalWrite(leftBackward , LOW);
    digitalWrite(rightForward , LOW);
    digitalWrite(rightBackward , LOW);

  servo.write(90);
  digitalWrite(trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig , LOW);
  duration = pulseIn(echo , HIGH);
  distance = (duration/2) / 28.5 ;
  Serial.println(distance);
  v1=distance;

  servo.write(180);
  digitalWrite(trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig , LOW);
  duration = pulseIn(echo , HIGH);
  distance = (duration/2) / 28.5 ;
  Serial.println(distance);
  v2=distance;

  servo.write(270);
  digitalWrite(trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig , LOW);
  duration = pulseIn(echo , HIGH);
  distance = (duration/2) / 28.5 ;
  Serial.println(distance);
  v3=distance;
if(v1>v2 && v1>v3)
v4=v1;
if(v2>v3)
v4=v2;
else
v4=v3;
  
  if(v4==v1)
  {
       Timer1.initialize(30000);
       Timer1.attachInterrupt(right);
    //   TCCR0 = 0x00;  

     digitalWrite(leftForward , LOW);
    digitalWrite(leftBackward , HIGH);
    digitalWrite(rightForward , HIGH);
    digitalWrite(rightBackward , LOW);
    }
    if(v4==v2)
  {
       Timer1.initialize(60000);
       Timer1.attachInterrupt(right);
       // TCCR0 = 0x00;  

     digitalWrite(leftForward , LOW);
    digitalWrite(leftBackward , HIGH);
    digitalWrite(rightForward , HIGH);
    digitalWrite(rightBackward , LOW);
    }
    if(v4==v3)
    {
      Timer1.initialize(90000);
       Timer1.attachInterrupt(right);
      // TCCR 0 = 0x00;  

     digitalWrite(leftForward , LOW);
    digitalWrite(leftBackward , HIGH);
    digitalWrite(rightForward , HIGH);
    digitalWrite(rightBackward , LOW);
    }
  }   
  
  
  else
  {
    
    digitalWrite(leftForward , LOW);
    digitalWrite(leftBackward , HIGH);
    digitalWrite(rightForward , HIGH);
    digitalWrite(rightBackward , LOW);
    
  }
delay(50);

}
void right(void)
{
    digitalWrite(leftForward , HIGH);
    digitalWrite(leftBackward , LOW);
    digitalWrite(rightForward , HIGH);
    digitalWrite(rightBackward , LOW);  
}
