
void setup() {
  // put your setup code here, to run once:
pinMode(3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(3,64);
delay(2000);
analogWrite(3,0);
delay(2000);
}
