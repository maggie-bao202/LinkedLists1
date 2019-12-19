//STUDENT HEADER FILE
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student {
 public://functions of Student.h
  Student(char* newfname, char* newlname, int newid, float newgpa);//Constructor
  ~Student();//destructor
  char* getFname();//get first name
  char* getLname();//get last name
  int getId();
  float getGPA();
  void print();//print out the student information
  
 private: //variables are private
  char* fname;
  char* lname;
  int id;
  float gpa;
};
#endif
