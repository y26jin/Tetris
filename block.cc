#include <string>
#include <cstdlib>
#include <iostream>
#include <limits>
#include "Block.h"
using namespace std;

extern Block I_Blk0;
extern Block I_Blk1;
extern Block S_Blk0;
extern Block S_Blk1;

extern Block J_Blk0;
extern Block J_Blk1;
extern Block J_Blk2;
extern Block J_Blk3;

extern Block L_Blk0;
extern Block L_Blk1;
extern Block L_Blk2;
extern Block L_Blk3;

extern Block T_Blk0;
extern Block T_Blk1;
extern Block T_Blk2;
extern Block T_Blk3;

extern Block Z_Blk0;
extern Block Z_Blk1;

extern Block O_Blk0;
extern Block O_Blk1;

Block::Block(){
   width = 0;
   height =0;
   B[0] = NULL;
   B[1] = NULL;
   B[2] = NULL;
//   bUniqNum = 0;
}

void Block::clearBlk(){
   for(int i = 0 ; i < width; i++){
//      delete [] B[i];
   }
//   delete [] B;
}
Block::~Block(){
   clearBlk();
}

void Blocks::blkBuild(BLKTYPE t){
   switch(t){
      case I :
	 blkRotate[0] = &I_Blk0;
	 blkRotate[1] = &I_Blk1;
         blkRotate[0]->width = 1;
         blkRotate[0]->height = 4;
         blkRotate[0]->B[0]= I_Block0[0];
	 blkRotate[0]->B[1]= I_Block0[1];
	 blkRotate[0]->B[2]= I_Block0[2];
	 blkRotate[0]->B[3]= I_Block0[3];
	 blkRotate[0]->collisions = &I_ColliPos0;
         blkRotate[1]->width = 4;
         blkRotate[1]->height = 1;
         blkRotate[1]->B[0] = I_Block1[0];
         blkRotate[1]->collisions = &I_ColliPos1;
         BlkNum = 2;
         curBlk = 0;
         BType = I;
         bcolor = GREEN;
         break;
      case S:
         blkRotate[0] = &S_Blk0;
         blkRotate[1] = &S_Blk1;
         blkRotate[0]->width = 3;
         blkRotate[0]->height = 2;
         blkRotate[0]->B[0]= S_Block0[0];
         blkRotate[0]->B[1]= S_Block0[1];
         blkRotate[0]->collisions = &S_ColliPos0;
         blkRotate[1]->width = 2;
         blkRotate[1]->height = 3;
         blkRotate[1]->B[0] = S_Block1[0];
         blkRotate[1]->B[1] = S_Block1[1];
         blkRotate[1]->B[2] = S_Block1[2];
         blkRotate[1]->collisions = &S_ColliPos1;
         BlkNum = 2;
         curBlk = 0;
         BType = S;
         bcolor = BLACK;
         break;
      case J:
         blkRotate[0] = &J_Blk0;
	 blkRotate[1] = &J_Blk1;
	 blkRotate[2] = &J_Blk2;
	 blkRotate[3] = &J_Blk3;
	 blkRotate[0]->width = 3;
	 blkRotate[0]->height = 2;
         blkRotate[0]->B[0]= J_Block0[0];
         blkRotate[0]->B[1]= J_Block0[1];
	 blkRotate[0]->collisions = &J_ColliPos0;
         blkRotate[1]->width = 2;
	 blkRotate[1]->height = 3;
         blkRotate[1]->B[0] = J_Block1[0];
	 blkRotate[1]->B[1] = J_Block1[1];
	 blkRotate[1]->B[2] = J_Block1[2];
	 blkRotate[1]->collisions = &J_ColliPos1;
	 blkRotate[2]->width = 3;
	 blkRotate[2]->height = 2;
         blkRotate[2]->B[0] = J_Block2[0];
	 blkRotate[2]->B[1] = J_Block2[1];
	 blkRotate[2]->collisions = &J_ColliPos2;
	 blkRotate[3]->width = 2;
	 blkRotate[3]->height = 3;
         blkRotate[3]->B[0] = J_Block3[0];
	 blkRotate[3]->B[1] = J_Block3[1];
	 blkRotate[3]->B[2] = J_Block3[2];
	 blkRotate[3]->collisions = &J_ColliPos3;
	 BlkNum = 4;
	 curBlk = 0;
	 BType = J;
	 bcolor = BLUE;
	 break;
      case L:
         blkRotate[0] = &L_Blk0;
         blkRotate[1] = &L_Blk1;
         blkRotate[2] = &L_Blk2;
         blkRotate[3] = &L_Blk3;
         blkRotate[0]->width = 3;
         blkRotate[0]->height = 2;
         blkRotate[0]->B[0]= L_Block0[0];
         blkRotate[0]->B[1]= L_Block0[1];
         blkRotate[0]->collisions = &L_ColliPos0;
         blkRotate[1]->width = 2;
         blkRotate[1]->height = 3;
         blkRotate[1]->B[0] = L_Block1[0];
         blkRotate[1]->B[1] = L_Block1[1];
         blkRotate[1]->B[2] = L_Block1[2];
         blkRotate[1]->collisions = &L_ColliPos1;
         blkRotate[2]->width = 3;
         blkRotate[2]->height = 2;
         blkRotate[2]->B[0] = L_Block2[0];
         blkRotate[2]->B[1] = L_Block2[1];
         blkRotate[2]->collisions = &L_ColliPos2;
         blkRotate[3]->width = 2;
         blkRotate[3]->height = 3;
         blkRotate[3]->B[0] = L_Block3[0];
         blkRotate[3]->B[1] = L_Block3[1];
         blkRotate[3]->B[2] = L_Block3[2];
         blkRotate[3]->collisions = &L_ColliPos3;
         BlkNum = 4;
         curBlk = 0;
         BType = L;
         bcolor = RED;
         break;

      case T:
         blkRotate[0] = &T_Blk0;
         blkRotate[1] = &T_Blk1;
         blkRotate[2] = &T_Blk2;
         blkRotate[3] = &T_Blk3;
         blkRotate[0]->width = 3;
         blkRotate[0]->height = 2;
         blkRotate[0]->B[0]= T_Block0[0];
         blkRotate[0]->B[1]= T_Block0[1];
         blkRotate[0]->collisions = &T_ColliPos0;
         blkRotate[1]->width = 2;
         blkRotate[1]->height = 3;
         blkRotate[1]->B[0] = T_Block1[0];
         blkRotate[1]->B[1] = T_Block1[1];
         blkRotate[1]->B[2] = T_Block1[2];
         blkRotate[1]->collisions = &T_ColliPos1;
         blkRotate[2]->width = 3;
         blkRotate[2]->height = 2;
         blkRotate[2]->B[0] = T_Block2[0];
         blkRotate[2]->B[1] = T_Block2[1];
         blkRotate[2]->collisions = &T_ColliPos2;
         blkRotate[3]->width = 2;
         blkRotate[3]->height = 3;
         blkRotate[3]->B[0] = T_Block3[0];
         blkRotate[3]->B[1] = T_Block3[1];
         blkRotate[3]->B[2] = T_Block3[2];
         blkRotate[3]->collisions = &T_ColliPos3;
         BlkNum = 4;
         curBlk = 0;
         BType = T;
         bcolor = CYAN;
         break;
      case Z:
         blkRotate[0] = &Z_Blk0;
         blkRotate[1] = &Z_Blk1;
         blkRotate[0]->width = 3;
         blkRotate[0]->height = 2;
         blkRotate[0]->B[0]= Z_Block0[0];
         blkRotate[0]->B[1]= Z_Block0[1];
         blkRotate[0]->collisions = &Z_ColliPos0;
         blkRotate[1]->width = 2;
         blkRotate[1]->height = 3;
         blkRotate[1]->B[0] = Z_Block1[0];
         blkRotate[1]->B[1] = Z_Block1[1];
         blkRotate[1]->B[2] = Z_Block1[2];
         blkRotate[1]->collisions = &Z_ColliPos1;
         BlkNum = 2;
         curBlk = 0;
         BType = Z;
         bcolor = MAGENTA;
         break;
      case O:
         blkRotate[0] = &O_Blk0;
	 blkRotate[1] = &O_Blk1;
         blkRotate[0]->width = 2;
         blkRotate[0]->height = 2;
         blkRotate[0]->B[0]= O_Block0[0];
         blkRotate[0]->B[1]= O_Block0[1];
         blkRotate[0]->collisions = &O_ColliPos0;
         blkRotate[1]->width = 2;
         blkRotate[1]->height = 2;
         blkRotate[1]->B[0] = O_Block1[0];
         blkRotate[1]->B[1] = O_Block1[1];
         blkRotate[1]->collisions = &O_ColliPos1;
         BlkNum = 2;
         curBlk = 0;
         BType = O;
         bcolor = ORANGE;
         break;
    case SPACE:
         break;

   }
}

Blocks::Blocks(){
   BType = I;
   BlkNum = curBlk = 0;
   blkRotate[0]=blkRotate[1] = blkRotate[2]= blkRotate[3]= blkRotate[4] = NULL;
   bcolor = RED;
}

void Blocks::clearBlks(){
   if(blkRotate != NULL){
//      delete [] blkRotate;
   }
}

Blocks::~Blocks(){
   clearBlks();
}

BLKTYPE Blocks::getBlkType(){
    return(BType);
}

Block *Blocks::getCurBlk(){
   return(blkRotate[curBlk]);
}

void Blocks::nextBlk(){
   if(curBlk + 1 < BlkNum){
      curBlk += 1;
   } else {
     curBlk = 0;
   }
} 

void Blocks::previousBlk(){
   if(curBlk == 0){
      curBlk = BlkNum - 1;
   } else {
      curBlk -= 1;
   }
}
