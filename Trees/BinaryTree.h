#ifndef BINARY_TREE_H
#define BINARY_TREE_H

template<class Data>
class BinaryTree {
  public:

  BinaryTree();
  void insert(Data);
  bool search(Data);
  Data max();

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
  bool performSearch(Node*&, Data);
  Data findMax(Node*&);
};

#endif
