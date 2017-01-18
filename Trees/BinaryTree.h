#ifndef BINARY_TREE_H
#define BINARY_TREE_H

template<class Data>
class BinaryTree {
  public:

  BinaryTree();
  void insert(Data);
  void printTree();

  private:
  
  struct Node {
    Data data;
    Node *left;
    Node *right;
  };
  
  // The Root of the Binary Tree
  Node *root;

  Node* newNode(Data);
  Node* performInsertion(Node*&, Data); // pass root here
};

#endif
