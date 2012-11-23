#include <string>
#include <cstdlib>
#include <iostream>
#include <limits>
#include "nextblk.h"

#define BLK_width 80
#define BLK_height 130

using namespace std;

NEXT_BLK::NEXT_BLK(bool runGui, BLKTYPE t){
   blkType = t;
   if(runGui){
      Xblk = new Xwindow(BLK_width, BLK_height);
   } else {
      Xblk = NULL;
   }
}

NEXT_BLK::~NEXT_BLK(){
   if(Xblk != NULL){
      delete Xblk;
   }
}
void NEXT_BLK::draw (int x, int y,BLKTYPE t) const{
  int y1 = y;
  y1 += 10;
 if(Xblk != NULL){
   Xblk->drawString(x,y1,"Next:");
   y1 += 10;
   switch(t){
      case I:
        Xblk->fillRectangle(x, y1, 20, 80, Xwindow::Red);
        break;
      case S:
        Xblk->fillRectangle(x+20,y1+20, 40, 20,  Xwindow::Red);
        Xblk->fillRectangle(x,y1+40, 40, 20,  Xwindow::Red);
        break;
      case T:
         Xblk->fillRectangle(x+20, y1+20, 20,20, Xwindow::Red);
         Xblk->fillRectangle(x, y1+40, 60,20, Xwindow::Red);
         break;
      case L:
         Xblk->fillRectangle(x, y1+20,20,20, Xwindow::Red);
         Xblk->fillRectangle(x, y1+40,60,20, Xwindow::Red); 
         break;
      case J:
         Xblk->fillRectangle(x+40, y1+20,20,20, Xwindow::Red);
         Xblk->fillRectangle(x, y1+40,60,20, Xwindow::Red);
         break;
      case Z:
         Xblk->fillRectangle(x, y1+20,40,20, Xwindow::Red);
         Xblk->fillRectangle(x+20, y1+40,40,20, Xwindow::Red);
         break;
      case O:
         Xblk->fillRectangle(x, y1+20,40,40, Xwindow::Red);
         break;
      default:
         break;
   }
 }
}

void NEXT_BLK::undraw() const{
 if(Xblk != NULL){
   Xblk->fillRectangle(0, 0,
                              BLK_width, BLK_height,
                              Xwindow::White);
 }
}
ostream &operator<<(ostream &out, const NEXT_BLK &nblk){
   int x = 10, y = 20;
   out<<"-----------------"<<endl;
   nblk.undraw();
   switch(nblk.blkType){
       case I:
           out<<"I"<<endl;
           out<<"I"<<endl;
           out<<"I"<<endl;
           out<<"I"<<endl;
           nblk.draw(x,y,I);
           break;
       case S:
           out<<" SS"<<endl;
           out<<"SS  "<<endl;
           nblk.draw(x,y,S);
           break;
       case T:
           out<<" T "<<endl;
           out<<"TTT"<<endl;
           nblk.draw(x,y,T);
           break;
       case L:
           out<<"L  "<<endl;
           out<<"LLL"<<endl;
           nblk.draw(x,y,L);
           break;
       case J:
           out<<"  J"<<endl;
           out<<"JJJ"<<endl;
           nblk.draw(x,y,J);
           break;
       case Z:
           out<<"ZZ "<<endl;
	   out<<" ZZ"<<endl;
           nblk.draw(x,y,Z);
	   break;
       case O:
           out<<"OO"<<endl;
	   out<<"OO"<<endl;
           nblk.draw(x,y,O);
	   break;
       default:
           out<<"Not defined!"<<endl;
   }
   return out;

}
