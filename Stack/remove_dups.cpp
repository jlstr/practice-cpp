#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

string removeDups(string);

int main() {
  cout << removeDups("mississippi") << endl;
  return 0;
}

string removeDups(string input) {
  Stack *stack = createStack();

  for (string::iterator i = input.begin(); i != input.end(); ++i) {
    if (empty(stack)) push(stack, *i);
    else {
      if (top(stack) == *i) pop(stack);
      else push(stack, *i);
    }
  }
  
  string result = "";

  while (!empty(stack))
    result = pop(stack) + result;

  return result;
}
