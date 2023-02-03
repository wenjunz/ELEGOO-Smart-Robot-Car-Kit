#include "Elegoo.h"


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
//  backward      backward        elegoo is running backwards

//Constructor

elegoo::elegoo(int version) {
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
  //libServo->attach(3);
  //IRrecv irrecv(RECV_PIN);
  //Servo libServo;
  //irrecv->begin(RECV_PIN, LED);
}


/*define forward function*/
void elegoo::forward(int speed){
  analogWrite(ENA,speed);
  analogWrite(ENB,speed);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}
/*define back function*/
void elegoo::back(int speed){
  analogWrite(ENA,speed);
  analogWrite(ENB,speed);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}
/*define left function*/
void elegoo::left(int speed){
  analogWrite(ENA,speed);
  analogWrite(ENB,speed);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}
/*define right function*/
void elegoo::right(int speed){
  analogWrite(ENA,HIGH);
  analogWrite(ENB,HIGH);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}

void elegoo::forward(){
  forward(defaultSpeed);
}

void elegoo::back(){
  forward(defaultSpeed);
}

void elegoo::left(){
  forward(defaultSpeed);
}

void elegoo::right(){
  forward(defaultSpeed);
}

void elegoo::stop(){
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
}

void elegoo::forwardT(int speed, float time){
  forward(speed);
  delay(time);
  stop();
}

void elegoo::backT(int speed, float time){
  back(speed);
  delay(time);
  stop();
}

void elegoo::leftT(int speed, float time){
  left(speed);
  delay(time);
  stop();
}

void elegoo::rightT(int speed, float time){
  right(speed);
  delay(time);
  stop();
}

long elegoo::getDistance() {
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long duration = pulseIn(echo, HIGH);
  long cm = (duration/2) / 29.1;
  return cm;
}


unsigned long elegoo::getIR(){
//  if (irrecv->decode()) {
//    irrecv->resume();
    //unsigned long var = IrReceiver.decodedIRData.decodedRawData;
    //return var;
//  }
}

char elegoo::getIRdec(){
  switch(getIR()){
    case FORWARD: return 1;   break;
    case BACK:    return 2;   break;
    case LEFT:    return 3;   break;
    case RIGHT:   return 4;   break;
    case STOP:    return 5;   break;
    case KEY1:    return 6;   break;
    case KEY2:    return 7;   break;
    default:                  break;
  }
}

void elegoo::remoteIR(){
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

void elegoo::remoteIRT(int time){
  for(int i = time; i > 0; i--){
    remote();
    delay(1);
  }
}

int elegoo::getLightR(){
  int r = !digitalRead(10);
  return r;
}

int elegoo::getLightM(){
  int m = !digitalRead(4);
  return m;
}

int elegoo::getLightL(){
  int l = !digitalRead(2);
  return l;
}

void elegoo::line(){
  if(elegoo::getLightM() == 0){
    forward();
  }
  else if(elegoo::getLightR() == 0) {
    right();
    while(elegoo::getLightR() == 0);
  }
  else if(elegoo::getLightL() == 0) {
    left();
    while(elegoo::getLightL() == 0);
  }
}

void elegoo::delay(unsigned long time){
  for(unsigned long i = 0; i < time; i++) {
    getBTdec();
    getIRdec();
    delay(1);
  }
}

unsigned long elegoo::getBT(){
  if(Serial.available()){
    unsigned long val = Serial.read();
    return val;
  }
}

char elegoo::getBTdec(){
  int dec;
  switch(getBT()){
    case FORWARD: dec = 'f'; return dec;   break;
    case BACK:    dec = 'b'; return dec;   break;
    case LEFT:    dec = 'l'; return dec;   break;
    case RIGHT:   dec = 'r'; return dec;   break;
    case STOP:    dec = 's'; return dec;   break;
    case KEY0:    dec = '0'; return dec;   break;
    case KEY1:    dec = '1'; return dec;   break;
    case KEY2:    dec = '2'; return dec;   break;
    case KEY3:    dec = '3'; return dec;   break;
    case KEY4:    dec = '4'; return dec;   break;
    case KEY5:    dec = '5'; return dec;   break;
    case KEY6:    dec = '6'; return dec;   break;
    case KEY7:    dec = '7'; return dec;   break;
    case KEY8:    dec = '8'; return dec;   break;
    case KEY9:    dec = '9'; return dec;   break;
    default:                    break;
  }
}

/*
float elegoo::regler(float ist, float soll, int p_faktor, ){
  float abweichung = soll - ist;
  float ergebnis  = (abweichung * p_factor);
  return ergebnis;
}
*/