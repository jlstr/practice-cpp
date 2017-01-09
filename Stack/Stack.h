#ifndef STACK_H
#define STACK_H

#include <iostream>

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

#endif
