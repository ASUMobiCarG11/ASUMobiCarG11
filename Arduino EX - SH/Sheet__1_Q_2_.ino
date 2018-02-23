int led1=4;
int led2=5;
int led3=6;
int led4=7;

void setup() {
  // put your setup code here, to run once:
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
for(int i=4;i<=7;i++)
{digitalWrite(i,HIGH);
delay(500);
digitalWrite(i,LOW);
delay(500);
}
for(int i=7;i>=4;i--)
{digitalWrite(i,HIGH);
delay(500);
digitalWrite(i,LOW);
delay(500);
}
}
