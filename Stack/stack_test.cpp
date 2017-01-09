#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
  Stack *stack = createStack();

  push(stack, 'a');
  push(stack, 'b');

  push(stack, 'c');
  push(stack, 'd');

  push(stack, 'e');
  push(stack, 'f');

  return 0;
}
