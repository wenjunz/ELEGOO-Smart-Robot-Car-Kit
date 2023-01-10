#ifndef car_H
#define car_H
#include <Arduino.h>
#include <Servo.h>

//--------Ultrasonic Sensor---------//
#define echo A4
#define trig A5

#define defaultVersion 3
#define defaultSpeed 255

//-------Line Tracking Pins--------//
#define LineTeacking_Pin_Right  10
#define LineTeacking_Pin_Middle 4
#define LineTeacking_Pin_Left   2

//---------- IR REMOTE -------------//
#define RECV_PIN  12        //Infrared signal receiving pin
#define LED       13        //define LED pin
#define L         16738455
#define UNKNOWN_L 1386468383

//------- IR REMOTE CODES ---------//
#define FORWARD   16736925
#define BACK      16754775
#define LEFT      16720605
#define RIGHT     16761405
#define STOP      16712445
#define KEY1      16738455 //Line Teacking mode
#define KEY2      16750695 //Obstacles Avoidance mode
#define KEY3      16756815
#define KEY4      16724175
#define KEY5      16718055
#define KEY6      16743045
#define KEY7      16716015
#define KEY8      16726215
#define KEY9      16734885
#define KEY0      16730805
#define KEY_STAR  16728765
#define KEY_HASH  16732845


class car
{
  public:
    car();  //Constructor
    /**
    This is the functiom to Initialze the Library.
    Write the Version Number of your Robot into the brackets.
    */
    void  init(int version);
    void  init();
    void  forward(int speed);
    void  back(int speed);
    void  left(int speed);
    void  right(int speed);
    void  forward();
    void  back();
    void  left();
    void  right();
    void  stop();
    long  getDistance();
    void  forwardT(int speed, float time);
    void  backT(int speed, float time);
    void  leftT(int speed, float time);
    void  rightT(int speed, float time);
    unsigned long getIR();
    char getIRdec();
    void remote();
    void remoteT(int time);
    int   getLightR();
    int   getLightM();
    int   getLightL();
    void  line();
  private:
};

#if !defined(NO_GLOBAL_INSTANCES) && !defined(NO_GLOBAL_CAR)
extern car car;
#endif

#endif
