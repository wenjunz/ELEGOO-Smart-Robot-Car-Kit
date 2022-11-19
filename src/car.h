#ifndef car_H
#define car_H
#include <Arduino.h>
class car
{
  public:
    car();
    /**

    */
    void  init(int version);
    void  init();
    void  forward(int speed);
    void  backward(int speed);
    void  left(int speed);
    void  right(int speed);
    void  stop();
    void  forwardT(int speed, int time);
    int   getDistance();
  private:
};

#if !defined(NO_GLOBAL_INSTANCES) && !defined(NO_GLOBAL_CAR)
extern car car;
#endif

#endif
