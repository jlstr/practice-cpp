#include <iostream>
#include "Trees/BinaryTree.h"
#include "Trees/BinaryTree.cpp"
using namespace std;

int main() {

  BinaryTree<int> binaryTree;
  binaryTree.insert(1);
  binaryTree.insert(4);
  binaryTree.insert(7);
  binaryTree.insert(666);
  
  binaryTree.ancestors(666);

  cout << endl;
  binaryTree.destroy();

  return 0;
}
