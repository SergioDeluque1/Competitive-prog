//intlist.h
#ifndef INTLIST_H
#define INTLIST_H
#include "intnode.h"

class intlist {
  private:
    int size;
    IntNode* head;
    IntNode* tail;

  public:
  intlist();

  void addnodeTohead(int element);
  void addnodeTotail(int element);
  void deleteHeadNode();

  int getsize();

  void printElems();

};
#endif
