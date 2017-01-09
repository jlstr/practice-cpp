#include <iostream>
using namespace std;

void printMenu();

class Node {
  int data;

public:
  Node *next;

  Node() {
    next = NULL;
  }

  ~Node() {
    cout << "NODE WITH DATA: " << this->data << " DESTROYED" << endl;
  }

  void setData(int n) {
    data = n;
  }

  int getData() {
    return this->data;
  }
};

int listLength(Node*);
void printLinkedList(Node*);
void pushNode(Node*&, int data);
void destroyList(Node*);

int main() {
  printMenu();  
  int option;
  bool breakLoop = false;

  Node *head = new Node();
  head->setData(666);

  while (!breakLoop && cin >> option) {
    switch (option) {
      case 1:
        printLinkedList(head);
        break;
      case 2:
        int data;
        cout << "Node value? ";
        cin >> data;
        pushNode(head, data);
        break;
      case 3:
        destroyList(head);
        breakLoop = true;
        break;
      default:
        break;
    };

    if (!breakLoop) printMenu();
  }

  return 0;
}

void printMenu() {
  cout << endl;
  cout << "===============================================================================" << endl;
  cout << "\t" << "1. " << "Print Linked List" << endl;
  cout << "\t" << "2. " << "Add Node to Linked List" << endl;
  cout << "\t" << "3. " << "Exit" << endl;
  cout << "===============================================================================" << endl;
  cout << "\n" << "Select an option: ";
}


int listLength(Node *head) {
  int count = 0;
  Node *current = head;

  while (current != NULL) {
    count++;
    current = current->next;
  }

  return count;
}

void pushNode(Node* &head, int data) {
  Node *newNode = new Node();
  newNode->setData(data);
  newNode->next = head;
  head = newNode;
  //
  // Success
  //
  cout << "\n" << "Insert [ OK ]" << "\n" << endl;
}

void printLinkedList(Node *head) {
  Node *i = head;

  cout << endl;

  while (i != NULL) {
    cout << i->getData() << "\t" << " => ";
    i = i->next;
  }

  cout << " [END] ";
  cout << endl;
}

void destroyList(Node *head) {
  Node *current = head, *next = head;

  while (next != NULL) {
    next = current->next;
    delete current;
    current = next;
  }
}
