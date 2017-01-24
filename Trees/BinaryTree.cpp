#include "BinaryTree.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

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

template<class Data>
int BinaryTree<Data>::size() {
  return calculateMax(root);
}

template<class Data>
int BinaryTree<Data>::calculateMax(Node* &root) {
  if (root == NULL)
    return 0;
  else 
    return 1 + calculateMax(root->left) + calculateMax(root->right);
}

/*
template<class Data>
int BinaryTree<Data>::calculateMax(Node* &root) {
  if (root == NULL) return 0;
  Node* temp;
  int count = 0;

  std::queue<Node*> countQueue;
  // Always add first element!
  countQueue.push(root);

  while (!countQueue.empty()) {
    temp = countQueue.front();
    countQueue.pop();
    
    ++count;

    if (temp->left != NULL) countQueue.push(temp->left);
    if (temp->right != NULL) countQueue.push(temp->right);
  }
  return count;
}
*/

template<class Data>
void BinaryTree<Data>::printReverse() {
  doPrintReverse(root);
}

template<class Data>
void BinaryTree<Data>::doPrintReverse(Node* &root) {
  if (root == NULL) return;
  Node* temp;

  std::queue<Node*> nodeQueue;
  nodeQueue.push(root);

  std::stack<Data> nodeStack;

  while (!nodeQueue.empty()) {
    temp = nodeQueue.front();
    nodeQueue.pop();

    if (temp->left != NULL) nodeQueue.push(temp->left);
    if (temp->right != NULL) nodeQueue.push(temp->right);

    nodeStack.push(temp->data);
  }

  while (!nodeStack.empty()) {
    std::cout << nodeStack.top() << ", ";
    nodeStack.pop();
  }

  std::cout << std::endl;
}

template<class Data>
void BinaryTree<Data>::destroy() {
  deleteBinaryTree(root);
}

// Deletion of Nodes should be done using POST-Order! (Destroy Children Nodes first)
template<class Data>
void BinaryTree<Data>::deleteBinaryTree(Node* &root) {
  if (root == NULL) return;
  deleteBinaryTree(root->left);
  deleteBinaryTree(root->right);
  std::cout << "----- deleting [Node] with data => " << root->data << std::endl;
  delete root;
  root = NULL;
  return;
}

template<class Data>
int BinaryTree<Data>::height() {
  return getHeight(root);
}

template<class Data>
int BinaryTree<Data>::getHeight(Node* &root) {
  if (root == NULL)
    return 0;
  else
    return 1 + std::max(getHeight(root->left), getHeight(root->right));
}

/*
template<class Data>
int BinaryTree<Data>::getHeight(Node* &root) {
  int height = 0;
  if (root == NULL)
    return 0;

  std::queue<Node*> nodeQueue;

  nodeQueue.push(root);
  nodeQueue.push(NULL);
  Node *temp = NULL;

  while (!nodeQueue.empty()) {
    temp = nodeQueue.front();
    nodeQueue.pop();

    if (temp == NULL) {
      if (!nodeQueue.empty())
        nodeQueue.push(NULL);
      height++;
    } else {
      if (temp->left != NULL)
        nodeQueue.push(temp->left);
      if (temp->right != NULL)
        nodeQueue.push(temp->right);
    }
  } // end of while

  return height;
}
*/

template<class Data>
Data BinaryTree<Data>::deepest() {
  Node *deepNode = getDeepest(root);
  if (deepNode == NULL)
    return Data(-666);
  else
    return deepNode->data;
}

template<class Data>
typename BinaryTree<Data>::Node* BinaryTree<Data>::getDeepest(Node* &root) {
  if (root == NULL)
    return NULL;

  std::queue<Node*> nodeQueue;
  nodeQueue.push(root);

  Node *temp = NULL;
  //
  while (!nodeQueue.empty()) {
    temp = nodeQueue.front();
    nodeQueue.pop();

    if (temp->left != NULL)
      nodeQueue.push(temp->left);
    if (temp->right != NULL)
      nodeQueue.push(temp->right);
  }

  return temp;
}
