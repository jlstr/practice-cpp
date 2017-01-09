#include <iostream>
using namespace std;

void printMenu() {
  cout << endl;
  cout << "===============================================================================" << endl;
  cout << "\t" << "1. " << "Push element" << endl;
  cout << "\t" << "2. " << "Pop Element" << endl;
  cout << "\t" << "3. " << "Exit" << endl;
  cout << "===============================================================================" << endl;
  cout << "\n" << "Select an option: ";
}

struct Stack {
  int top;
  int capacity;
  int *array;
  ~Stack() {
    cout << "\n" << "Stack destroyed!" << endl;
  };
};

Stack* createStack();
bool empty(Stack*&);
bool full(Stack*&);
void push(Stack*&, int);
int pop(Stack*&);
void destroy(Stack*&);

int main() {

  printMenu();  
  int option;
  bool breakLoop = false;

  Stack *stack = createStack();


  while (!breakLoop && cin >> option) {
    switch (option) {
      case 1:
        int data;
        cout << "Element value: ";
        cin >> data;
        push(stack, data);
        break;
      case 2:
        int popped;
        popped = pop(stack);
        cout << "\n" << popped << " was popped!" << endl;
        break;
      case 3:
        destroy(stack);
        breakLoop = true;
        break;
      default:
        break;
    };

    if (!breakLoop) printMenu();
  }


  return 0;
}


Stack* createStack() {
  Stack *stack = new Stack();
  stack->capacity = 2;
  stack->top = -1;
  stack->array = new int[stack->capacity];

  return stack;
}

bool empty(Stack* &stack) {
  return stack->top == -1;
}

bool full(Stack* &stack) {
  return stack->top == stack->capacity - 1;
}

void push(Stack* &stack, int data) {
  if (full(stack)) {
    cout << "\n" << "Stack Full!" << endl;
    return;
  } else
    stack->array[++stack->top] = data;
}

int pop(Stack* &stack) {
  if (empty(stack)) {
    cout << "\n" << "Stack is Empty!" << endl;
    return 0;
  } else
    return stack->array[stack->top--];
}

void destroy(Stack* &stack) {
  delete stack->array;
  delete stack;
}

