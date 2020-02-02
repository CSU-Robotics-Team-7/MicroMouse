#include "Arduino.h"
#include "Motor.h"

Motor::Motor(int standBy, int AIN1, int AIN2, int PWMA, int BIN1, int BIN2, int PWMB){
  pinMode(standBy, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);


 _standBy = standBy;
 _AIN1 = AIN1;
 _AIN2 = AIN2;
 _PWMA = PWMA;
 _BIN1 = BIN1;
 _BIN2 = BIN2;
 _PWMB = PWMB;
}

//Define the functions that we are calling

void Motor::forward(int _spd){ //The value in the parenthesis inside the loop will be the desired speed
  runMotor(1, _spd, 0);        //(Select motor A) (move at the designated speed) (forward)
  runMotor(0, _spd, 0);        //(Select motor B) (move at the designated speed) (forward)
}

void Motor::backward(int _spd){
  runMotor(1, _spd, 1);        //(Select motor A) (move at the designated speed) (backward)
  runMotor(0, _spd, 1);        //(Select motor B) (move at the designated speed) (backward)
}

void Motor::turnRight(int _spd){
  runMotor(1, _spd, 0); //The combination of motor A moving forward and motor B moving backward
  runMotor(0, _spd, 1); //at the same speeds creates a stationary right turn...hopefully!
}

void Motor::turnLeft(int _spd){
  runMotor(1, _spd, 1); //The combination of motor B moving forward and motor A moving backward
  runMotor(0, _spd, 0); //at the same speeds creates a stationary right turn...hopefully!
}

void Motor::runMotor(int _pickMotor, int _spd, int _dir){
  digitalWrite (_standBy, HIGH); //If this is low the motors stop

  //This assumes that our dirPin1 is the negative terminal and dirPin2 is the positive terminal
  //By default, if we let dir = 0 then the motor will move forward since the positive will be HIGH

  bool _dirPin1 = LOW; 
  bool _dirPin2 = HIGH;
  
  if (_dir == 1){
    _dirPin1 = HIGH;
    _dirPin2 = LOW;
  }
  
  if(_pickMotor == 1){
    digitalWrite(_AIN1, _dirPin1);
    digitalWrite(_AIN2, _dirPin2);
    analogWrite(_PWMA, _spd);
  }
  else{
    digitalWrite(_BIN1, _dirPin1);
    digitalWrite(_BIN2, _dirPin2);
    analogWrite(_PWMB, _spd);
  }
}


void Motor::stop() {
  digitalWrite(_standBy, LOW); //This stops the motors
}
