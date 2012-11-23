#ifndef __TRIE_H__
#define __TRIE_H__
#include <iostream>
#include <string>

struct Trie {
       bool isWord;
       Trie *letters[27];
       Trie();
       ~Trie();
       };

int judge_char(std::string s);
std::string turn_string(int n);
bool judge_null(Trie *node);
void insert(Trie *node, std::string word);
void remove( Trie *node, std::string word );
std::string find( Trie *node, std::string word );
int word_counter(std::string s);
#endif
      
