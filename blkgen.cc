#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <tr1/cstdint>
#include "blkgen.h"
#include "Block.h"
#include "PRNG.h"
using namespace std;
string BLK_select::generator(int level){
	int num,temp;
        string strTemp;
    string stat[7]={"S","Z","I","T","O","L","J"};
        if(level == 0){
            if(infile != NULL){
	        *infile>>strTemp;
      		if(infile->fail()){
         		if(infile->eof()){
           		   infile->clear();
                           infile->seekg(0, ios::beg);//got it from web. it can reset stream.
                           *infile>>strTemp;
         	         }
                         else {
                           infile->clear();
                           infile->seekg(0, ios::beg); //got it from web. it can reset stream.
                           *infile>>strTemp;
                         }
      	        }
                return(strTemp);
             } else {
                 cerr<<"Can not open sequence.txt file!"<<endl;
                 exit(EXIT_FAILURE);
              }
         }
               
	if(level==1){
		num=(*p)()%12;
		if(num<2) temp=num;
		else{
			if(num%2==0) temp=num/2+1;
			else temp=(num+1)/2;
		}
	}
	else if(level==2){
	       num=(*p)()%7;
		   temp=num;
	}
	else if(level==3){
		num=(*p)()%9;
		if(num>3) temp=num-2;
		else{
			if(num%2==0) temp=num/2;
			else temp=(num-1)/2;
		}
		
	}
    return stat[temp];

}

void BLK_select:: resetPRNseed(uint32_t s){
   p->seed(s);
   return;
}
void BLK_select::set_result(BLKTYPE x){
	result=x;
}
BLKTYPE BLK_select::get_result(){
	return result;
}
BLK_select::BLK_select(){
   infile = new ifstream("sequence.txt");
   if(infile->fail()){
      cerr<<"Cannot open sequence.txt"<<endl;
      exit(EXIT_FAILURE);
   }   
   p = new PRNG;
}
BLK_select::~BLK_select(){
   if(p != NULL){
       delete p;
    }
   if(infile != NULL){
      infile->close();
      delete infile;
   }
} 
