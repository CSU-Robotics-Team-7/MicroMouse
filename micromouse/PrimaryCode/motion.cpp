//9.25 in between walls 10" squares, 10x10 units
#include <Arduino.h>
//#include "Motor.h"
//#include "Maze.h"
#include <Encoder.h>
#include <USDS.h>
#include "motion.h"



//setup 2 encoders, 4 distance sensors, 1 gyro and motor driver
motion::motion(int encw1, int encw2, int ence1, int ence2,
               int standBy,int AIN1,int AIN2,int PWMA,int BIN1,
               int BIN2,int PWMB,int gyroSDA,int gryoSCL,int gyroINT){
                    
  Encoder myEncW(encw1,encw2);
  Encoder myEncE(ence1,ence2);
  //Motor m = Motor(standBy,AIN1,AIN2,PWMA, BIN1, BIN2, PWMB);

this->encw1 = encw1;

encw1 = 19;
encw2 = 52;
ence1 = 18;
ence2 = 50;

//UltraSonicDistanceSensor dsn(35, 36);
  }


    
  

/**
 * encw1 19
 * encw2 52
 * ence1 18
 * ence2 50
 * ds1e  34
 * ds1t  35
 * ds2e  36
 * ds2t  37
 * ds3e  38
 * ds3t  39
 * ds4e  40
 * ds4t  41
 * standBy 44
 * AIN1  45
 * AIN2  46
 * PWMA  5
 * BIN1  47
 * BIN2  48
 * PWMB  6
 * gyroSDA  20
 * gryoSCL  21
 * gyroINT  2
**/
  
  


void motion::updateSensors(){
    double distanceN = dsn().measureDistanceCm(); //The value of the double variable distanceN is being set to the value of the function measureDistanceCm which is part of the dsn instance
    double distanceE = dse().measureDistanceCm();
    double distanceW = dsw().measureDistanceCm();
    double distanceS = dss().measureDistanceCm();
}
