//intlist.cpp
#include <iostream>
#include "intlist.h"
using namespace std;
using namespace Intlist;

intlist():
size(0), head(nullptr), tail(nullptr){};

void addnodeTohead(int element) {
  intNode* node = new intNode();
  node -> setElement(element);
  if (head == nullptr) {
    head = tail = node;
  } else node -> setNext(head);
    head = node
    size++
}
void addnodeTotail(int element) {
  intNode* node = new intNode();
  node -> setElement(element);
  if (head == nullptr) {
    head = tail = node;
  } else node -> setNext(head);
    tail = node
    size++
}
int getsize(){
/* code*/
}

void printElems() {
intnode* current = head;
while (current != nullptr) {
  cout << current ->getElement() << '\n';
  current = current -> getNext();
  }
}
