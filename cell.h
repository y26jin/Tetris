#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include "window.h"
const int maxNeighbours = 8;
//colors available in window.h
//Black, Red, Green, Blue, Cyan, Yellow, Magenta, Orange, Brown
enum COLOR {WHITE=0, BLACK, RED, GREEN, BLUE, CYAN, YELLOW, MAGENTA, ORANGE, BROWN};

class Cell {
  bool isAlive;
  char cell_c; 
  unsigned int Cnum; //which is the #th of blocks that appearred.
  COLOR cell_Color;
  // Add other private members if necessary
  #define X_width 38
        int x; 
	int y;
	int width;
	int height;
	Xwindow *Xwin;
  void draw();
  void undraw();
 public:
  Cell();  // Default constructor
  ~Cell(); // Destructor
  Cell &operator=(const Cell &rhs);
  void setLiving(COLOR c = WHITE);         // Explicitly sets me to living.
  void setDied();
  void recalculate();       // Reassess my living-or-dead status, based on
                            // info from neighbours.

  void setCoords(int x, int y, int w, int h, Xwindow *Xw);
  bool IsAlive();
  void setCellType(char cellc =' ');
  void setNum(unsigned int number){ Cnum = number;};
  unsigned int getNum(){return Cnum;}
  void clearCell();
  friend std::ostream& ::operator<<(std::ostream &out, const Cell &c);
};

#endif

