#include <iostream>
#include <algorithm>
using namespace std;

void printMenu() {
  cout << endl;
  cout << "===============================================================================" << endl;
  cout << "\t" << "1. " << "Print Tree" << endl;
  cout << "\t" << "2. " << "Tree Size" << endl;
  cout << "\t" << "3. " << "Tree Depth" << endl;
  cout << "\t" << "4. " << "Minimum Value" << endl;
  cout << "\t" << "5. " << "Insert new Node" << endl;
  cout << "\t" << "6. " << "Has Sum?" << endl;
  cout << "\t" << "7. " << "Exit" << endl;
  cout << "===============================================================================" << endl;
  cout << "\n" << "Select an option: ";
}

struct Node {
  int data;
  Node *left;
  Node *right;
  ~Node() {
    cout << "Node with data: " << this->data << " destroyed!" << endl;
  }
};

Node* newNode(int);
Node* insert(Node*&, int);
int size(Node*&);
int depth(Node*&);
int minValue(Node*&);
void print(Node*&);
int hasSum(Node*&, int);

int main() {
  printMenu();

  Node *tree = NULL;
  int option;
  bool breakLoop = false;

  while (!breakLoop && cin >> option) {
    switch (option) {
      case 1:
        cout << endl;
        print(tree);
        cout << endl;
        break;
      case 2:
        cout << "\n" << "Tree Size is: " << size(tree) << endl;
        break;
      case 3:
        cout << "\n" << "Tree Depth is: " << depth(tree) << endl;
        break;
      case 4:
        cout << "\n" << "Tree Minimum value is: " << minValue(tree) << endl;
        break;
      case 5:
        int data;
        cout << "Value? ";
        cin >> data;
        tree = insert(tree, data);
        break;
      case 6:
        int sum;
        cout << "Enter sum value: ";
        cin >> sum;
        cout << ((hasSum(tree, sum) == 0) ? "TRUE" : "FALSE") << endl;
        break;
      case 7:
        breakLoop = true;
        break;
      default:
        break;
    };

    if (!breakLoop) printMenu();
  }  

  return 0;
}

Node* newNode(int data) {
  Node *node = new Node();
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return node;
}

Node* insert(Node* &tree, int data) {
  if (tree == NULL)
    return newNode(data);
  else {
    if (data <= tree->data) tree->left = insert(tree->left, data);
    else tree->right = insert(tree->right, data);

    return tree;
  }
}

int size(Node* &tree) {
  if (tree == NULL)
    return 0;
  else {
    int count = 1;
    count += size(tree->left);
    count += size(tree->right);
    return count;
  }
}

int depth(Node* &tree) {
  if (tree == NULL)
    return 0;
  else {
    return 1 + std::max(depth(tree->left), depth(tree->right));
  }
}

int minValue(Node* &tree) {
  if (tree == NULL)
    return 0;

  if (tree->left != NULL)
    return minValue(tree->left);
  else
    return tree->data;
}

void print(Node* &tree) {
  if (tree == NULL) return;
  else {
    print(tree->left);
    cout << tree->data << ", ";
    print(tree->right);
  }
}

int hasSum(Node* &tree, int sum) {
  cout << "sum : " << sum << endl;

  if (tree == NULL)
    return ((sum == 0) ? 0 : -1);
  else {
    int subSum = sum - tree->data;
    return hasSum(tree->left, subSum) || hasSum(tree->right, subSum);
  }
}

