#include <NewPing.h>
#include <RedBot.h>
RedBotSensor left_sen = RedBotSensor(A3);   
RedBotSensor center_sen = RedBotSensor(A4); 
RedBotSensor right_sen = RedBotSensor(A5);

#define trigPin 13
#define echoPin 12
NewPing sonar(trigPin , echoPin,200);


int MotorLF = 9 ; // two left wheels move forward
int MotorRF = 6; // two right wheels move forward
int MotorLB = 10; // two left wheels move backward
int MotorRB = 5; // two right wheels move Backward
int speedState;
long distance;
int lineStandard = 512;
char command;  //bluetooth state

void setup()
{
  Serial.begin(115200);
  pinMode(MotorLF,OUTPUT);
  pinMode(MotorRF,OUTPUT);
  pinMode(MotorLB,OUTPUT);
  pinMode(MotorRB,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  
}



void avoidObstacle () //if distance smaller than 20cm then it goes backward then right or left
{
   while(distance<=50){
      backward();
    distance = sonar.ping_cm();}
    Stop();
}


void Stop() // stop car
{
  analogWrite(MotorLF,0);
  analogWrite(MotorRF,0);
  analogWrite(MotorLB,0);
  analogWrite(MotorRB,0);
}
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

void setSpeed (int x){
  speedState= map(x,0,100,0,255);  
}

void loop() {
  distance = sonar.ping_cm();
  if(distance<=20&&distance!=0)//library give 0 if not ultrasonic didnot recive
   avoidObstacle();
  //Serial.println(distance);
  
  if(Serial.available() > 0){ 
    command = Serial.read();   
    
    Serial.print("Reading");
    Serial.println(command);
    //******************Controls*****************
    if (command == '0') {
      setSpeed(0);
    }
    else if (command == '1') {
      setSpeed(10);
    } 
    else if (command == '2') {
      setSpeed(20);
    } 
    else if (command == '3') {
      setSpeed(30);
    } 
    else if (command == '4') {
      setSpeed(30);
    } 
    else if (command == '5') {
      setSpeed(50);
    } 
    else if (command == '6') {
      setSpeed(60);
    } 
    else if (command == '7') {
      setSpeed(70);
    } 
    else if (command == '8') {
      setSpeed(80);
    } 
    else if (command == '9') {
      setSpeed(90);
    } 
    else if (command == 'q') {
      setSpeed(100);
    } 
    // moving forward if distance >20
    else if(command=='F'){
       forward(); 
    }
    // move Forward Left if distance >20
    else if(command=='G'){
       moveForwardLeft();
    }
    // move Forward Right if distance >20
    else if(command=='I'){
     moveForwardRight();
    }
    // moving backward
    else if(command=='B'){
      backward(); 
    }
    // moving back left
    else if(command=='H'){
      moveBackwardLeft(); 
    }
    // moving back right
    else if(command=='J'){
      moveBackwardRigth(); 
    }
    // moving left
    else if(command=='L'){
      left(); 
    }
    // moving right
    else if(command=='R'){
      right(); 
    }
    // stop
    else if(command=='S'){
      Stop(); 
    } 
    else if(command=='W'){
      do{
        //*******************************
        if (command == '0') {
        setSpeed(0);
        }
        else if (command == '1') {
          setSpeed(10);
        } 
        else if (command == '2') {
          setSpeed(20);
        } 
        else if (command == '3') {
          setSpeed(30);
        } 
        else if (command == '4') {
          setSpeed(30);
        } 
        else if (command == '5') {
          setSpeed(50);
        } 
        else if (command == '6') {
          setSpeed(60);
        } 
        else if (command == '7') {
          setSpeed(70);
        } 
        else if (command == '8') {
          setSpeed(80);
        } 
        else if (command == '9') {
          setSpeed(90);
        } 
        else if (command == 'q') {
          setSpeed(100);
        }
    //*********************************
      if(center_sen.read() > lineStandard && right_sen.read() < lineStandard && left_sen.read() <lineStandard)
      {
        Serial.println("forward");
        forward();
      }
      if(center_sen.read() < lineStandard && right_sen.read() < lineStandard && left_sen.read() <lineStandard)
        {
          forward();
          if(left_sen.read() >lineStandard)
          {
            while(1){
            left();
            if(center_sen.read() > lineStandard)
              break;
            }
          }
          if(right_sen.read() >lineStandard)
          {
            while(1){
            right();
            if(center_sen.read() > lineStandard)
              break;
            }
          }
          
//          while(1){
//            right();
//            if(center_sen.read() > lineStandard)
//            break;
//          }
        }
      if(center_sen.read() < lineStandard && right_sen.read() > lineStandard && left_sen.read() <lineStandard)
        {
          Serial.println("right");
          while(1){
          right();
          if(center_sen.read() > lineStandard)
              break;  
          }
          
        }
      if(center_sen.read() > lineStandard && right_sen.read() > lineStandard && left_sen.read() <lineStandard)
        {
          forward();
        }
      if(center_sen.read() < lineStandard && right_sen.read() < lineStandard && left_sen.read() >lineStandard)
        {
          Serial.println("left");
          while(1){
          left();
          if(center_sen.read() > lineStandard)
              break;  
          }
        }
      if(center_sen.read() > lineStandard && right_sen.read() < lineStandard && left_sen.read() >lineStandard)
      {
          forward();
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
         Serial.println("OK!");
         command=Serial.read(); 
      }while(command!='w');
    } 
  }
}












