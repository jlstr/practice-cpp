#include <iostream>
#include "Trees/BinaryTree.h"
#include "Trees/BinaryTree.cpp"
using namespace std;

int main() {

  BinaryTree<int> binaryTree;

  binaryTree.insert(1);
  binaryTree.insert(9);
  binaryTree.insert(11);
  
  int deepestValue = binaryTree.deepest();

  if (deepestValue == -666) cout << "No deepest value found!" << endl;
  else cout << "Deepest Value = " << deepestValue << endl;

  binaryTree.destroy();

  return 0;
}
