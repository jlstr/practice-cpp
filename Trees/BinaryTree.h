#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <vector>

template<class Data>
class BinaryTree {
  public:

  BinaryTree();
  void insert(Data);
  bool search(Data);
  Data max();
  int size();
  void printReverse();
  void destroy();
  int height();
  Data deepest();
  int numLeaves();
  Data maxLevelSum();
  void printPaths();
  bool hasSum(int);
  int sum();
  void ancestors(Data);

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
  int calculateMax(Node*&);
  void doPrintReverse(Node*&);
  void deleteBinaryTree(Node*&);
  int getHeight(Node*&);
  Node* getDeepest(Node*&);
  int getNumLeaves(Node*&);
  void doPrintPaths(Node*&, std::vector<Data>);
  bool hasSum(Node*&, int);
  int sum(Node*&);
  bool ancestors(Node*&, Data);
};

#endif
