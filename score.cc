#include <string>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <cmath>
#include "score.h"

using namespace std;

Score::Score(){
   height = 0;
   width =0;
   level=0;
   x=y=0;
   score = 0;
   hiScore = 0;
}

void Score::resetScore(){
   level=0;
   score = 0;
}

void Score::addLineScore(unsigned int numOflines){
   if(numOflines > 0){
      score += pow((numOflines + level), 2);
      hiScore =(hiScore > score)? hiScore:score;
   }
}

void Score::additionalScore(unsigned int forLevel){
  score += pow((forLevel + 1), 2);
  hiScore = (hiScore > score) ?  hiScore:score;
}

void Score::levelup(){
   if(level<3){
      level += 1;
   }
}

void Score::leveldown(){
   if(level>0){
      level -= 1;
   }
}

ostream &operator<<(ostream &out, const Score &s){
   out <<"Level:"<<"\t\t"<<s.level<<endl;
   out <<"Score:"<<"\t\t"<<s.score<<endl;
   out <<"Hi Score:"<<"\t"<<s.hiScore<<endl;
   out <<"-----------------"<<endl;
   return out;
}


