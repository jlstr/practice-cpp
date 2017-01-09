#ifndef QUEUE_H
#define QUEUE_H

struct Node;

struct Node {
  int data;
  Node *next;
};

struct Queue {
  Node *front;
  Node *rear;
};

Queue* createQueue();
bool empty(Queue*&);
void enQueue(Queue*&, int);
int deQueue(Queue*&);
int front(Queue*&);
int size(Queue*&);

#endif
