#include "Stack.h"
#include <iostream>

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
  std::cout << "\n\t" << "----> Doubling Stack!" << std::endl;

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
