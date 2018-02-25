int MotorLF = 5 ; // two left wheels move forward
int MotorRF = 9; // two right wheels move forward
int MotorLB = 6; // two left wheels move backward
int MotorRB = 10; // two right wheels move Backward
int speedState;
char command;  //bluetooth state

void setup() {
  Serial.begin(9600);
  pinMode(MotorLF, OUTPUT);
  pinMode(MotorRF, OUTPUT);
  pinMode(MotorLB, OUTPUT);
  pinMode(MotorRB, OUTPUT);
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
  analogWrite(MotorLF,speedState/2);
  analogWrite(MotorRF,speedState);
  analogWrite(MotorLB,0);
  analogWrite(MotorRB,0);
  
}

void moveForwardRight()
{
  analogWrite(MotorLF,speedState);
  analogWrite(MotorRF,speedState/2);
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

void setSpeed (int x) {
  speedState = map(x, 0, 100, 0, 255);
}
void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
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
      setSpeed(40);
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
    else if (command == 'F') {
      forward();
    }
    // move Forward Left if distance >20
    else if (command == 'G') {
      moveForwardLeft();
    }
    // move Forward Right if distance >20
    else if (command == 'I') {
      moveForwardRight();
    }
    // moving backward
    else if (command == 'B') {
      backward();
    }
    // moving back left
    else if (command == 'H') {
      moveBackwardLeft();
    }
    // moving back right
    else if (command == 'J') {
      moveBackwardRigth();
    }
    // moving left
    else if (command == 'L') {
      left();
    }
    // moving right
    else if (command == 'R') {
      right();
    }
    // stop
    else if (command == 'S') {
      Stop();
    }
  }
}
