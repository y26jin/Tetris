#include <string>
#include <cstdlib>
#include <iostream>
#include <limits>
#include "cell.h"
#include "window.h"
using namespace std;

Cell::Cell(){
   isAlive = false;
   cell_c = ' ';
   Cnum = 0;
   cell_Color = WHITE;
}

Cell::~Cell(){
   return;
}

Cell &Cell::operator=(const Cell &rhs){
      isAlive=rhs.isAlive;
      cell_c = rhs.cell_c;
      Cnum = rhs.Cnum;
      cell_Color = rhs.cell_Color;
      width = rhs.width;
      height = rhs.height;
      Xwin = rhs.Xwin;
      draw();
      return *this;
}

void Cell::setLiving(COLOR c){
   if(! isAlive){
      isAlive = true;
      cell_Color = c;
   }
   draw();
  //if I am alive, do nothing
   return;
}

void Cell::setDied(){
   if(isAlive){
      isAlive = false;
     cell_Color = WHITE;
      undraw();
   }
   return;
}

bool Cell::IsAlive(){
   return(isAlive);
}
void Cell::recalculate(){
/*   if(!isAlive){
	 undraw();
   } 
   else{
	 draw();
      }
 */ 
} 
void Cell::setCellType(char  cellc){
  cell_c = cellc;
}

ostream& operator<<(ostream &out, const Cell &c){
   if(c.isAlive){
      out << c.cell_c;
   } else {
      out << " ";
   }
   return out;
}

void Cell::draw(){
  if(Xwin != NULL){
   Xwin->fillRectangle(x+1, y+1,
                              width-2, height-2,
//			      Xwindow::Black);
                             cell_Color);
  }
}

void Cell::undraw(){
 if(Xwin != NULL){
   Xwin->fillRectangle(x, y,
                              width, height,
                              Xwindow::White);
 }
}

void Cell::setCoords(int Xx, int Xy, int Xwidth, int Xheight, Xwindow *X){
   x = Xx, y = Xy, width = Xwidth, height = Xheight;
   Xwin = X;
   undraw();
}
