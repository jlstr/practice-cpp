#include <iostream>
#include <string>
using namespace std;

void printMenu() {
  cout << endl;
  cout << "===============================================================================" << endl;
  cout << "\t" << "1. " << "Convert to postfix" << endl;
  cout << "\t" << "2. " << "Exit" << endl;
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
string toPostfix(string);

bool isSign(int);
bool isOperand(int);
bool isLeftParenthesis(int);
bool isRightParenthesis(int);

int main() {
  printMenu();  
  int option;
  bool breakLoop = false;


  while (!breakLoop && cin >> option) {
    switch (option) {

      case 1: {
        string expression;
        cout << "Enter expression: ";
        cin >> expression;
        string result = toPostfix(expression);
        cin.ignore();
        cout << "\n\tResult: " << result << endl;
        break;
      }
      case 2:
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

string toPostfix(string expression) {
  // resulting infix string
  string result = "";
  string::iterator i = expression.begin();

  // Stack to execute algorithm on
  Stack *stack = createStack();

  while (i != expression.end()) {
    if (isOperand(*i))
      result += *i;

    else if (isRightParenthesis(*i)) {
      while (!empty(stack)) {
        char popped = pop(stack);
        if (!isLeftParenthesis(popped))
          result += popped;
      };
    } else {
      if (isSign(*i) || isLeftParenthesis(*i)) {
        while (!empty(stack)) {
          char topOfStack = top(stack);
          
          if (isLeftParenthesis(topOfStack)) break;
          else if (isSign(topOfStack) || isOperand(topOfStack)) result += pop(stack);
        };

        push(stack, *i);
      }
    }

    ++i;
  };

  while (!empty(stack)) {
    result += pop(stack);
  };

  return result;
}

bool isSign(int asciiValue) {
  if (asciiValue >= 42 && asciiValue < 46)
    return true;
  else
    return false;
}

bool isOperand(int asciiValue) {
    if ((asciiValue >= 65 && asciiValue < 91) || (asciiValue >= 97 && asciiValue < 123))
    return true;
  else
    return false;
}

bool isLeftParenthesis(int asciiValue) {
  if (asciiValue == 40)
    return true;
  else
    return false;
}

bool isRightParenthesis(int asciiValue) {
  if (asciiValue == 41)
    return true;
  else
    return false;
}
