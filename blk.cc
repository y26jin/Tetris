#include "Block.h"
//I-Block --  collision points for I block when rotate.
bool I_Block0[4][1] = {{true},{true},{true},{true}};
bool I_Block1[1][4] = {{true,true,true, true}};
POS I_ClkWPos0[9] = {{0,1},{0,2},{0,3},{1,1},{1,2},{1,3}, {2,1},{2,2},{2,3}};
POS I_CntWPos0[6] = {{0,1},{1,1},{1,2},{2,1},{2,2},{2,3}};
POS I_CntWPos1[12] = {{0,0},{0,1}, {0,2},{0,3},{1,0}, {1,1},{1,2},{1,3},{2,0},{2,1},{2,2},{2,3}};
POS I_ClkWPos1[9] = {{0,0},{0,1},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2},{2,3}};
CollisionPos I_ColliPos0 = {{9, I_ClkWPos0}, {6, I_CntWPos0} };
CollisionPos I_ColliPos1 = {{9, I_ClkWPos1}, {12, I_CntWPos1} };
Block I_Blk0, I_Blk1;

//S-Block

bool S_Block0[2][3] = { {false, true, true},
                        {true, true, false}};
bool S_Block1[3][2] = { {true, false},
                        {true, true},
			{false, true}};
POS S_ClkWPos0[3] = {{0,0},{1,0},{2,2}};
POS S_CntWPos0[4] = {{0,0},{0,1},{0,2},{1,0}};
POS S_ClkWPos1[4] = {{0,1},{0,2},{1,2},{2,0}};
POS S_CntWPos1[3] = {{1,2},{2,0},{2,2}};
CollisionPos S_ColliPos0 = {{3, S_ClkWPos0}, {4,S_CntWPos0}};
CollisionPos S_ColliPos1 = {{4, S_ClkWPos1}, {3,S_CntWPos1}};
Block S_Blk0, S_Blk1;

//J-Block

bool J_Block0[2][3] = { {false, false, true},
                        {true, true, true}
		      };
bool J_Block1[3][2] = { {true, false},
                        {true, false},
                        {true, true}
		      };
bool J_Block2[2][3] ={ {true, true, true},
                        {true, false, false}
                      };
bool J_Block3[3][2] = { {true, true},
                        {false, true},
                        {false, true}
                      };
POS J_ClkWPos0[4] = {{0,0},{0,1},{1,0},{1,1}};
POS J_CntWPos0[5] = {{0,0},{0,1},{0,2},{1,0},{1,1}};
POS J_ClkWPos1[4] = {{0,1},{0,2},{1,2},{1,2}};
POS J_CntWPos1[3] = {{0,1},{1,1},{2,2}};
POS J_ClkWPos2[4] = {{0,0},{0,1},{2,1},{2,2}};
POS J_CntWPos2[4] = {{0,0},{0,1},{0,2},{2,1}};
POS J_ClkWPos3[4] = {{0,2},{1,2},{2,2},{2,0}};
POS J_CntWPos3[4] = {{1,0},{1,2},{2,0},{2,2}};
CollisionPos J_ColliPos0 = {{4, J_ClkWPos0}, {5, J_CntWPos0}};
CollisionPos J_ColliPos1 = {{4, J_ClkWPos1}, {3, J_CntWPos1}};
CollisionPos J_ColliPos2 = {{4, J_ClkWPos2}, {4, J_CntWPos2}};
CollisionPos J_ColliPos3 = {{4, J_ClkWPos3}, {4,  J_CntWPos3}};
Block J_Blk0, J_Blk1, J_Blk2, J_Blk3;

//L-Block

bool L_Block0[2][3] = { {true, false, false},
                        {true, true, true}
                      };
bool L_Block1[3][2] = { {true, true},
                        {true, false},
                        {true, false}
                      };
bool L_Block2[2][3] ={ {true, true, true},
                        {false, false, true}
                      };
bool L_Block3[3][2] = { {false, true},
                        {false, true},
                        {true, true}
                      };
