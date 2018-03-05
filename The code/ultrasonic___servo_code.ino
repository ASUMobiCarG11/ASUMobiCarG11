
#include <Servo.h>
#include "Ultrasonic.h"
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int x=0;
int pos = 0;    // variable to store the servo position
Ultrasonic ultrasonic(11,10);//(Trig,Echo)

void setup() {
  myservo.attach(9); 
	Serial.begin(9600);
 pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  myservo.write(90);
}
void forward(){
  analogWrite(6,70);
  analogWrite(5,0);
  analogWrite(9,70);
  analogWrite(10,0);
  }
  void Stop(){
    analogWrite(5,0);
  analogWrite(6,0);
  analogWrite(10,0);
  analogWrite(9,0);
    }
    void right(){
  analogWrite(6,70);
analogWrite(5,0);
analogWrite(9,0);
analogWrite(10,70);
  }
  void left(){
    analogWrite(5,70);
analogWrite(6,0);
analogWrite(9,70);
analogWrite(10,0);
    }
void loop()
{
  if (ultrasonic.Ranging(CM)<30)
    {Stop();
      
  for (pos = 90; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    if(ultrasonic.Ranging(CM)>30){right();delay(1000);myservo.write(90);x=1;break;}
    }
    if (x==0){
     for (pos = 90; pos >= 0; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    if(ultrasonic.Ranging(CM)>30){left();delay(1000);myservo.write(90);break;}
    }
    }
    }
    else {forward();x=0;}
	//output the distance in cm
	Serial.println(ultrasonic.Ranging(CM)); 
	delay(100);
}




