//9.25 in between walls 10" squares
#ifndef maze_h
#define maze_h
#include <Arduino.h>

typedef struct
{
  boolean north;
  boolean east;
  boolean south;
  boolean west;
  boolean visited;
} tile;





class Maze
{
    public:
        tile mazeArray[10][10];
        Maze();
        
        void setup();
        //initilize maze with no walls and no visited tiles, add walls to outer tiles

        struct coord explore(struct robotCoord);
        //returns xy position of the next best tile to visit
        
        //possibly keep second maze that keeps track of tiles that dont need visisted
        //solve without using unvisited tile and solve with using unvisited tile and if its faster without unvisisted tile we do not need to visit them
        
        void solve();
        //find and return solution to the maze in array form 

        void printMaze();
        //prints maze to serial


};

#endif