POS L_ClkWPos0[4] = {{0,0},{0,1},{1,1},{1,2}};
POS L_CntWPos0[4] = {{0,1},{0,2},{1,1},{1,2}};
POS L_ClkWPos1[5] = {{0,2},{1,1},{1,2},{2,1},{2,2}};
POS L_CntWPos1[3] = {{1,1},{2,1},{2,2}};
POS L_ClkWPos2[5] = {{0,0},{0,1},{0,2},{2,0},{2,1}};
POS L_CntWPos2[5] = {{0,0},{0,1},{0,2},{2,0},{2,1}};
POS L_ClkWPos3[4] = {{0,1},{1,0},{1,1},{2,0}};
POS L_CntWPos3[4] = {{0,0},{0,1},{1,0},{1,1}};
CollisionPos L_ColliPos0 = {{4, L_ClkWPos0}, {4, L_CntWPos0}};
CollisionPos L_ColliPos1 = {{5, L_ClkWPos1}, {3, L_CntWPos1}};
CollisionPos L_ColliPos2 = {{5, L_ClkWPos2}, {5, L_CntWPos2}};
CollisionPos L_ColliPos3 = {{4, L_ClkWPos3}, {4, L_CntWPos3}};
Block L_Blk0, L_Blk1, L_Blk2, L_Blk3;

//T-Block

bool T_Block0[2][3] = { {false, true, false},
                        {true, true, true}
                      };
bool T_Block1[3][2] = { {true, false},
                        {true, true},
                        {true, false}
                      };
bool T_Block2[2][3] ={ {true, true, true},
                        {false, true,false}
                      };
bool T_Block3[3][2] = { {false, true},
                        {true, true},
                        {false, true}
                      };
POS T_ClkWPos0[2] = {{0,0},{1,0}};
POS T_CntWPos0[4] = {{0,1}, {0,2},{1,0},{1,2}};
POS T_ClkWPos1[5] = {{0,1},{0,2},{1,2},{2,1},{2,2}};
POS T_CntWPos1[3] = {{0,1},{2,1},{2,2}};
POS T_ClkWPos2[4] = {{0,0},{0,1},{2,0},{2,2}};
POS T_CntWPos2[5] = {{0,0},{0,1},{0,2},{2,0},{2,2}};
POS T_ClkWPos3[2] = {{2,0},{2,1}};
POS T_CntWPos3[4] = {{0,0},{0,1},{1,0},{2,1}};
CollisionPos T_ColliPos0 = {{2, T_ClkWPos0}, {4, T_CntWPos0}};
CollisionPos T_ColliPos1 = {{5, T_ClkWPos1}, {3, T_CntWPos1}};
CollisionPos T_ColliPos2 = {{4, T_ClkWPos2}, {5, T_CntWPos2}};
CollisionPos T_ColliPos3 = {{2, T_ClkWPos3}, {4, T_CntWPos3}};
Block T_Blk0, T_Blk1, T_Blk2, T_Blk3;

//Z-Block

bool Z_Block0[2][3] = { {true, true,false},
                        {false, true, true}};
bool Z_Block1[3][2] = { {false, true},
                        {true, true},
                        {true, false}};
POS Z_ClkWPos0[3] = {{0,0},{0,1},{2,0}};
POS Z_CntWPos0[4] = {{0,1},{0,2},{1,2},{2,0}};
POS Z_ClkWPos1[5] = {{0,0},{0,2},{1,2},{2,1},{2,2}};
POS Z_CntWPos1[4] = {{0,0},{1,2},{2,1},{2,2}};
CollisionPos Z_ColliPos0 = {{3, Z_ClkWPos0}, {4,Z_CntWPos0}};
CollisionPos Z_ColliPos1 = {{5, Z_ClkWPos1}, {4,Z_CntWPos1}};
Block Z_Blk0, Z_Blk1;

// O-Block

bool O_Block0[2][2] = { {true, true},
                        {true, true}
		      };
bool O_Block1[2][2] = { {true, true},
                        {true, true}
	              };
POS O_ClkWPos0[1] = {{0,0}};
POS O_CntWPos0[1] = {{0,0}};
POS O_ClkWPos1[1] = {{0,0}};
POS O_CntWPos1[1] = {{0,0}};
CollisionPos O_ColliPos0 = {{1, O_ClkWPos0}, {1,O_CntWPos0}};
CollisionPos O_ColliPos1 = {{1, O_ClkWPos1}, {1,O_CntWPos1}};
Block O_Blk0, O_Blk1;

