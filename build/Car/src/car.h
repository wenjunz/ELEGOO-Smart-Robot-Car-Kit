#ifndef car_H
#define car_H
#include <Arduino.h>

#define Echo A4
#define Trig A5
#define defaultVersion 3
#define defaultSpeed 255


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
    int   getDistance();
    void  forwardT(int speed, float time);
    void  backwardT(int speed, float time);
    void  leftT(int speed, float time);
    void  rightT(int speed, float time);
  private:
};

#if !defined(NO_GLOBAL_INSTANCES) && !defined(NO_GLOBAL_CAR)
extern car car;
#endif

#endif
