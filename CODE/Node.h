#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;
  
struct Node {
   char letter;
   string color;
   Node* next;
  Node* getNext(){
    return this->next;
  }
  void setColor(string c){
    this->color = c;
  }
  char getLetter(){
    return this->letter;
  }
    string getColor(){
      return this->color;
    }
  
  
};
struct Node* newNode(char l) {
   Node* node = new Node;
   node->color = "NEGRO";
   node->letter = l;
   node->next = NULL;
   return node;
};

#endif