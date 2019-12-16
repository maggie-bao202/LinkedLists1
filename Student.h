//STUDENT HEADER FILE
#ifdef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student {
 public:
  Student(char* newfname, char* newlname, int newid, float newgpa);
  ~Student();
  char* getFname();
  char* getLname();
  int getId();
  float getGPA():
  void print();
  
 private:
  char* fname;
  char* lname;
  int id;
  float gpa;
};
#endif
