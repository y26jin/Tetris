#ifndef _BLOCK_H_
#define _BLOCK_H_
#include "cell.h"
struct POS {int x; int y;};

struct rCollisions{
             int size;
             POS *posPtr;
           };

struct CollisionPos{
        rCollisions rClkW;
        rCollisions rCntW;
};

// collision points for I block when rotate.
extern bool I_Block0[4][1];
extern bool I_Block1[1][4];
extern POS I_ClkWPos0[9];
extern POS I_CntWPos0[6];
extern POS I_ClkWPos1[9];
extern POS I_CntWPos1[12];
extern CollisionPos I_ColliPos0;
extern CollisionPos I_ColliPos1;

// S-Block;

extern bool S_Block0[2][3];
extern bool S_Block1[3][2];
extern POS S_ClkWPos0[3];
extern POS S_CntWPos0[4];
extern POS S_ClkWPos1[4];
extern POS S_CntWPos1[3];
extern CollisionPos S_ColliPos0;
extern CollisionPos S_ColliPos1;

// J-Block;

extern bool J_Block0[2][3];
extern bool J_Block1[3][2];
extern bool J_Block2[2][3];
extern bool J_Block3[3][2];
extern POS J_ClkWPos0[4];
extern POS J_CntWPos0[5];
extern POS J_ClkWPos1[4];
extern POS J_CntWPos1[3];
extern POS J_ClkWPos2[4];
extern POS J_CntWPos2[4];
extern POS J_ClkWPos3[4];
extern POS J_CntWPos3[4];
extern CollisionPos J_ColliPos0;
extern CollisionPos J_ColliPos1;
extern CollisionPos J_ColliPos2;
extern CollisionPos J_ColliPos3;

// L-Block


extern bool L_Block0[2][3];
extern bool L_Block1[3][2];
extern bool L_Block2[2][3];
extern bool L_Block3[3][2];
extern POS L_ClkWPos0[4];
extern POS L_CntWPos0[4];
extern POS L_ClkWPos1[5];
extern POS L_CntWPos1[3];
extern POS L_ClkWPos2[5];
extern POS L_CntWPos2[5];
extern POS L_ClkWPos3[4];
extern POS L_CntWPos3[4];
extern CollisionPos L_ColliPos0;
extern CollisionPos L_ColliPos1;
extern CollisionPos L_ColliPos2;
extern CollisionPos L_ColliPos3;

// T-Block

extern bool T_Block0[2][3];
extern bool T_Block1[3][2];
extern bool T_Block2[2][3];
extern bool T_Block3[3][2];
extern POS T_ClkWPos0[2];
extern POS T_CntWPos0[4];
extern POS T_ClkWPos1[5];
extern POS T_CntWPos1[3];
extern POS T_ClkWPos2[4];
extern POS T_CntWPos2[5];
extern POS T_ClkWPos3[2];
extern POS T_CntWPos3[4];
extern CollisionPos T_ColliPos0;
extern CollisionPos T_ColliPos1;
extern CollisionPos T_ColliPos2;
extern CollisionPos T_ColliPos3;

// Z-Block

extern bool Z_Block0[2][3];
extern bool Z_Block1[3][2];
extern POS Z_ClkWPos0[3];
extern POS Z_CntWPos0[4];
extern POS Z_ClkWPos1[5];
extern POS Z_CntWPos1[4];
extern CollisionPos Z_ColliPos0;
extern CollisionPos Z_ColliPos1;

// O-Block

extern bool O_Block0[2][2];
extern bool O_Block1[2][2];
extern POS O_ClkWPos0[1];
extern POS O_CntWPos0[1];
extern POS O_ClkWPos1[1];
extern POS O_CntWPos1[1];
extern CollisionPos O_ColliPos0;
extern CollisionPos O_ColliPos1;

class Block{
 void clearBlk();
 public:
   Block();
   ~Block();
   int width;
   int height;
   bool *B[4];
   CollisionPos *collisions;
};

   enum BLKTYPE { I, J, L, O, S, Z, T, SPACE };
   //enum BCOLOR {RED,ORANGE, YELLOW, GREEN, GREY, BLUE, PURPLE};

class Blocks{
   BLKTYPE BType;
   COLOR bcolor;
   int BlkNum;
   int curBlk;
   Block *blkRotate[4];

   void clearBlks();
 public:
   Blocks();
   ~Blocks();
   void blkBuild(BLKTYPE t = I);
   BLKTYPE getBlkType();
   Block *getCurBlk();
   void nextBlk();
   void previousBlk();
   COLOR getBlkColor(){return bcolor;};

};

#endif //_BLOCK_H_
