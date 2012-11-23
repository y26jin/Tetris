#include <string>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>
#include "Block.h"
#include "grid.h"
#include "window.h"
using namespace std;
Grid::Grid(bool runGui){
   theGrid = NULL;
   blkX = 0;
   blkY = 0;
   blks = NULL;
   BlkUniqNo = 0;
   GameOver = false;
   if(runGui){
      Xw = new Xwindow(gcolumns*X_width, glines*X_width);
      Xscore = new Xwindow(Xscore_width*X_width, Xscore_height*X_width);
   }else{
      Xw = NULL;
      Xscore = NULL;
   }

}
void Grid::clearGrid(){
   for(int i = 0; i < glines; i++){
      delete [] theGrid[i]; //delete a line; 
   }
   delete  [] theGrid;
   //theGrid == NULL;
   blkX=0;
   blkY=0;
   if(blks != NULL){
      delete blks;
   }
   blks = NULL;
   GameOver = false;
}

Grid::~Grid(){
   clearGrid();
   if(Xscore != NULL){
     delete Xscore;
     delete Xw;
   }
}

void Grid::init(){
   if(theGrid != NULL){ // clear old grid
      //delete theGrid; //~Grid would be invorked;
      clearGrid();
   }
    
   theGrid = new Cell*[glines]; //allocate n pointer first
   for(int i=0;i<glines;i++){    // allocate n Cells for n pointers
      theGrid[i] = new Cell[gcolumns];
   }

   for(int i =0 ; i< glines; i++){
      for(int j = 0 ; j < gcolumns; j++){
         theGrid[i][j].setCoords(j*X_width, i*X_width, X_width, X_width, Xw);
      }
   }
   Score::resetScore();
   blk_vs_cnt.clear();
   blk_vs_level.clear();
}

void Grid::initBlk(BLKTYPE t){
  if(blks != NULL){
     delete blks;
  }
  blks = new Blocks;
  blks->blkBuild(t);
  setBlkCoords(0,0);
  BlkUniqNo += 1;
  GameOver = false;
  tick();
}
void Grid::tick(){
   Block *blkP = blks->getCurBlk();
   for(int i = 0; i < blkP->height; i++){
      for(int j = 0; j < blkP->width; j++){
         if(blkP->B[i][j]){
	    turnOn(i, j, blks->getBlkType(),blks->getBlkColor());
	 }
	 else{
	   //turnOff(i, j);
	 }
      }
   }

   for(int i = 0; i < glines; i ++){
      for(int j = 0; j < gcolumns; j++){
         theGrid[i][j].recalculate();
      }
   }
}
void Grid::turnOn(int i, int j, BLKTYPE cellType, COLOR c){
   Block *blkP = blks->getCurBlk();
   char cellc = ' ';
   if(i < glines && j < gcolumns){
      switch(cellType){
        case I:
	   cellc = 'I';
	   break;
	case S:
	   cellc = 'S';
	   break;
	case J:
	   cellc = 'J';
	   break;
	case L:
	   cellc = 'L';
	   break;
	case T:
	   cellc = 'T';
	   break;
	case Z:
	   cellc = 'Z';
	   break;
	case O:
	   cellc = 'O';
	   break;
	case SPACE:
	   break;
     }
	     
      theGrid[i+blkX+4-blkP->height][j+blkY].setCellType(cellc);
      theGrid[i+blkX+4-blkP->height][j+blkY].setLiving(c);
   }
}

void Grid::turnOff(int i, int j){
   Block *blkP = blks->getCurBlk();
   if(i < glines && j < gcolumns){
         theGrid[i+blkX+4-blkP->height][j+blkY].setDied();
   }
}


ostream &operator<<(ostream &out, const Grid &g){
   out <<"Level:"<<"\t\t"<<g.level<<endl;
   out <<"Score:"<<"\t\t"<<g.score<<endl;
   out <<"Hi Score:"<<"\t"<<g.hiScore<<endl;
   out <<"-----------------"<<endl;
   if(g.Xscore != NULL){
      string msg, cleanmsg;
      stringstream xss;
 //have to clean Score Board first for re-writting.
      g.Xscore->fillRectangle(0, 0,
                              Xscore_width*X_width, Xscore_height*X_width,
                              Xwindow::White);
      xss.clear();
      xss.str("");
      xss<<g.level;
      msg = "Level:          " + xss.str();
      g.Xscore->drawString(10, 30, msg);
      xss.clear();
      xss.str("");
      xss<<g.score;
      msg = "Score:          " + xss.str();
      g.Xscore->drawString(10, 60, msg);
      xss.clear();
      xss.str("");
      xss<<g.hiScore;
      msg = "Hi Score:       " + xss.str();
      g.Xscore->drawString(10, 90, msg);
   } 
   for(int i = 0; i < glines; i++){
      for(int j = 0; j < gcolumns; j ++){
         out<<g.theGrid[i][j];
      }
      out<<endl;
   }
   return out;
}

void Grid::setBlkCoords(int x, int y){
   blkX = x, blkY =y;
   return;
}

