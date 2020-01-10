//MAIN
#include "Node.h"
#include "Student.h"
#include <iostream>
#include <cstring>
#include <iterator>
#include <iomanip>

using namespace std;
//12/9/19 Maggie Bao This is a program of sadness.
void add(Node* &head, Node* node, Student* student);
void print(Node* node);
void remove(Node* &head, Node* node, int id);

//if null checks if there is anything in the memory

int main() {
  Node* head = NULL;
  char keyword[10];
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
      cout << "Enter First Name: ";
      cin.getline(fname, 40, '\n');
      cout << "Enter Last Name: ";
      cin.getline(lname, 40, '\n');
      cout << "Enter Student ID: ";
      cin >> id;
      while (id > 999999 || id < 100000){
	cout << "Enter a 6 digit number." << endl;
	cout << "Enter Student ID: ";
	cin >> id;
	cin.clear();
	cin.ignore(9999, '\n');
      }
      cout << "Enter GPA: ";
      cin >> gpa;
      while (gpa > 5.0 || gpa < 0.0){
	cout << "GPA cannot exceed a 5.00, and cannot be 0.00." << endl;
	cout << "Enter GPA: ";
	cin >> gpa;
	cin.clear();
	cin.ignore(9999, '\n');
      }
      Student* current = new Student(fname, lname, id, gpa);
      add(head, head, current);
      cout << "Student Added." << endl;
      cout << endl;
    }
    else if (strcmp(keyword, "PRINT") == 0){
      cout << "Student List:" << endl;
      print(head);
      cout << endl;
    }
    else if (strcmp(keyword, "DELETE") == 0){
      int id = 0;
      cout << "Enter Student ID:" << endl;
      cin >> id;
      remove(head, head, id);
      cin.clear();
      cin.ignore(999, '\n');
      cout << endl;
    }
    else if(strcmp(keyword, "QUIT") == 0){
      cout << "Have a nice day!" << endl;
      return 0; //close program

    }
    else{
      cout << "Make sure the keyword is capitalized." << endl;
    }
    cin.clear();//debugging to make header not print twice
    cin.ignore(9999,'\n');
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
  print(node->getNext());
}

void remove(Node* &head, Node* node, int id){
  if (node->getStudent()->getId() == id){
    if (node == head) {
      Node* temp = head;
      head = head->getNext();
      delete temp;
      cout << "Student Removed." << endl;
      return;
    }
  }
  if (!(node->getStudent()->getId()) == id){
    cout << "Invalid ID." << endl;
    return;
 }
 if (node->getNext()->getStudent()->getId() == id) {
    node->setNext(node->getNext()->getNext());
    delete node->getNext();
    cout << "Student Removed." << endl;
    return;
  }
 if (!(node->getNext()->getStudent()->getId()) == id){
   cout << "Invalid ID." << endl;
   return;
 }
  remove(head, node->getNext(), id);
  return;
}
