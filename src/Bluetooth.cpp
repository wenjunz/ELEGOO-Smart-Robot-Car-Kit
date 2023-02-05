#include "Bluetooth.h"

void elegoo::delay(unsigned long time){
  for(unsigned long i = 0; i < time; i++) {
    getBTdec();
    //getIRdec();
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
