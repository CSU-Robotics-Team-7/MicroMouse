/*TODO list 
-use ir distance sensors
-setup motor library
-setup encoders
-setup gyro
-finish maze library


*/

#include "maze.h"
#include <HCSR04.h>
#include "motion.h"
#include "turnSensor.h"

int triggerPin = 35;
int echoPin = 37;
UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);
//pin Assignments
int bottonApin = 1;
int bottonBpin = 2;



Maze m;
motion mv;

struct coord
{
  int x;
  int y;
};
typedef struct coord currentCoordinates;
void setup() {
  m.Setup();

  
  Serial.begin(9600);

}

void loop() {
  //m.printMaze();
  char button;

  Serial.println(distance);
  delay(100);

  //Sit still
  //motors.setSpeeds(0,0)
  //wait for button press
  //get button press button = a or b;

  //if last button press was A, explore()
  //explore();
 
  
  //if last button press was B, finish()
  
}

 //explore asks the maze for the next best tile to travel to and travels there, updates the maze
 //after certain time limit return to start, or if batteries are low, or if most optimal path been found
void explore(){
  
  gotoTile(m.explore(currentCoordinates));
}
  //finish mode runs solve from maze and only travels the array of coordinates returned
void finish(){
//  (0,1)
//  (1,1)
  
}
//turns and travels to specific tile, when done update new coordinates
void gotoTile(struct coords){
  int newX = 1;
  int newY = 0;
  
  currentCoordinates.x = newX;
  currentCoordinates.y = newY;
}
