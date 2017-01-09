#include <iostream>
#include "Stack.h"
using namespace std;

void reverseStack(Stack*&);
void insertAtBottom(Stack*&, char);

int main() {
  Stack *stack = createStack();
  push(stack, 'a');
  push(stack, 'b');
  push(stack, 'c');

  while (!empty(stack)) {
    cout << pop(stack) << endl;
  }

  return 0;
}

void reverseStack(Stack* &stack) {
  if (empty(stack))
    return;

  char data = pop(stack);
  reverseStack(stack);
  insertAtBottom(stack, data);
}

void insertAtBottom(Stack* &stack, char data) {
  if (empty(stack)) {
    push(stack, data);
    return;
  } else {
    char temp = pop(stack);
    insertAtBottom(stack, data);
    push(stack, temp);
  }
}
