#include <HardwareSerial.h>
#include <String.h>

int a=2;
int b =3;
int c = 4;
int d = 8;
int e = 9;
void setup() {
  // put your setup code here, to run once:
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  
 
  Serial.begin(9600);

}

void loop() {
  //put your main code here, to run repeatedly:
 

  if (Serial.available()){
    // char command = Serial.read();
    // if(command == 'A'){
    // digitalWrite(a,HIGH);}
    // else if(command=='B')
    // digitalWrite(a,LOW);
    String inputString = Serial.readStringUntil('\n');
    // int number1 = inputString.substring(0, inputString.indexOf(',')).toInt();
    // int number2 = inputString.substring(inputString.indexOf(',') + 1).toInt();
    // int number3 = inputString.substring(inputString.indexOf(',') + 2).toInt();
    int number1 = inputString.substring(0, inputString.indexOf(',')).toInt();
    inputString.remove(0, inputString.indexOf(',') + 1);
    int number2 = inputString.substring(0, inputString.indexOf(',')).toInt();
    inputString.remove(0, inputString.indexOf(',') + 1);
    int number3 = inputString.toInt();
    //int num = Serial.parseInt();
    if(number2==0){
      digitalWrite(a,HIGH);
      digitalWrite(c,LOW);
    }else{
      digitalWrite(a,LOW);
      digitalWrite(c,HIGH);
    }
    analogWrite(b,number1);
    if(number3==1){
      digitalWrite(e,HIGH);
    }
    else{
      digitalWrite(e,LOW); 
    }   
  }
  

}
