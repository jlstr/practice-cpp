#include <iostream>
#include <string>
using namespace std;

void printMenu() {
  cout << endl;
  cout << "===============================================================================" << endl;
  cout << "\t" << "1. " << "Push element" << endl;
  cout << "\t" << "2. " << "Pop Element" << endl;
  cout << "\t" << "3. " << "Evaluate expression" << endl;
  cout << "\t" << "4. " << "Exit" << endl;
  cout << "===============================================================================" << endl;
  cout << "\n" << "Select an option: ";
}

struct Stack {
  int top;
  int capacity;
  char *array;
};

Stack* createStack();
bool full(Stack*&);
void doubleStack(Stack*&);
void push(Stack*&, char);
bool empty(Stack*&);
char top(Stack*&);
char pop(Stack*&);
//
bool evaluateString(string);

int main() {

  printMenu();  
  int option;
  bool breakLoop = false;

  Stack *stack = createStack();
  // for symbol balance evaluation
  string expression = "";

  while (!breakLoop && cin >> option) {
    switch (option) {

      case 1:
        char data;
        cout << "Element value: ";
        cin >> data;
        push(stack, data);
        break;

      case 2:
        char popped;
        popped = pop(stack);
        if (popped != '\0')
          cout << "\n" << popped << " was popped!" << endl;
        else cout << "\n\t" << "Empty Stack" << endl;
        break;

      case 3: {
        cout << "\n\nEnter expression: ";
        cin.ignore(); // Required for switch!
        getline(cin, expression);
        // Let's eval this motherfucker!
        bool balanced = evaluateString(expression);
        cout << "\nExpression: " << expression << " is " << (balanced ? "" : "Not ") << "balanced" << endl;
        break;
      }

      case 4:
        //
        //destroy(stack);
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
  stack->capacity = 1;
  stack->top = -1;
  stack->array = new char[stack->capacity];

  return stack;
}

bool full(Stack* &stack) {
  return stack->top == (stack->capacity - 1);
}

void doubleStack(Stack* &stack) {
  cout << "\n\t" << "----> Doubling Stack!" << endl;

  char *tmp = stack->array;
  stack->capacity *= 2;
  stack->array = new char[stack->capacity];

  int i = 0;
  for (; i < stack->capacity/2; ++i) {
    stack->array[i] = tmp[i];
  }
}

void push(Stack* &stack, char data) {
  if (full(stack)) doubleStack(stack);
  stack->array[++stack->top] = data;
}

bool empty(Stack* &stack) {
  return stack->top == -1;
}

char top(Stack* &stack) {
  if (empty(stack))
    return '\0';
  else return stack->array[stack->top];
}

char pop(Stack* &stack) {
  if (empty(stack))
    return '\0';
  else return stack->array[stack->top--];
}

bool evaluateString(string expression) {
  Stack *stack = createStack();

  for(string::iterator i = expression.begin(); i != expression.end(); ++i) {
    char c = *i;

    if (c == '(' || c == '[' || c == '{')
      push(stack, c);
    else if (c == ')' || c == ']' || c == '}') {
      if (empty(stack)) return false;
      char popped = pop(stack);
      switch(c) {
        case ')':
          if (popped != '(') return false;
          break;
        case ']':
          if (popped != '[') return false;
          break;
        case '}':
          if (popped != '{') return false;
          break;
      };
    }
  } // end loop
  
  return empty(stack);
}
