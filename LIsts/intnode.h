// intnode.h
#ifndef INTNODE_H
#define INTNODE_H

class IntNode {
private:
  int element;
  IntNode* next;

public:
  // constructor
  IntNode();
  IntNode (int element);
  // setter
void setElement (int element);
void setNext (IntNode* next);
// getter
int getElement();
IntNode* getNext();
};
#endif
