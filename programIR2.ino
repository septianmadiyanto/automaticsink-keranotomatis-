
#include <Servo.h>

#define ir1  11  
#define ir2  12
#define ledmerah 3
#define ledhijau 5
#define buzzer 6

Servo myservo;
int jarak1;
int jarak2;
int langkah=0;

unsigned long myPrevMillis2 = millis();
void setup() {

myservo.attach(9);
pinMode(ir1,INPUT);
pinMode(ir2,INPUT);
pinMode(ledmerah,OUTPUT);
pinMode(ledhijau,OUTPUT);
pinMode(buzzer,OUTPUT);
myservo.write(180);
digitalWrite(ledmerah,HIGH);
digitalWrite(ledhijau,HIGH);
digitalWrite(buzzer,HIGH);
myDelay(1000);
digitalWrite(ledmerah,LOW);
digitalWrite(ledhijau,LOW);
digitalWrite(buzzer,LOW);
myservo.detach();

myDelay(10);

}
void myDelay(int del) {
  unsigned long myPrevMillis = millis();
  while (millis()- myPrevMillis <= del);
}
void bacasensor()
{
  jarak1=digitalRead(ir1);
  jarak2=digitalRead(ir2);
  myDelay(100);
}
void loop() {

  bacasensor();  
  
  if(langkah==0&&jarak1==0||jarak2==0){    
    myservo.attach(9);
    myservo.write(0);
    digitalWrite(ledhijau,HIGH);
    myDelay(2000);
    digitalWrite(ledhijau,LOW); 
    myPrevMillis2=millis();  
  }
  else if(langkah==0&&jarak1==1&&jarak2==1) {
    myservo.write(180);
    digitalWrite(ledmerah,HIGH);
    myDelay(2000);
    digitalWrite(ledmerah,LOW);
    myservo.detach();
    if (millis()- myPrevMillis2 >=6000&&millis()- myPrevMillis2 <=7000){
    langkah++;
  }
  }
  else if (langkah==1){
    for(int i=0;i<=4;i++){
      digitalWrite(buzzer,HIGH);
      digitalWrite(ledhijau,HIGH);
      myDelay(200);
      digitalWrite(buzzer,LOW);
      digitalWrite(ledhijau,LOW);
      myDelay(200);
    }
    langkah=0;
  }
    
  
  


  
}
