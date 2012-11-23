#ifndef _SCORE_H_
#define _SCORE_H_
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
struct Score {
   int width;
   int height;
   int x, y;
   int level;
   int score;
   int hiScore;
   Score();
   void addLineScore(unsigned int lineNum);
   void additionalScore(unsigned int forLevel);
   void resetScore();
   void levelup();
   void leveldown();
 
  friend std::ostream& ::operator<<(std::ostream &out, const Score &s);
};
#endif
