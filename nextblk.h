#ifndef _NEXTBLK_H_
#define _NEXTBLK_H_
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include "Block.h"
class NEXT_BLK {
   BLKTYPE blkType;
   Xwindow *Xblk;
   void draw(int x, int y, BLKTYPE t) const;
   void undraw() const;
public:
   NEXT_BLK(bool runGui, BLKTYPE t = I);
   ~NEXT_BLK();
   void setBlkType(BLKTYPE t){blkType=t;};
   BLKTYPE getBlkType(){return blkType;};
   friend std::ostream& ::operator<<(std::ostream &out,  const NEXT_BLK &nblk);
};
#endif
