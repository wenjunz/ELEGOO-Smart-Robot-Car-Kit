#include "Arduino.h"
#include "Elegoo.h"
#include <Servo.h>
#include <IRremote.h>

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


//    Left motor truth table
//  ENA         IN1               IN2         Description
//  LOW   Not Applicable    Not Applicable    Motor is off
//  HIGH        LOW               LOW         Motor is stopped (brakes)
//  HIGH        HIGH              LOW         Motor is on and turning forwards
//  HIGH        LOW               HIGH        Motor is on and turning backwards
//  HIGH        HIGH              HIGH        Motor is stopped (brakes)

//    Right motor truth table
//  ENB         IN3             IN4         Description
//  LOW   Not Applicable   Not Applicable   Motor is off
//  HIGH        LOW             LOW         Motor is stopped (brakes)
//  HIGH        LOW             HIGH        Motor is on and turning forwards
//  HIGH        HIGH            LOW         Motor is on and turning backwards
//  HIGH        HIGH            HIGH        Motor is stopped (brakes)

//    The direction of the car's movement
//  Left motor    Right motor     Description
//  stop(off)     stop(off)       Car is stopped
//  forward       forward         Car is running forwards
//  forward       backward        Car is turning right
//  backward      forward         Car is turning left
//  backward      backward        Car is running backwards


int in1;
int in2;
int in3;
int in4;
int ENA;
int ENB;

long duration, cm;

Servo libServo;

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
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(LineTeacking_Pin_Right, INPUT);
  pinMode(LineTeacking_Pin_Middle, INPUT);
  pinMode(LineTeacking_Pin_Left, INPUT);
  libServo.attach(3);
  IrReceiver.begin(RECV_PIN, LED); // Start the receiver
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
void car::back(int speed){
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

void car::back(){
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

long car::getDistance() {
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  cm = (duration/2) / 29.1;
  return cm;
}

void car::forwardT(int speed, float time){
  forward(speed);
  delay(time);
  stop();
}

void car::backT(int speed, float time){
  back(speed);
  delay(time);
  stop();
}

void car::leftT(int speed, float time){
  left(speed);
  delay(time);
  stop();
}

void car::rightT(int speed, float time){
  right(speed);
  delay(time);
  stop();
}

unsigned long car::getIR(){
  if (IrReceiver.decode()) {
    IrReceiver.resume();
    unsigned long var = IrReceiver.decodedIRData.decodedRawData;
    return var;
  }
}

char car::getIRdec(){
  switch(getIR()){
    case FORWARD: return 1;   break;
    case BACK:    return 2;   break;
    case LEFT:    return 3;   break;
    case RIGHT:   return 4;   break;
    case STOP:    return 5;   break;
    case KEY1:    return 6;   break;
    case KEY1:    return 7;   break;
    default:                  break;
  }
}

void car::remoteIR(){
  int preMillis;
  switch(getIRdec()){
    case 1: 
      forward();
      preMillis = millis();  
      break;
    case 2:    
      back();
      preMillis = millis();     
      break;
    case 3:    
      left();
      preMillis = millis();     
      break;
    case 4:   
      right(); 
      preMillis = millis();   
      break;
    case 5:    
      stop();
      preMillis = millis();     
      break;
    default:                  
      break;
  }
  if(millis() - preMillis > 500){
    stop();
    preMillis = millis();
  }
}

void car::remoteIRT(int time){
  for(int i = time; i > 0; i--){
    remote();
    delay(1);
  }
}

int car::getLightR(){
  int r = !digitalRead(10);
  return r;
}

int car::getLightM(){
  int m = !digitalRead(4);
  return m;
}

int car::getLightL(){
  int l = !digitalRead(2);
  return l;
}

void car::line(){
  if(car::getLightM() == 0){
    forward();
  }
  else if(car::getLightR() == 0) {
    right();
    while(car::getLightR() == 0);
  }
  else if(car::getLightL() == 0) {
    left();
    while(car::getLightL() == 0);
  }
}

void car::delay(unsigned long time){
  for(unsigned long i = 0; i < t; i++) {
    getBTdec();
    getIRdec();
    delay(1);
  }
}

unsigned long car::getBT(){
  if(Serial.available()){
    unsigned long val = Serial.read();
    return val;
  }
}

char car::getBTdec(){
  switch(getBT()){
    case FORWARD: return f;   break;
    case BACK:    return b;   break;
    case LEFT:    return l;   break;
    case RIGHT:   return r;   break;
    case STOP:    return s;   break;
    case KEY0:    return 0;   break;
    case KEY1:    return 1;   break;
    case KEY2:    return 2;   break;
    case KEY3:    return 3;   break;
    case KEY4:    return 4;   break;
    case KEY5:    return 5;   break;
    case KEY6:    return 6;   break;
    case KEY7:    return 7;   break;
    case KEY8:    return 8;   break;
    case KEY9:    return 9;   break;
    default:                  break;
}