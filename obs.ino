
const int trig = 2;
const int echo = 4;
const int leftForward = 5;
const int leftBackward = 6;
const int rightForward = 10;
const int rightBackward = 9;
int input;
String text="";

int duration = 0;
int distance = 0;

void setup() 
{
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  pinMode(leftForward , OUTPUT);
  pinMode(leftBackward , OUTPUT);
  pinMode(rightForward , OUTPUT);
  pinMode(rightBackward , OUTPUT);
  
  Serial.begin(9600);

}
void loop() {
  
      
      while(Serial.available()>0)
      { 
       input=Serial.read(); 
        
        Serial.println(input);
      }

      
   if(input==54)
   {
     
   do
   {
    digitalWrite(trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig , LOW);
  duration = pulseIn(echo , HIGH);
  distance = (duration/2) / 28.5 ;
  Serial.println(distance);
 if ( distance < 50 )
  {
    digitalWrite(leftForward , HIGH);
    digitalWrite(leftBackward , LOW);
    digitalWrite(rightForward , HIGH);
    digitalWrite(rightBackward , LOW);
    
    delay(500);
    input=Serial.read(); 
  }
  else
  {
    
    digitalWrite(leftForward , LOW);
    digitalWrite(leftBackward , HIGH);
    digitalWrite(rightForward , HIGH);
    digitalWrite(rightBackward , LOW);
    input=Serial.read(); 
  }
   } while(input!=48);
   digitalWrite(leftForward , LOW);
    digitalWrite(leftBackward , LOW);
    digitalWrite(rightForward , LOW);
    digitalWrite(rightBackward , LOW);
   }
   
   
     
 else  if(input==49)
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
   else if(input==53)
   {
    digitalWrite(leftForward , LOW);
    digitalWrite(leftBackward ,LOW);
    digitalWrite(rightForward , LOW);
    digitalWrite(rightBackward , LOW);
   }

 else if(input=55)
 {
  text="";
  while (Serial.available())
      {
         delay(5);
         char c = (char)Serial.read();
         text += c;
         Serial.println(text); 
      }


   if(text=="go")
 {
   digitalWrite(leftForward , LOW);
    digitalWrite(leftBackward , HIGH);
    digitalWrite(rightForward , HIGH);
    digitalWrite(rightBackward , LOW);
    text="";
 }
  if(text=="back")
 {
  digitalWrite(leftForward , HIGH);
    digitalWrite(leftBackward ,LOW);
    digitalWrite(rightForward , LOW);
    digitalWrite(rightBackward , HIGH);
    text="";
 }
 if(text=="right")
 {
  digitalWrite(leftForward , HIGH);
    digitalWrite(leftBackward , LOW);
    digitalWrite(rightForward , HIGH);
    digitalWrite(rightBackward , LOW);
    text="";
 }
 if(text=="left")
 {
  digitalWrite(leftForward , LOW);
    digitalWrite(leftBackward ,HIGH);
    digitalWrite(rightForward , LOW);
    digitalWrite(rightBackward , HIGH);
    text="";
 }
 if(text=="stop")
 {
  digitalWrite(leftForward , LOW);
    digitalWrite(leftBackward ,LOW);
    digitalWrite(rightForward , LOW);
    digitalWrite(rightBackward , LOW);
    text="";
 }

}
}


  
   
   

   
