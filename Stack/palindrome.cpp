#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s = "aaaXaaa";
  string::iterator i = s.begin();

  Stack *stack = createStack();

  while(*i != 'X') {
    push(stack, *i++);
  }

  i++;

  while (i != s.end()) {
    if (empty(stack) || *i != pop(stack)) {
      cout << "Not Palindrome" << endl;
      break;
    }
    i++;
  }

  if (empty(stack))
    cout << "Is Palindrome" << endl;

  return 0;
}
