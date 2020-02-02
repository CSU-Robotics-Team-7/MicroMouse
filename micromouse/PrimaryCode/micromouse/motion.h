/*
this class will use the motor and turnsensor classes with the encoders and distance sensors to navigate between 2 points in a straight line
- also will be able to return locations of the walls since the distance senors are initialized or at least have the distance sensors accessable

use nearby walls to keep the robot centered, a threshold will be used to determine if the robot is traveleing parallel inbetween walls to straighten out and calibrate sensors

*/
#ifndef motion_h
#define motion_h
#include "Arduino.h"
//#include "Motor.h"
//#include "Maze.h"
#include <USDS.h>
#include <Encoder.h>




class motion{
  public:

//initilize 4 ultra sonic sensors, gyro and 2 encoders and motor driver
  motion(int encw1, int encw2, int ence1, int ence2,                 
         int standBy,int AIN1,int AIN2,int PWMA,int BIN1,   //Each encoder has A and B digital pins
         int BIN2,int PWMB,int gyroSDA,int gryoSCL,int gyroINT);     //Gyro/Accel has 9 variables
              

//    //travel between 2tiles given in a straight line
//    void to(struct robotCoord, struct destCoord, bool detect);
    
//    //detect walls and return tile struct with visited as true
//    struct tile getWalls();


    double distanceN;
    double distanceE;
    double distanceS;
    double distanceW;
    double angle;
    

//dsn.measureDistanceCm();

  
  private:

    //read and store sensor values
    void updateSensors();

// Do we need to include the underscore procedure as in the motor library? Why/why not is this required? This is done to adress the instance situation!    
    int encw1;
    int encw2;
    int ence1;
    int ence2;
    int dsne;
    int dsnt;
    int dsee;
    int dset;
    int dsse;
    int dsst;
    int dswe;
    int dswt;
    int standBy; 
    int AIN1;
    int AIN2;
    int PWMA;
    int BIN1;
    int BIN2;
    int PWMB;
    int gyroSDA;
    int gryoSCL;
    int gyroINT;

    usds dsn(); //I beleive that I am creating a private instance of the USDS class called dsn. This allows us to use the functions contained inside the USDS class library
    usds dse();
    usds dsw();
    usds dss();
};

#endif
