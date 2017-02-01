#include <iostream>
#include "Trees/BinaryTree.h"
#include "Trees/BinaryTree.cpp"
using namespace std;

int main() {

  BinaryTree<int> binaryTree;

  binaryTree.insert(666);
  binaryTree.insert(22);
  binaryTree.insert(777);
  
  cout << "Number of Leaf Nodes is: " << binaryTree.numLeaves() << endl;

  binaryTree.destroy();

  return 0;
}
