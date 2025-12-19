#ifndef INTQUEUE_H
#define INTQUEUE_H
##include "intnode.h"

class intqueue{
  private:
    int element;
    intnode* next
  public:
    //constructor
    intqueue();
    //destuctor
    ~intqueue();
    //setters
    void enqueue(int element);
    void dequeue();
    int peek();

  
};
#endif
