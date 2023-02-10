#include "Sensors.h"

bool keepDistanceState = 1;
int  keepDistanceValue = 10;

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

long elegoo::getDistance(int angle) {
  libServo->write(angle);
  return getDistance();
}

long elegoo::getDistanceReturn(int angle){
  
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
    keepDistance();
    delay(1);
  }
}

void elegoo::keepDistance(){
  if(keepDistanceState){
    int distance = getDistance();
    if(distance < keepDistanceValue){
      stop();
    }
  }
}

void elegoo::enableKeepDistance(){
  keepDistanceState = 1;
}

void elegoo::disableKeepDistance(){
  keepDistanceState = 0;
}

void elegoo::setKeepDistance(int val){
  keepDistanceValue = val;
}

//TODO delay for IRremote