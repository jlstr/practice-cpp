#include <iostream>
#include "Trees/BinaryTree.h"
#include "Trees/BinaryTree.cpp"
using namespace std;

int main() {

  BinaryTree<int> binaryTree;

  binaryTree.insert(666);
  binaryTree.insert(777);
  binaryTree.insert(111);
  binaryTree.insert(1);
  binaryTree.insert(2);
  binaryTree.insert(3);
  binaryTree.insert(999);

  cout << "Max Value: " << binaryTree.max() << endl;

  return 0;
}
