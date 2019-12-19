//NODE HEADER FILE
#include <iostream>
#include "Student.h"

using namespace std;

class Node{
 public://functions of Node
  Node(Student* newstudent);//Constructor
  ~Node();//Destructor
  void setNext(Node* newnext);//next node
  Node* getNext();
  Student* getStudent();
 private://variables of Node
  Student* student;
  Node* next;
};
