//NODE.H FILE
#include <iostream>
#include "Student.h"

using namespace std;

class Node{
 public:
  Node(Student* newstudent);
  ~Node();
  void setNext(Node* newnext);
  Node* getNext();
  Student* getStudent();
 private:
  Student* student;
  Node* next;
};
