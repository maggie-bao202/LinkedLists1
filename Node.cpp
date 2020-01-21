//NODE.CPP FILE
//NOTE: the .o file was not working correctly, so I have created my own node.cpp file from Devin's code. it is pretty similar to my own; he just included 1 extra function setStudent. Might end up deleting this file later after I test in the lab
#include "Node.h"
#include <iostream>
using namespace std;

Node :: Node(Student* newstudent){
  student = newstudent;
  next = NULL;
}

Node :: ~Node(){
  delete student;
  next = NULL;
}

void Node :: setNext(Node* newnext){
  next = newnext;
}

Node* Node :: getNext(){
  return next;
}

Student* Node :: getStudent(){
  return student;
}

void Node :: setStudent(Student*){

}
