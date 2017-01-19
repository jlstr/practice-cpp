#include "BinaryTree.h"
#include <iostream>
#include <algorithm>
#include <queue>

template<class Data>
BinaryTree<Data>::BinaryTree() {
  root = NULL;
}

template<class Data>
typename BinaryTree<Data>::Node* BinaryTree<Data>::newNode(Data data) {
  Node *node = new Node();
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  
  return node;
}

template<class Data>
void BinaryTree<Data>::insert(Data data) {
  root = performInsertion(root, data);
}

template<class Data>
typename BinaryTree<Data>::Node* BinaryTree<Data>::performInsertion(Node* &root, Data data) {
  if (root == NULL)
    root = newNode(data);
  else {
    if (data <= root->data) performInsertion(root->left, data);
    else performInsertion(root->right, data);
  }

  return root;
}

template<class Data>
bool BinaryTree<Data>::search(Data target) {
  return performSearch(root, target);
}

template<class Data>
bool BinaryTree<Data>::performSearch(Node* &root, Data target) {
  if (root == NULL)
    return false;
  if (target == root->data)
    return true;
  else {
    if (target < root->data) return performSearch(root->left, target);
    else return performSearch(root->right, target);
  }
}

template<class Data>
Data BinaryTree<Data>::max() {
  return findMax(root);
}

template<class Data>
Data BinaryTree<Data>::findMax(Node* &root) {
  Data rootValue, left, right, maxValue = -999;

  if (root != NULL) {
    rootValue = root->data;
    left = findMax(root->left);
    right = findMax(root->right);

    return std::max(rootValue, std::max(left, right));
  } 
  // else
  return Data(-9999);
}


// without Recursion, using Queue
/*
template<class Data>
Data BinaryTree<Data>::findMax(Node* &root) {
  Data maxValue(-10000);
  Node *temp;
  std::queue<Node*> maxQueue;

  maxQueue.push(root);

  while (!maxQueue.empty()) {
    temp = maxQueue.front();
    maxQueue.pop();
    
    if (maxValue < temp->data)
      maxValue = temp->data;

    if (temp->left != NULL)
      maxQueue.push(temp->left);

    if (temp->right != NULL)
      maxQueue.push(temp->right);
  }

  return maxValue;
}
*/
