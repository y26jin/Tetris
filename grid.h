#ifndef __GRID_H__
#define __GRID_H__
#include <iostream>
#include <map>
#include "cell.h"
#include "Block.h"
#include "score.h"
#define glines  18
#define gcolumns 10
#define Xscore_width 4
#define Xscore_height 3
enum LINE_STATUS {LINE_FULL=0, LINE_EMPTY, LINE_NOT_FULL};
class Grid : public Score{
  Cell **theGrid;  // The actual grid.
  int gridWidth;    // Size of the grid.
  int gridHeight;
  std::map<int,int> blk_vs_cnt;
  std::map<int,int> blk_vs_level;
  unsigned int BlkUniqNo;
  bool GameOver;
  int blkX, blkY;
  Blocks *blks;

  void clearGrid();   // Frees the grid.
  
  Xwindow *Xw;
  Xwindow *Xscore;
 public:
  Grid(bool runGui);
  ~Grid();

  void init(); // Sets up an n x n grid.  Clears old grid, if necessary.
                    // Initializes every cell in the grid, and tells each
                    // cell who its neighbours are.
  
  void tick();      // Runs one iteration of the simulation.
                    // Tells each cell to alert its neighbours, and then
                    // tells each cell to recalculate.

  void turnOn(int i, int j, BLKTYPE cellc, COLOR c = WHITE);  // Sets cell at i, j to living.
  void GturnOn(int i, int j );
  void turnOff(int i, int j);
  void setBlkCoords(int x, int y);
  bool moveBlk(int i, int steps = 1);
  void rotateBlk(int direction, int steps = 1);
  void dropDown();
  void initBlk(BLKTYPE t = S);
  bool isFull();
  LINE_STATUS lineStatus(unsigned int lineNum);
  void Remove_Score(unsigned int lineNum);
  void updateGridandScore();
  bool isGameOver();
  friend std::ostream& ::operator<<(std::ostream &out, const Grid &g);
};

#endif

