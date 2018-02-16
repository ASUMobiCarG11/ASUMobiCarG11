int a;
void setup() {
  // put your setup code here, to run once:
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(a=4;a<8;a++){
digitalWrite(a,HIGH);
delay(1000);
digitalWrite(a,LOW);
}
 for(a=6;a>4;a--){
digitalWrite(a,HIGH);
delay(1000);
digitalWrite(a,LOW);
}
}
