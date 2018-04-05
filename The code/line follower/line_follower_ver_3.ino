#include <RedBot.h>
RedBotSensor left_sen = RedBotSensor(A3);   
RedBotSensor center_sen = RedBotSensor(A4); 
RedBotSensor right_sen = RedBotSensor(A5);

int MotorLF = 9 ; // two left wheels move forward
int MotorRF = 6; // two right wheels move forward
int MotorLB = 10; // two left wheels move backward
int MotorRB = 5; // two right wheels move Backward
int speedState=100;
int lineStandard = 512; //for linetracking
void forward() // move car forward 
{
  analogWrite(MotorLF,speedState);
  analogWrite(MotorRF,speedState);
  analogWrite(MotorLB,0);
  analogWrite(MotorRB,0);
}

void moveForwardLeft()
{
  analogWrite(MotorLF,speedState/4);
  analogWrite(MotorRF,speedState);
  analogWrite(MotorLB,0);
  analogWrite(MotorRB,0);
  
}

void moveForwardRight()
{
  analogWrite(MotorLF,speedState);
  analogWrite(MotorRF,speedState/4);
  analogWrite(MotorLB,0);
  analogWrite(MotorRB,0);
  
}

void backward() //move car backward
{
  analogWrite(MotorLF,0);
  analogWrite(MotorRF,0);
  analogWrite(MotorLB,speedState);
  analogWrite(MotorRB,speedState);
}

void moveBackwardLeft()
{
  analogWrite(MotorLF,0);
  analogWrite(MotorRF,0);
  analogWrite(MotorLB,speedState/2);
  analogWrite(MotorRB,speedState);
  
}

void moveBackwardRigth()
{
  analogWrite(MotorLF,0);
  analogWrite(MotorRF,0);
  analogWrite(MotorLB,speedState);
  analogWrite(MotorRB,speedState/2);
}

void left() //move car to left
{
  analogWrite(MotorLF,0);
  analogWrite(MotorRF,speedState);
  analogWrite(MotorLB,speedState);
  analogWrite(MotorRB,0);
}

void right() //move car to right
{
  analogWrite(MotorLF,speedState);
  analogWrite(MotorRF,0);
  analogWrite(MotorLB,0);
  analogWrite(MotorRB,speedState);
}
void setup() {
  pinMode(MotorLF,OUTPUT);
  pinMode(MotorRF,OUTPUT);
  pinMode(MotorLB,OUTPUT);
  pinMode(MotorRB,OUTPUT);

}

void loop() {
  if(center_sen.read() > lineStandard && right_sen.read() < lineStandard && left_sen.read() <lineStandard)
    {
      Serial.println("forward");
      forward();
    }
  if(center_sen.read() < lineStandard && right_sen.read() < lineStandard && left_sen.read() <lineStandard)
    {
      while(1){
        right();
        if(center_sen.read() > lineStandard)
        break;
      }
    }
  if(center_sen.read() < lineStandard && right_sen.read() > lineStandard && left_sen.read() <lineStandard)
    {
      Serial.println("right");
      moveForwardRight();
    }
  if(center_sen.read() > lineStandard && right_sen.read() > lineStandard && left_sen.read() <lineStandard)
    {
      Serial.println("right");
      right();
    }
  if(center_sen.read() < lineStandard && right_sen.read() < lineStandard && left_sen.read() >lineStandard)
    {
      Serial.println("left");
      moveForwardLeft();
    }
  if(center_sen.read() > lineStandard && right_sen.read() < lineStandard && left_sen.read() >lineStandard)
  {
      left();   
  }   
  if(center_sen.read() > lineStandard && right_sen.read() > lineStandard && left_sen.read() > lineStandard)
  {
      forward();
      if(center_sen.read() < lineStandard && right_sen.read() < lineStandard && left_sen.read() <lineStandard)
      {
        backward();
        moveForwardRight();
      }
  }
}
