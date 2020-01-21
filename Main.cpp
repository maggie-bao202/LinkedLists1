//MAIN
#include "node.h"
#include "Student.h"
#include <iostream>
#include <cstring>
#include <iterator>
#include <iomanip>

using namespace std;
//1/20/19 Author: Maggie Bao Description: Linked Lists (Part 2) prompts the user to enter a keyword. Typing "ADD" will prompt the user to enter the student information. "PRINT" shows the students that are in the list. "AVERAGE" takes the average of all the student's GPAs. "DELETE" prompts the user for a student id, then searches the list for the student GPA that matches. "QUIT" will terminate the program.
void add(Node* &head, Node* node, Student* student);
void print(Node* node);
void remove(Node* &head, Node* node, int id);
void average(Node* node, float counter, float total);
//if null checks if there is anything in the memory

int main() {
  Node* head = NULL;
  char keyword[10];
    while (true){
    cout << "Type in a keyword (\"ADD\", \"PRINT\",\"DELETE\", \"AVERAGE\", or \"QUIT\")"<<endl;
    cin.getline(keyword, 10, '\n'); //put into array of 10. Extra char will be ignored
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
      cin.clear();
      cin.ignore(999, '\n');
      while (id > 999999 || id < 100000){//student id must be 6 digits
	cout << "Enter a 6 digit number." << endl;
	cout << "Enter Student ID: ";
	cin >> id;
	cin.clear();
	cin.ignore(9999, '\n');
      }
      cout << "Enter GPA: ";
      cin >> gpa;
      cin.clear();
      cin.ignore(999, '\n');
      while (gpa > 5.0 || gpa == 0.0){//must be valid gpa
	cout << "GPA cannot exceed a 5.00, and cannot be 0.00." << endl;
	cout << "Enter GPA: ";
	cin >> gpa;
	cin.clear();
	cin.ignore(9999, '\n');
      }
      Student* current = new Student(fname, lname, id, gpa);//create a student with user inputted data
      add(head, head, current);//add student to node, to list
      cout << "Student Added." << endl;
      cout << endl;
    }
    else if (strcmp(keyword, "PRINT") == 0){
      cout << "Student List:" << endl;
      print(head);//pass through print function. Don't need to pass through reference because not altering list
      cout << endl;
    }
    else if (strcmp(keyword, "DELETE") == 0){
      int id = 0;
      cout << "Enter Student ID:" << endl;
      cin >> id;//prompt user for id
      remove(head, head, id);//remove the student with given id
      cin.clear();
      cin.ignore(999, '\n');
      cout << endl;
    }
    else if (strcmp(keyword, "AVERAGE") == 0){
      average(head, 0, 0);//starts off with counter and total at 0. Will iterate with each student
      cout << endl;
    }
    else if(strcmp(keyword, "QUIT") == 0){
      if(head == NULL){//if there is nothing in the list
	cout << "Have a nice day!" << endl;
	return 0;
      }
      while(head->getNext()!= NULL){//if student is not the head or the tail
	Node* temp = head->getNext();
	delete head;
	head = temp;
      }
      if(head->getNext() == NULL){//if last student in the list
	delete head;
	head = NULL;
	cout << "Have a nice day!" << endl;
	return 0; //close program
      }
    }
    else{
      cout << "Make sure the keyword is capitalized." << endl;
    }
  }
  return 0;
}

void add(Node* &head, Node* node, Student* student){//makes student into a node, adds it to the list
  if (node == NULL){//if there is nothing in the list
    Node* current = new Node(student);//create a node, make it the head
    head = current;
    return;
  }
  if (head->getStudent()->getId() > student->getId()){//if the student id is smaller than the head, then make new student the new head--before the previous head
    Node* current = new Node(student);
    current->setNext(head);
    head = current;
    return;
  }
  else if (node->getNext() == NULL){//if larger than the head, add node to the end of the list
    Node* current = new Node(student);
    node->setNext(current);
    return;
  }
  if (node->getStudent()->getId() < student->getId()
      && node->getNext()->getStudent()->getId() > student->getId()){//if the new student id falls between two nodes, add it in between them
    Node* current = new Node(student);
    Node* temp = node->getNext();
    node->setNext(current);
    current->setNext(temp);
    return;
  }
  add(head, node->getNext(), student);
}

void print(Node* node){//print the linked list out
  if (node == NULL){//if there is nothing in the list, print nothing. Also, if it is last node in linked list
    return;
  }
  node->getStudent()->print();//calling print function from student class
  print(node->getNext());//go to next node
}

void remove(Node* &head, Node* node, int id){//removes the student with matching id
  if (node->getStudent()->getId() == id){//if matching node is first node in list
    if (node == head) {
      Node* temp = head;
      head = head->getNext();//set the next node as the head
      delete temp;
      cout << "Student Removed." << endl;
      return;
    }
  }
  if (node->getNext()->getStudent()->getId() == id) {//if the next node is going to be deleted
    node->setNext(node->getNext()->getNext());//make the current node point to the next next node to connect them
    delete node->getNext();//delete the next node
    cout << "Student Removed." << endl;
    return;
  }
  remove(head, node->getNext(), id);
  return;
}

void average(Node* node, float counter, float total){//prints out the average of all the student GPAs
  if(node == NULL){//if the node is the last node in the list, calculate the average
    cout << setprecision(2) << fixed << total/counter << endl;
    return;
  }
  total += node->getStudent()->getGPA();//update the total with each new student
  counter++;//update the counter with each new student
    average(node->getNext(), counter, total);
}
