//STUDENT.CPP FILE
#include "Student.h"
#include <iomanip>
#include <iostream>

using namespace std;

Student :: Student(char* newfname, char* newlname, int newid, float newgpa){//constructor, need to pass through student's data
  fname = newfname;
  lname = newlname;
  id = newid;
  gpa = newgpa;
}

Student :: ~Student(){//destructor
  delete fname;
  delete lname;
}

//getters
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

void Student :: print(){//print out the student information 
  cout << fname << " " << lname << ", " << id << ", " << fixed << setprecision(2) << gpa << endl;
}
