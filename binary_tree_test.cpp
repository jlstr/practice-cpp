#include <iostream>
#include "Trees/BinaryTree.h"
#include "Trees/BinaryTree.cpp"
using namespace std;

int main() {

  BinaryTree<int> binaryTree;

  binaryTree.insert(2);
  binaryTree.insert(666);

  cout << "Tree Height(Depth) = " << binaryTree.height() << endl;

  binaryTree.destroy();

  return 0;
}
