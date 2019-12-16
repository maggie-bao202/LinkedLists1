//MAIN
#include "Node.h"
#include "Student.h"
#include <iostream>
#include <cstring>
#include <iterator>
#include <iomanip>

using namespace std;
//12/9/19 Maggie Bao This is a program of sadness.
void add(Node &head, Node* node, Student* student);
void print(Node* node);
void remove(Node* &head, Node* node);

//if null checks if there is anything in the memory

int main() {
  Node* head = NULL; 
    while (true){
    cout << "Type in a keyword (\"ADD\", \"PRINT\",\"DELETE\", or \"QUIT\")"<<endl;
    cin.get(keyword, 10); //put into array of 10. Extra char will be ignored
    cin.clear(); //clear, ignore fixes null bug
    cin.ignore(9999, '\n');
    if (strcmp(keyword, "ADD") == 0){//if keyword char pointer matches with str
      char* fname = new char(40);
      char* lname = new char(40);
      int id = 0;
      float gpa = 0;
      cout << "Enter First Name:" << endl;
      cin.getline(fname, 40);
      cout << "Enter Last Name:" << endl;
      cin.getline(lname, 40);
      cout << "Enter Student ID:"<< endl;
      cin >> id;
      cin.ignore();
      cout << "Enter GPA:"<< endl;
      cin >> gpa;
      cin >> ignore();
      Student* current = new Student(fname, lname, id, gpa);
      add(head, head, current);
    }
    else if (strcmp(keyword, "PRINT") == 0){
      print(head);
    }
    else if (strcmp(keyword, "DELETE") == 0){
      int id = 0;
      cout << "Enter Student ID:" << endl;
      cin >> id;
      remove(head, head, id);
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

void add(Node* &head, Node* node, Student* student){
  if (node == NULL){
    Node* current = new Node(student);
    head = current;
    return;
  }
  if (node->getNext() == NULL){
    Node* current = new Node(student);
    node->setNext(current);
    return;
  }
  add(head, node->getNext(), student);
}

void print(Node* node){
  if (node == NULL){
    return;
  }
  node->getStudent()->print();
  cout << endl;
  print(node->getNext());
}

void remove(Node* &head, Node* node, int id){
  if (node->getStudent()->getId() == id){
    if (node == head) {
      Node* temp = head;
      head = head->getNext();
      delete temp;
      return;
    }
  }
 if (node->getNext()->getStudent()->getId() == id) {
    node->setNext(node->getNext()->getNext());
    delete node->getNext();
    return;
  }
  remove(head, node->getNext(), id);
}
