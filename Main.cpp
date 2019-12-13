//MAIN
#include <iostream>
#include <cstring>
#include <iterator>
#include <iomanip>

using namespace std;
//12/9/19 Maggie Bao This is a program of sadness.
void add(int newvalue);
void print(Node* next);

Node* head = NULL;//if null checks if there is anything in the memory

int main() {
  add(5);
  print(head);
  add(7);
  print(head);
  add(2);
  print(head);
}

void add(int newvalue){
  Node* current = head;
  if (current == NULL){
    head = new Node();
    head->setValue(newvalue);
  }
  else {
    while (current->getNext() != NULL){
      current = current->getNext();
    }
    current->setNext(new Node());
    current->getNext()->setValue(newvalue);
  }
}

void print(Node* next){
  if (next == head){
    cout << "List:" << endl;
  }
  if (next == NULL){
    cout << next->getValue() << " ";
    print(next->getNext());
  }
}

    while (true){
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
