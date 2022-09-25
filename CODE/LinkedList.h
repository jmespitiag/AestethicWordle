#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "Node.h"
using namespace std;

class LinkedList{
    protected:
        Node* head;
        Node* tail;
        int length;
        string word;
    public:

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
                cout << head->letter << "->{" << head->color << "} ";
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
    
};
#endif
