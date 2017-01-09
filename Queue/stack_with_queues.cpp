#include "Queue.h"
#include <iostream>
using namespace std;

void printMenu() {
  cout << endl;
  cout << "===============================================================================" << endl;
  cout << "\t" << "1. " << "Push" << endl;
  cout << "\t" << "2. " << "Pop" << endl;
  cout << "\t" << "3. " << "Exit" << endl;
  cout << "===============================================================================" << endl;
  cout << "\n" << "Select an option: ";
}

struct Stack {
  Queue *q1;
  Queue *q2;

  Stack() {
    this->q1 = createQueue();
    this->q2 = createQueue();
  }
};

void push(Stack*&, int);
int pop(Stack*&);

int main() {

  printMenu();  
  int option;
  bool breakLoop = false;

  Stack *stack = new Stack();

  while (!breakLoop && cin >> option) {
    switch (option) {
      case 1: {
        int data;
        cout << "\n" << "Enter value: ";
        cin >> data;
        push(stack, data);
        break;
      }
      case 2:
        cout << pop(stack) << endl;
        break;
      case 3:
        breakLoop = true;
        break;
      default:
        break;
    };

    if (!breakLoop) printMenu();
  }
  return 0;
}


void push(Stack* &stack, int data) {
  if (empty(stack->q1))
    enQueue(stack->q2, data);
  else
    enQueue(stack->q1, data);
}

int pop(Stack* &stack) {
  
  if (empty(stack->q1)) {
    int queueSize = size(stack->q2);
    for (int i = 0; i < queueSize - 1; ++i) {
      enQueue(stack->q1, deQueue(stack->q2));
    }
    return deQueue(stack->q2);
  } else {
    int queueSize = size(stack->q1);
    for (int i = 0; i < queueSize - 1; ++i) {
      enQueue(stack->q2, deQueue(stack->q1));
    }
    return deQueue(stack->q1);
  }
}
