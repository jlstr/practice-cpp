#include <iostream>
#include "Trees/BinaryTree.h"
#include "Trees/BinaryTree.cpp"
using namespace std;

int main() {

  BinaryTree<int> binaryTree;
  binaryTree.insert(1);
  binaryTree.insert(665);
  
  cout << "Tree-Sum = " << binaryTree.sum() << endl;

  cout << endl;
  binaryTree.destroy();

  return 0;
}
