#ifndef Motor_h
#define Motor_h
#include "Arduino.h"

class Motor{
  public:
  Motor(int standBy, int AIN1, int AIN2, int PWMA, int BIN1, int BIN2, int PWMB);
  void forward(int _spd);
  void backward(int _spd);
  void turnRight(int _spd);
  void turnLeft(int _spd);
  void runMotor(int _pickMotor, int _spd, int _dir);
  void stop();
  
  private:
  int _standBy;
  int _AIN1;
  int _AIN2;
  int _PWMA;
  int _BIN1;
  int _BIN2;
  int _PWMB;
  int _pickMotor;
  int _spd;
  bool _dirPin1;
  bool _dirPin2;
};

#endif
