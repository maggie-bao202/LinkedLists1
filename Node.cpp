//NODE.CPP FILE
#include "Node.h"
Node :: Node(){
  value = 0;
  next = NULL;
}

Node :: ~Node(){
  delete &value;
  next = NULL;
}

void Node :: setValue(int newValue){
  value = newvalue;
}

int Node :: getValue(){
  return value;
}

void Node :: setNext(Node* newnext){
  next = newnext;
}

Node* Node :: getNext(){
  return next;
}
