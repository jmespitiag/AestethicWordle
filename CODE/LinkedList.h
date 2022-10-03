#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "Node.h"
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
using namespace std;

class LinkedList{
    protected:
        Node* head;
        Node* tail;
        int length;
        string word;
    public:

      string getWord(){
        return this->word;
      }

        int getLength(){
          return this->length;
        }
        Node* getHead(){
          return this->head;
        }
        int Length(Node* head)
        {
            if(head == NULL)
            {
                return 0;
            }
            else{return 1+Length(head->next);}
        }
        Node* Tail(Node* head)
        {
            if(head->next == NULL)
            {
                return head;
            }
            else{return Tail(head->next);}
        }

        LinkedList(){}
        LinkedList(string w, Node* n)
        {
            this->head=n;
            this->word=w;
            this->tail=Tail(n);
            this->length=Length(n);
        }

        void insertNewNode(Node** head, char l) 
        {
            Node* node = newNode(l);
            Node* temp = newNode('x');
            if (*head == NULL) 
            {*head = node;}
            else {temp = *head;};
            while (temp->next != NULL) 
            {
                temp = temp->next;
            }
            temp->next = node;
        }
        void printLinkedList() 
        {
            Node* head = this->head;
            while (head != NULL) 
            {
              
                if (head->color=="NEGRO")
                {
                  printf("\033[1;30m%c\033[0m ", head->letter);
                }
                if (head->color=="AMARILLO")
                {
                  printf("\033[1;33m%c\033[0m ", head->letter);
                }
              if (head->color=="VERDE")
                {
                 printf("\033[1;32m%c\033[0m ", head->letter);
                }
              if (head->color=="ROJO")
                {
                 printf("\033[1;31m%c\033[0m ", head->letter);
                }
                head = head->next;
            }
        }
        LinkedList createLinkedList(string w, int n) {
            Node *head = NULL;
            for (int i = 0; i < n; i++) {
                insertNewNode(&head, w[i]);
            }
            return LinkedList(w, head);
        }

     LinkedList compareList(LinkedList a, LinkedList b, Node* current, int posa=1){
    if (current == NULL){
      return a;
    }
    else{
      Node* current2 = b.getHead();
      int posb = 1;
      while(current2 != NULL){
        if ((posa == posb) && (current->getLetter() == current2->getLetter())){
          current->setColor("VERDE");

        }
        else if(current->getLetter() == current2->getLetter()){
            if (current->getColor() != "VERDE")
            {
                current->setColor("AMARILLO");
            }
        }
        current2 = current2->next;
        posb = posb + 1;
      }
      return compareList(a,b,current->getNext(),posa+1);
    }
    
  }

     
     bool verifyLinkedList() {
         Node* head = this->head;
         while (head != NULL)
         {
             if (head->color != "VERDE")
             {
                 return false;
             }
             else { head = head->next; }
         }
         return true;
     }

    LinkedList loseLinkedList(Node* head){
      Node* originalhead = head;
      while(head != NULL){
        head->setColor("ROJO");
        head = head->getNext();
      }
      LinkedList l1 = LinkedList("", originalhead);
      return l1;
    }
    
    int howMany(string w,int i){
      char letter = w[i];
      int count = 0;
      for(int j = 0; j<w.length(); j++){
        if (w[j] == letter){
          count = count+1;
        }
      }
      return count;
    }

    int greenMany(LinkedList a, Node* current, string w, int i){
      char letter = w[i];
      int times = 0;
      while(current!=NULL){
        if((current->letter == letter)&&(current->color == "VERDE")){
          times = times+1;
          
        }
        current = current->next;
      }
      return times;
    }

LinkedList compareList2(LinkedList a, LinkedList b, Node* current){
    string toGuess = b.getWord();
    for(int i = 0; i<toGuess.length(); i++){
      LinkedList list = LinkedList();
      char letter = toGuess[i];
      int times = list.howMany(toGuess,i);
      int greenOnes = list.greenMany(a,current,toGuess,i);
      if(times == greenOnes){
        while(current != NULL){
          if((current->letter == letter)&&(current->color != "VERDE")){
            current->color = "NEGRO";
          }
          current = current->next;
      }
      
        }
      }
      return a;
  
    }
  

    
};
#endif
