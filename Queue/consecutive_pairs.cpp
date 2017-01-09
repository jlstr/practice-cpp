#include "Queue.h"
#include "Stack/Stack.h"
#include <iostream>
#include <cmath>
using namespace std;

int main() {

  Stack *stack = createStack();
  Queue *queue = createQueue();

  char numbers[] = { '9', '7', '4', '3', '2', '1' };
  const int SIZE = sizeof(numbers) / sizeof(char);

  for (char *i = numbers, *end = numbers + SIZE; i != end; ++i)
    push(stack, *i);

  while (!empty(stack)) {
    int n = pop(stack) - '0';
    enQueue(queue, n);

    if (!empty(stack)) {
      int m = pop(stack) - '0';
      enQueue(queue, m);

      if (std::abs(n - m) == 1) {
        cout << "[ " << n << ", " << m << " ]" << " is a consecutive pair" << endl;
      }
    }

  } // end of while

  return 0;
}
