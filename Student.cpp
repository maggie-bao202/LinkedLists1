//STUDENT.CPP FILE
#include "Student.h"
#include <iomanip>
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

float Student :: getGPA(){
  return gpa;
}

void Student :: print(){
  cout << fname << " " << lname << ", " << id << ", " << fixed << setprecision(2) << gpa << endl;
}
