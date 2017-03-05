#include <Servo.h>
#define trigPin1 7
#define echoPin1 6
#define trigPin2 4
#define echoPin2 5

Servo servo;
void setup()
{
Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
servo.attach(8);
}
void loop()
{
long duration; 

digitalWrite(trigPin1, HIGH);
delayMicroseconds(500);
digitalWrite(trigPin1, LOW);
duration = pulseIn(echoPin1, HIGH);
int front = (duration/2) / 29.1;
Serial.print("front distance= ");
Serial.println(front);

digitalWrite(trigPin2, HIGH);
delayMicroseconds(500);
digitalWrite(trigPin2, LOW);
duration = pulseIn(echoPin2, HIGH);
int back = (duration/2) / 29.1;
Serial.print("back distance= ");
Serial.println(back);
delay(1000);
if (front< 50)
{
servo.write(90);

digitalWrite(trigPin1, HIGH);

digitalWrite(trigPin1, LOW);
duration = pulseIn(echoPin1, HIGH);
int right= (duration/2) / 29.1;
Serial.print("right distance= ");
Serial.println(right);
delay(2000);

digitalWrite(trigPin2, HIGH);

digitalWrite(trigPin2, LOW);
duration = pulseIn(echoPin2, HIGH);
int left = (duration/2) / 29.1;
Serial.print("left distance=");
Serial.println(left);
}

else
{
servo.write(0);
}

delay(2000);
}



