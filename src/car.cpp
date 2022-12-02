#include "car.h"
//www.elegoo.com
//2016.09.12



//    The direction of the car's movement
//  ENA   ENB   IN1   IN2   IN3   IN4   Description
//  HIGH  HIGH  HIGH  LOW   LOW   HIGH  Car is runing forward
//  HIGH  HIGH  LOW   HIGH  HIGH  LOW   Car is runing back
//  HIGH  HIGH  LOW   HIGH  LOW   HIGH  Car is turning left
//  HIGH  HIGH  HIGH  LOW   HIGH  LOW   Car is turning right
//  HIGH  HIGH  LOW   LOW   LOW   LOW   Car is stoped
//  HIGH  HIGH  HIGH  HIGH  HIGH  HIGH  Car is stoped
//  LOW   LOW   N/A   N/A   N/A   N/A   Car is stoped

int in1;
int in2;
int in3;
int in4;
int ENA;
int ENB;

//Constructor

car::car() {
  in1=0;
  in2=0;
  in3=0;
  in4=0;
  ENA=0;
  ENB=0;
}

void car::init(int version){ 
    if(version == 1){
      in1=9;
      in2=8;
      in3=7;
      in4=6;
      ENA=10;
      ENB=5;
    }
    if(version == 2){
      in1=6;
      in2=7;
      in3=8;
      in4=9;
      ENA=5;
      ENB=11;
    }
    if(version == 3){
      in1=7;
      in2=8;
      in3=9;
      in4=11;
      ENA=5;
      ENB=6;
    }
    pinMode(in1,OUTPUT);
    pinMode(in2,OUTPUT);
    pinMode(in3,OUTPUT);
    pinMode(in4,OUTPUT);
    pinMode(ENA,OUTPUT);
    pinMode(ENB,OUTPUT);
}

void car::init(){
  car::init(defaultVersion);
}

/*define forward function*/
void car::forward(int speed){
  analogWrite(ENA,speed);
  analogWrite(ENB,speed);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}
/*define back function*/
void car::backward(int speed){
  analogWrite(ENA,speed);
  analogWrite(ENB,speed);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}
/*define left function*/
void car::left(int speed){
  analogWrite(ENA,speed);
  analogWrite(ENB,speed);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}
/*define right function*/
void car::right(int speed){
  analogWrite(ENA,HIGH);
  analogWrite(ENB,HIGH);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}

void car::forward(){
  forward(defaultSpeed);
}

void car::backward(){
  forward(defaultSpeed);
}

void car::left(){
  forward(defaultSpeed);
}

void car::right(){
  forward(defaultSpeed);
}


void car::stop(){
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
}

int car::getDistance(){
  digitalWrite(Trig, LOW);
  delayMicroseconds(5);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(1);
  digitalWrite(Trig, LOW);
  return (int)pulseIn(Echo, HIGH) / 58;
}

void car::forwardT(int speed, int time){
  forward(speed);
  delay(time);
  stop();
}

void car::backwardT(int speed, int time){
  backward(speed);
  delay(time);
  stop();
}

void car::leftT(int speed, int time){
  left(speed);
  delay(time);
  stop();
}

void car::rightT(int speed, int time){
  right(speed);
  delay(time);
  stop();
}
