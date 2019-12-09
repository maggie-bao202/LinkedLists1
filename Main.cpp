//MAIN
#include <iostream>
#include <cstring>
#include <iterator>
#include <iomanip>

using namespace std;
//12/9/19 Maggie Bao This is a program of sadness.
void addStudent();
void printStudent();
void deleteStudent();

int main() {
  while(true){
    cout << "Type in a keyword (\"ADD\", \"PRINT\",\"DELETE\", or \"QUIT\")"<<endl;
    cin.get(keyword, 10); //put into array of 10. Extra char will be ignored
    cin.clear(); //clear, ignore fixes null bug
    cin.ignore(9999, '\n');
    if (strcmp(keyword, "ADD") == 0){//if keyword char pointer matches with str
      addStudent();
    }
    else if (strcmp(keyword, "PRINT") == 0){
      printStudent();
    }
    else if (strcmp(keyword, "DELETE") == 0){
      deleteStudent();
    }
    else if(strcmp(keyword, "QUIT") == 0){
      cout << "Have a nice day!" << endl;
      return 0; //close program

    }
    else{
      cout << "Make sure the keyword is capitalized." << endl;
    }
  }
  return 0;
}
