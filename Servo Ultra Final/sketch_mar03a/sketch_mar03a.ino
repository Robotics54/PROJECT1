#include <Servo.h>
#define trigPin1 7
#define echoPin1 11
#define trigPin2 4
#define echoPin2 12
const int leftForward = 5;
const int leftBackward = 6;
const int rightForward = 10;
const int rightBackward = 9;

Servo servo;
void setup()
{
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  servo.attach(8);
  pinMode(leftForward , OUTPUT);
  pinMode(leftBackward , OUTPUT);
  pinMode(rightForward , OUTPUT);
  pinMode(rightBackward , OUTPUT);
}
void loop()
{
long duration; 
int front, back,left,right;

digitalWrite(trigPin1, HIGH);
digitalWrite(trigPin1, LOW);
duration = pulseIn(echoPin1, HIGH);
front = (duration/2) / 29.1;
Serial.print("front distance= ");
Serial.println(front);

digitalWrite(trigPin2, HIGH);
digitalWrite(trigPin2, LOW);
duration = pulseIn(echoPin2, HIGH);
back = (duration/2) / 29.1;
Serial.print("back distance= ");
Serial.println(back);
delay(20);
if (front< 50)
{
  moveStop();
servo.write(90);
delay(50);
digitalWrite(trigPin1, HIGH);
digitalWrite(trigPin1, LOW);
duration = pulseIn(echoPin1, HIGH);
right= (duration/2) / 29.1;
Serial.print("right distance= ");
Serial.println(right);
delay(20);
servo.write(0);

servo.write(90);
delay(20);
digitalWrite(trigPin2, HIGH);
digitalWrite(trigPin2, LOW);
duration = pulseIn(echoPin2, HIGH);
left = (duration/2) / 29.1;
Serial.print("left distance=");
Serial.println(left);

servo.write(0);

if(front>left && front>back && front>right)
{
  moveForward();
  }
else if(back>right && back>left)
{
  servo.write(90);
  delay(50);
  moveStop();
  delay(1000);
  moveRight();
  delay(1500);
  moveForward();
}
else if(left>right)
{
  servo.write(90);
  delay(50);
  moveStop();
  delay(1000);
  moveLeft();
  delay(2000);
  moveForward();
}
else 
{
  servo.write(90);
  delay(50);
  moveStop();
  delay(1000);
   moveRight();
   delay(800);
   moveForward();
}
}
else
{
servo.write(0);
}

delay(2000);
}


void moveForward()
{
    digitalWrite(leftForward , LOW);
    digitalWrite(leftBackward , HIGH);
    digitalWrite(rightForward , HIGH);
    digitalWrite(rightBackward , LOW);
}
void moveBackward()
{
    digitalWrite(leftForward , HIGH);
    digitalWrite(leftBackward ,LOW);
    digitalWrite(rightForward , LOW);
    digitalWrite(rightBackward , HIGH);
}
void moveRight()
{
    digitalWrite(leftForward , HIGH);
    digitalWrite(leftBackward , LOW);
    digitalWrite(rightForward , HIGH);
    digitalWrite(rightBackward , LOW);
}


void moveLeft()
{
    digitalWrite(leftForward , LOW);
    digitalWrite(leftBackward ,HIGH);
    digitalWrite(rightForward , LOW);
    digitalWrite(rightBackward , HIGH);
}
void moveStop()
{
    digitalWrite(leftForward , LOW);
    digitalWrite(leftBackward ,LOW);
    digitalWrite(rightForward , LOW);
    digitalWrite(rightBackward , LOW);
}

