//NODE.H FILE
#ifdef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

void Node{
 public:
  Node();
  ~Node();
  void setValue(int newvalue);
  int getValue();
  void setNext(Node* newnext);
  Node* getNext();
 private:
  int value;
  Node* next;
};
#endif
