//9.25 in between walls 10" squares, 10x10 units
#include <Arduino.h>
#include "maze.h"



Maze::Maze(){
}
void Maze::setup(){
 //fill mazeArray with empty and unvisited files
  for(int i=0;i < 10; i++){
    for(int j = 0; j < 10 ;j++){
      mazeArray[i][j].north = true;
      mazeArray[i][j].east = true;
      mazeArray[i][j].south = true;
      mazeArray[i][j].west = true;
      mazeArray[i][j].visited = false;
      
      if(j == 9) mazeArray[i][j].north = false;
      if(i == 0) mazeArray[i][j].west = false;
      if(j == 0) mazeArray[i][j].south = false;
      if(i == 9) mazeArray[i][j].east = false;
    }
  }
}

void Maze::printMaze(){
      for(int i=0;i < 10; i++){
        for(int j = 0; j < 10 ;j++){
          Serial.print(i);
          Serial.print(" , ");
          Serial.print(j);
          Serial.print(" :  ");
          Serial.print(mazeArray[i][j].north);
          Serial.print(" /  ");
          Serial.print(mazeArray[i][j].east);
          Serial.print(" /  ");
          Serial.print(mazeArray[i][j].south);
          Serial.print(" /  ");
          Serial.print(mazeArray[i][j].west);
          Serial.print(" /  ");
          Serial.print(mazeArray[i][j].visited);  
          Serial.println();         
        }
   }
}
