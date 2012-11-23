#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits>
#include <map>
#include <tr1/cstdint>
#include "grid.h"
#include "score.h"
#include "nextblk.h"
#include "trie.h"
#include "blkgen.h"
using namespace std;
int main(int argc, char *argv[]){
   string stype, sToken,s0,s1,line;
   string left="left",right="right",levelup="levelup",leveldown="leveldown",clockwise="clockwise",counterclockwise="counterclockwise",restart="restart",down="down",drop="drop";
   unsigned  num;
   string number= "0123456789";
   BLK_select genBlk;
   genBlk.resetPRNseed(time(NULL));
   bool guirun = true;
   int k = 1;
   if(argc>4){
     cout<< "Usage: " << argv[0] <<" [-text][-seed xxx]"<<endl;
     exit(EXIT_FAILURE);
   }
   switch(argc){
     case 1:
        guirun = true;
        break;
     case 2:
     case 3:
     case 4:
        while( k < argc){
          sToken = "-text";
          if(argv[k] == sToken){
             guirun = false;
          } else{
            sToken = "-seed"; 
            if(argv[k] == sToken){
               genBlk.resetPRNseed(atoi(argv[k+1]));
               k += 1;
            }
          }
          k += 1;
         }
         break;
    default:
         cout<<"Usage: "<<argv[0]<<" [-text]|[-seed xxx]" << endl;
         exit(EXIT_FAILURE);
  }
   Grid grid(guirun);
   grid.setBlkCoords(0, 0);
   NEXT_BLK next_blk(guirun, O);
// from partner
    Trie *t = new Trie;
    insert(t,"left");
    insert(t,"right");
    insert(t,"clockwise");
    insert(t,"counterclockwise");
    insert(t,"down");
    insert(t,"drop");
    insert(t,"levelup");
    insert(t,"leveldown");
    insert(t,"restart");
//
   map<string, BLKTYPE> bmap;
   bmap["I"] = I; bmap["S"] = S; bmap["Z"] = Z; bmap["L"] = L;
   bmap["J"] = J; bmap["T"] = T; bmap["O"] = O; grid.init();

     stype = genBlk.generator(grid.level); 
     grid.initBlk(bmap[stype]);
     stype = genBlk.generator(grid.level);
     next_blk.setBlkType(bmap[stype]);
    while(!cin.eof()){
       cout<<grid;
       cout<<next_blk;
loop:  getline(cin,line);
        string::size_type posn = line.find_first_of( number );
        if(posn == string::npos) {
	   if(line.length() == 0){
	     continue; 
	   }
	   posn = 0;
	   num = 1;
	}else{
           line = line.substr( posn ); //remove heading spaces
           posn = line.find_first_not_of( number );
	   s1 =line.substr(0, posn);
           num = atoi(s1.c_str());
	}
	line=line.substr(posn); //remove num at front of string
        posn = line.find_first_not_of(" "); //remove heading spaces
	if(posn == string::npos) continue;
        line = line.substr(posn); 
 if(line.substr(0,6)=="rename"){
        string ori,sub;
        istringstream sss(line.substr(7,line.length()-7));
        sss>>ori;
        if((ori=find(t, ori)) == "Command not found") {
            cerr<<ori<<" is invalid!"<<endl;
            goto loop;
        } 
        istringstream ssss(line.substr(7+ori.length(),line.length()-7-ori.length()));
        ssss>>sub;
        if(ori==left) left=sub;
        else if(ori==right) right=sub;
        else if(ori==down) down=sub;
        else if(ori==drop) drop=sub;
        else if(ori==levelup) levelup=sub;
        else if(ori==leveldown) leveldown=sub;
        else if(ori==clockwise) clockwise=sub;
        else if(ori==counterclockwise) counterclockwise=sub;
        else if(ori==restart) restart=sub;

        remove(t,ori);
        insert(t,sub);
        goto loop;
        }

     s1=find(t,line);
     posn = s1.find_last_not_of(" "); //find() has problem, it adds white space at end of returned string.
     if(posn != string::npos){
        s1 = s1.substr(0,posn+1);
     }
     if(s1=="Command not found"){
         cerr << "Invalid command"<<endl;
         goto loop;
     }
     if(s1.find(" ")!=string::npos){
        cout<<s1<<endl;
        cerr<<"Command is ambiguous"<<endl;
        goto loop;
     }
     istringstream ss(s1);
     ss>>s0;
     if(grid.isGameOver() && s0 !=restart){
        goto loop;
     }
     if(s0==left){
             grid.moveBlk(0, num);
      }
     else if(s0==right){
             grid.moveBlk(1, num);
          }
     else if(s0==clockwise){
             grid.rotateBlk(0, num);
          }
     else if(s0==counterclockwise){
             grid.rotateBlk(1, num);
          }
     else if(s0==down){
             grid.moveBlk(2, num);
          }
     else if(s0==drop){
             grid.dropDown();
      if(grid.isFull()){
         cout<<"Game Over!"<<endl;
         cout<<"Type \"restart\" to play again."<<endl;
         goto loop;
     } else {
      grid.initBlk(next_blk.getBlkType());
      stype = genBlk.generator(grid.level);
      next_blk.setBlkType(bmap[stype]);
      }
     }
     else if(s0==levelup){
          grid.levelup();
     }
     else if(s0==leveldown){
          grid.leveldown();
      }
        else if(s0 == restart){
        grid.init();
        stype = genBlk.generator(grid.level);
        grid.initBlk(bmap[stype]);
        stype = genBlk.generator(grid.level);
        next_blk.setBlkType(bmap[stype]);
     } 
  }
} //grid destructor ~Grid will be called to release mem allocated

