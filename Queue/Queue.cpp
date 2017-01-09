#include "Queue.h"
#include <iostream>
using namespace std;

Queue* createQueue() {
  Queue *queue;
  queue = new Queue();
  queue->front = NULL;
  queue->rear = NULL;
  return queue;
}

bool empty(Queue* &queue) {
  return (queue->front == NULL);
}

void enQueue(Queue* &queue, int data) {
  Node *node = new Node();
  node->data = data;
  node->next = NULL;

  if (empty(queue)) {
    queue->front = node;
    queue->rear = node;
  } else {
    queue->rear->next = node;
    queue->rear = node;
  }
}

int deQueue(Queue* &queue) {
  if (empty(queue))
    return -666;

  int data;
  Node *temp;

  temp = queue->front;
  data = temp->data;

  if (queue->front == queue->rear) {
    queue->front = NULL;
    queue->rear = NULL;
  } else 
    queue->front = queue->front->next;

  delete temp;

  return data;
}

int front(Queue* &queue) {
  if (empty(queue))
    return -666;
  return queue->front->data;
}

int size(Queue* &queue) {
  if (empty(queue))
    return 0;
  int queueSize = 0;
  for (Node *temp = queue->front; temp != NULL; temp = temp->next) {
    queueSize++;  
  }

  return queueSize;
}
