//STUDENT.CPP FILE
#include "Student.h"
#include <iostream>

using namespace std;

Student :: Student(char* newfname, char* newlname, int newid, float newgpa){
  fname = newfname;
  lname = newlname;
  id = newid;
  gpa = newgpa;
}

Student :: ~Student(){
  delete fname;
  delete lname;
}

char* Student :: getFname(){
  return fname;
}

char* Student :: getLname(){
  return lname;
}

int Student :: getId(){
  return id;
}

float Student :: getGpa(){
  return gpa;
}

void Student :: print(){
  cout << "Name: " << fname << " " << endl;
  cout << "ID: " << id << endl;
  cout << "GPA: " << gpa << endl;
}
