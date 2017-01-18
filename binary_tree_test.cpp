#include <iostream>
#include "Trees/BinaryTree.h"
#include "Trees/BinaryTree.cpp"
using namespace std;

int main() {

  BinaryTree<int> binaryTree;

  binaryTree.insert(666);
  binaryTree.insert(333);
  binaryTree.insert(777);

  binaryTree.printTree();

  return 0;
}
