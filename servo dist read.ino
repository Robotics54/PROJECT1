#include <Servo.h>
#define trigPin 7
#define echoPin 6

Servo servo;
void setup()
{
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
servo.attach(8);
}
void loop()
{
long duration, distance;

digitalWrite(trigPin, HIGH);
delayMicroseconds(500);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
Serial.println(distance);
if (distance < 50)
{
servo.write(90);

digitalWrite(trigPin, HIGH);

digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
int distance1 = (duration/2) / 29.1;
Serial.print("distance 1= ");
Serial.println(distance1);
delay(2000);
}
digitalWrite(trigPin, HIGH);

digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
Serial.println(distance);
if (distance < 50)
{
servo.write(180);

delay(10);
digitalWrite(trigPin, HIGH);

digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
int distance2 = (duration/2) / 29.1;
Serial.print("distance 2= ");
Serial.println(distance2);
delay(2000);
}
digitalWrite(trigPin, HIGH);

digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
Serial.println(distance);
if (distance < 50)
{
servo.write(-90);

delay(10);
digitalWrite(trigPin, HIGH);

digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
int distance3 = (duration/2) / 29.1;
Serial.print("distance 3= ");
Serial.println(distance3);
delay(2000);
}
/*servo.write(270);
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
int distance3 = (duration/2) / 29.1;
Serial.println(distance3);*/

else
{
servo.write(0);
}

delay(4000);
}


