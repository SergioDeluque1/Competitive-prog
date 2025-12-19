//listmain.cpp
#include <iostream>
#include "intlist.h"
using namespace std;
//using namespace Intlist;

int main() {
  cout << "using data structure list" << '\n';
  intlist myList;
  myList.addnodeTohead(3);
  myList.addnodeTohead(5);
  myList.printElems();
  cout << "list size: " << myList.getsize() << '\n';
  cout << '\n';
  myList.addnodeTotail(4);
  myList.addnodeTotail(7);
  myList.printElems();
  return 0;
}
