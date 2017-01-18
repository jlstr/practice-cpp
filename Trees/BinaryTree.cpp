#include "BinaryTree.h"
#include <iostream>

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
void BinaryTree<Data>::printTree() {
  std::cout << root->data << ", " << root->left->data << ", " << root->right->data << std::endl;
}
