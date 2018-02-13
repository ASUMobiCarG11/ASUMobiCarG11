int MotorspeedL=1 ;      //Two left motors speed
int MotorspeedR=2;       //Two Right motors speed
int MotorDL=5;           //Two left motors Direction
int MotorDR=6;           //Two Right motors Direction
void moveForward()
{
  digitalWrite(MotorDL,HIGH);
  digitalWrite(MotorDR,HIGH);
  analogWrite(MotorDL,255);
  analogWrite(MotorDR,255);
}
void moveBackward()
{
  digitalWrite(MotorDL,LOW);
  digitalWrite(MotorDR,LOW);
  analogWrite(MotorspeedL,255);
  analogWrite(MotorspeedR,255);
  
}
void moveBackwardLeft()
{
  digitalWrite(MotorDL,LOW);
  digitalWrite(MotorDR,LOW);
  analogWrite(MotorspeedL,128);
  analogWrite(MotorspeedR,255);
 
  
}
void moveBackwardRigth()
{
 digitalWrite(MotorDL,LOW);
  digitalWrite(MotorDR,LOW);
  analogWrite(MotorspeedL,255);
  analogWrite(MotorspeedR,128);
}
void moveForwardLeft()
{
  digitalWrite(MotorDL,HIGH);
  digitalWrite(MotorDR,HIGH);
  analogWrite(MotorspeedL,128);
  analogWrite(MotorspeedR,255);
 
  
}
void moveForwardRight()
{
 digitalWrite(MotorDL,HIGH);
  digitalWrite(MotorDR,HIGH);
  analogWrite(MotorspeedL,255);
  analogWrite(MotorspeedR,128);
  
}
void moveLeft()
{
 digitalWrite(MotorDL,HIGH);
  digitalWrite(MotorDR,LOW);
  analogWrite(MotorspeedL,255);
  analogWrite(MotorspeedR,255);
}
void moveRight()
{
  digitalWrite(MotorDL,LOW);
  digitalWrite(MotorDR,HIGH);
  analogWrite(MotorspeedL,255);
  analogWrite(MotorspeedR,255);
  
}



void setup() {
  // put your setup code here, to run once:
  pinMode(MotorDL,OUTPUT);
  pinMode(MotorDR,OUTPUT);
  pinMode(MotorspeedL,OUTPUT);
  pinMode(MotorspeedR,OUTPUT);
   Serial.begin(115200);



}

void loop() {
  
 
}
