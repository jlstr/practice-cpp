#include <iostream>
using namespace std;

int* copyArray(int*, int);
int* appendToNew(int*, int, int);

int main() {
  int array[] = { 1, 2, 3, 4 };
  int size = sizeof(array) / sizeof(int);


  int *copy = copyArray(array, size);
  
  cout << copy[2] << endl;

  return 0;
}

int* copyArray(int *array, int size) {
  int* copy = new int[0];

  for (int i = 0; i < size; i++) {
    copy = appendToNew(copy, array[i], i);
  }

  return copy;
}


int* appendToNew(int *array, int value, int size) {
  int *bigger = new int[size + 1];

  for (int i = 0; i < size; i++) {
    *(bigger + i) = *(array + i);
  }

  // add new element
  *(bigger + size) = value;

  return bigger;
}