bool Grid::moveBlk(int direction, int steps){
   bool cantMove = false; 
   Block *blkP = blks->getCurBlk();
 for(int s = 0; s < steps ; s++){
   for(int i = 0; i < blkP->height; i++){
      for(int j = 0; j < blkP->width; j++){
         if(blkP->B[i][j]){
            turnOff(i, j);
         }
      }
   }
   switch(direction){
      case 0:
         if(blkY > 0){
	    blkY -= 1;
	    for(int i =0 ; i < blkP->height; i++){
	       for(int j = 0; j < blkP->width; j++){
	          if(theGrid[i+blkX+4-blkP->height][blkY+j].IsAlive()
	          && blkP->B[i][j]){
	             blkY += 1;
		     cantMove = true;
                     break; 
		  }
	       }
	       if(cantMove) break;
	    }
	 }
	 break;
      case 1:
         if(blkY + blkP->width < gcolumns){
            blkY += 1;
	    for(int i = 0; i < blkP->height; i++){
	       for(int j = 0; j < blkP->width; j++){
	          if(theGrid[i+blkX+4-blkP->height][blkY+j].IsAlive()
		     && blkP->B[i][j]){
	                blkY -= 1;
			cantMove = true;
	                break;
		  }
	       }
	       if(cantMove) break;
	    }
         }
	 break;
      case 2:
         if(blkX + 4< glines){ //
	    blkX += 1;
	    for(int i = 0; i < blkP->height; i++){
	       for(int j = 0; j < blkP->width; j++){
	          if(theGrid[i+blkX+4-blkP->height][blkY+j].IsAlive()
	           && blkP->B[i][j]){
		      blkX -= 1;
		      cantMove = true;
		      break;
		  }
	       }
	       if(cantMove) break;
	    }
	 }else{
	    cantMove = true;
	 }
         if(cantMove){ //set block uniq number accordinglly.
             for(int i=0;i<blkP->height; i++){
                for(int j =0;j<blkP->width; j++){
                  if(blkP->B[i][j]){
                     theGrid[i+blkX+4-blkP->height][blkY+j].setNum(BlkUniqNo);
                  }
                }
             }
         }
	 break;
      default:
          return false;
   }
   tick();
 }
 return(!cantMove);
}

void Grid::dropDown(){
   while(moveBlk(2));
   blk_vs_cnt.insert(pair<int, int>(BlkUniqNo, 4)); //each block has 4 cells
   blk_vs_level.insert(pair<int,int>(BlkUniqNo, level)); //
   updateGridandScore();
}

void Grid::rotateBlk(int direction, int steps){
   Block *blkP = blks->getCurBlk();
   int offH;
   for(int i = 0 ; i <steps; i++){
   offH=(blkP->width > blkP->height ? blkP->width:blkP->height);
   for(int i = 0; i < blkP->height; i++){
      for(int j = 0; j < blkP->width; j++){
         if(blkP->B[i][j]){
            turnOff(i, j);
         }
      }
   }

   if(direction == 0){
      for(int i = 0; i <blkP->collisions->rClkW.size; i++){
         if(blkX+4-offH+blkP->collisions->rClkW.posPtr[i].x>glines
	    || blkY+blkP->collisions->rClkW.posPtr[i].y>gcolumns
	    || theGrid[blkX+4-offH+blkP->collisions->rClkW.posPtr[i].x]
                   [blkY+blkP->collisions->rClkW.posPtr[i].y].IsAlive()){
             tick();
             return;
         }
      }
       blks->nextBlk();
       blkP = blks->getCurBlk();
       if(blkY + blkP->width > gcolumns){
         blks->previousBlk();
      }
   } else {
      for(int i = 0; i < blkP->collisions->rCntW.size; i++){
         if(blkX+4-offH+blkP->collisions->rCntW.posPtr[i].x>glines
            || blkY+blkP->collisions->rCntW.posPtr[i].y>gcolumns
            || theGrid[blkX+4-offH+blkP->collisions->rCntW.posPtr[i].x]
                   [blkY+blkP->collisions->rCntW.posPtr[i].y].IsAlive()){
		   tick();
		   return;
         }

      }
      blks->previousBlk();
   }
   tick();
  }
}

void Grid::GturnOn(int j, int i){
   if(i < glines && j < gcolumns){
      theGrid[i][j].setLiving(RED);
   }
}

bool Grid::isFull(){
   for(int i = 0;i < 3;i++){
     if(theGrid[3][i].IsAlive()){
        return true;
     }
   }
   GameOver = true;
   return false;
}

LINE_STATUS Grid::lineStatus(unsigned int lineNum){
   int lineCnt =0;
   if(lineNum<4) return LINE_EMPTY;
   for(int i = 0; i < gcolumns; i++){
      if(theGrid[lineNum][i].IsAlive()){
         lineCnt += 1;
      }
   }
  if(lineCnt == gcolumns) return LINE_FULL;
  if(lineCnt < gcolumns && lineCnt > 0) return LINE_NOT_FULL;
  return LINE_EMPTY;
} 

void Grid::Remove_Score(unsigned int lineNum){
   int tmpI;
      for(int i=0; i < gcolumns; i++){
        tmpI = theGrid[lineNum][i].getNum();
        blk_vs_cnt[tmpI] -= 1;
        if(blk_vs_cnt[tmpI] == 0){
          additionalScore(blk_vs_level[tmpI]);
          blk_vs_cnt.erase(tmpI);
          blk_vs_level.erase(tmpI);
        }
        theGrid[lineNum][i].setDied();
     }
}

  
void Grid::updateGridandScore(){
   int line, tmpline;
   int rmLineNo = 0;
   line = glines - 1;
   while(line > 3){
      if(lineStatus(line) == LINE_FULL){
         Remove_Score(line);
         rmLineNo += 1;
         tmpline = line;
         do{
            for(int j = 0; j < gcolumns; j++){
                theGrid[tmpline][j] = theGrid[tmpline - 1][j];
            }
            tmpline -= 1;
         } while(lineStatus(tmpline) != LINE_EMPTY);
      } else { 
         if(lineStatus(line) == LINE_NOT_FULL){
           line -= 1;
           continue; 
         } else { //LINE_EMPTY
            break;
         }
     }
  }
  addLineScore(rmLineNo);
}

bool Grid::isGameOver(){
  return(GameOver);
}
