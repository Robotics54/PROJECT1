#include <Servo.h>

int servoPin = 12;
 
Servo servo;  
 
int servoAngle = 0; 

const int trig = 2;
const int echo = 4;
const int leftForward = 5;
const int leftBackward = 6;
const int rightForward = 10;
const int rightBackward = 9;
int input;

int duration = 0;
int distance = 0;

void setup() 
{
  Serial.begin(9600);  
  servo.attach(servoPin);
  
  pinMode(leftForward , OUTPUT);
  pinMode(leftBackward , OUTPUT);
  pinMode(rightForward , OUTPUT);
  pinMode(rightBackward , OUTPUT);
  
  Serial.begin(9600);

}
void loop() {
  servo.write(45);      // Turn SG90 servo Left to 45 degrees
   delay(1000);          // Wait 1 second
   servo.write(90);      // Turn SG90 servo back to 90 degrees (center position)
   delay(1000);          // Wait 1 second
   servo.write(135);     // Turn SG90 servo Right to 135 degrees
   delay(1000);          // Wait 1 second
   servo.write(90);      // Turn SG90 servo back to 90 degrees (center position)
   delay(1000);

   for(servoAngle = 0; servoAngle < 180; servoAngle++)  //move the micro servo from 0 degrees to 180 degrees
  {                                  
    servo.write(servoAngle);              
    delay(50);                  
  }
 
  for(servoAngle = 180; servoAngle > 0; servoAngle--)  //now move back the micro servo from 0 degrees to 180 degrees
  {                                
    servo.write(servoAngle);          
    delay(10);      
  }
   
      while(Serial.available()>0){ // Checks whether data is comming from the serial port
       input=Serial.read(); // Reads the data from the serial port
        //read1=(char)input;
        Serial.println(input);
     }
   if(input==54)
   {
 if ( distance < 50 )
  {
    digitalWrite(leftForward , LOW);
    digitalWrite(leftBackward , HIGH);
    digitalWrite(rightForward , HIGH);
    digitalWrite(rightBackward , LOW);
    
    delay(500);
  }
  else
  {
    
    digitalWrite(leftForward , HIGH);
    digitalWrite(leftBackward , LOW);
    digitalWrite(rightForward , HIGH);
    digitalWrite(rightBackward , LOW);
  }
   }
   if(input==49)
    {
    digitalWrite(leftForward , HIGH);
    digitalWrite(leftBackward , LOW);
    digitalWrite(rightForward , HIGH);
    digitalWrite(rightBackward , LOW);
    delay(500);
    }
  else if(input== 50)
  {
    digitalWrite(leftForward , LOW);
    digitalWrite(leftBackward ,HIGH);
    digitalWrite(rightForward , LOW);
    digitalWrite(rightBackward , HIGH);
    delay(500);
  }
  else if(input==51)
  {
     digitalWrite(leftForward , LOW);
    digitalWrite(leftBackward , HIGH);
    digitalWrite(rightForward , HIGH);
    digitalWrite(rightBackward , LOW);
  }
 else if(input==52)
 {
   digitalWrite(leftForward , HIGH);
    digitalWrite(leftBackward ,LOW);
    digitalWrite(rightForward , LOW);
    digitalWrite(rightBackward , HIGH);
   }
   else
   {
    digitalWrite(leftForward , LOW);
    digitalWrite(leftBackward ,LOW);
    digitalWrite(rightForward , LOW);
    digitalWrite(rightBackward , LOW);
   }
   }
   

   
