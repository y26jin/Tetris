#include <iostream>
#include <string>
#include <sstream>
#include "trie.h"
using namespace std;
Trie::Trie(){
 isWord=false;
 int i;
 for(i=0;i<27;i++){letters[i]=NULL;}
 }
Trie::~Trie(){
 int i;
 for(i=0;i<27;i++){
   if(letters[i]) delete letters[i];
   }             
 }
int judge_char(std::string s){
    return ((int)s.c_str()[0])-97;
    }
std::string turn_string(int n){
    stringstream ss;
    string s;
    char c=97+n;
    ss<<c;
    ss>>s;
    return s;
    }

bool judge_null(Trie *node){
     int i;
     Trie *temp=node;
     for(i=0;i<27;i++){
       if(temp->letters[i]!=NULL) break;
      }
     if(i==27) return true;
     else return false;
     }
void insert(Trie *node,std::string word){
     unsigned int i=0;
     Trie *m=node,*temp;
     if(word!=""){
       while(i!=word.length()){
         if(m->letters[judge_char(word.substr(i,1))]==NULL){
            temp = new Trie;
            m->letters[judge_char(word.substr(i,1))]=temp;
            m=temp;
           }
         else{
            temp=m->letters[judge_char(word.substr(i,1))];
            m=temp;         
         }
         i++;
        }
       m->isWord=true;
      }
     }
void remove( Trie *node, std::string word ){
     unsigned int i=0;
     Trie *m=node,*temp;
     while(i!=word.length()){
       temp=m->letters[judge_char(word.substr(i,1))];
       m=temp;
       i++;
       }
     m->isWord=false;
     }
std::string find( Trie *node, std::string word ){
      unsigned int i=0,j=0;
      string s="",errorsss="Command not found";
      Trie *m=node;
      Trie *temp;
      while(i!=word.length()){
	   if(m->letters[judge_char(word.substr(i,1))]!=NULL){	  
        temp=m->letters[judge_char(word.substr(i,1))];
        m=temp;
        i++;}
        else break;
      }
      
      if(i!=word.length()) return errorsss;
      
      if(judge_null(m)){
         if(m->isWord) s.append(word);
         return s;
      }
       else{    
             string s1;
             if(m->isWord) s.append(word);
             for(j=0;j<27;j++){
                s1=word;
                if(m->letters[j]!=NULL){
                    if(m->letters[j]->isWord){
                       s1.append(turn_string(j));
                       s.append(find(node,s1));
                       s.append(" ");
                                               }
                    else{
                         s1.append(turn_string(j));
                         s.append(find(node,s1));
                         }                
                                          }
                               }
             return s;
             }
      
     }
     
     
int word_counter(std::string s){
	istringstream a(s);
	int temp=0;
	std::string x;
	while(!a.fail()){
		a>>x;
		temp++;
		}
	return temp-1;
	}
