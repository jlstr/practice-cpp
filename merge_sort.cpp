#include <iostream>
using namespace std;

void mergeSort(int*, int, int);
void merge(int*, int, int, int);
void printArray(int*, int);

int main() {
  
  int array[] = { 4, 2 };
  const int SIZE = sizeof(array) / sizeof(int);

  printArray(array, SIZE);
  mergeSort(array, 0, SIZE-1);
  printArray(array, SIZE);

  return 0;
}

void mergeSort(int *array, int p, int r) {
  if (p < r) {
    int q = (p + r) / 2;
    mergeSort(array, p, q);
    mergeSort(array, q+1, r);
    merge(array, p, q, r);
  } else
    return;
}

void merge(int *array, int p, int q, int r) {
  int n1 = q - p + 1;  // size of sub-array 1
  int n2 = r - q;     // size of sub-array 2

  int *left = new int[n1 + 1]; // reserve one additional space for sentinel
  int *right = new int[n2 + 1];

  for (int i = 0; i < n1; ++i)
    left[i] = array[p + i];

  for (int i = 0; i < n2; ++i)
    right[i] = array[q + i + 1];

  left[n1] = 99999; // sentinels
  right[n2] = 99999;

  int i = 0, j = 0;
    
  for (int k = p; k <= r; ++k) {
    if (left[i] <= right[j])
      array[k]  = left[i++];
    else
      array[k] = right[j++];
  }

  delete [] left;
  delete [] right;
}

void printArray(int *array, int size) {
  cout << "\n";
  cout << "[ ";
  for (int i = 0; i < size; ++i)
    cout << array[i] << ((i < size-1) ? ", " : "");
  cout << " ]\n" << endl;
}
