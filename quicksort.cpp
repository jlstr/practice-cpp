#include <iostream>
using namespace std;

int partition(int*, int, int);
void quickSort(int*, int, int);
void printArray(int*, int);

int main() {

  int array[] = { 666, 1, 0, 4, 99, 21, 20, 19, 44, 50, 23, 9, 7, 10, 11, 22 };
  const int SIZE = sizeof(array) / sizeof(int);

  printArray(array, SIZE);
  quickSort(array, 0, SIZE-1);
  printArray(array, SIZE);

  return 0;
}


int partition(int *array, int p, int r) {
  // Pivot is Array's last element
  int x = array[r];
  // position i offset to the left side of the Array
  int i = p - 1;

  for (int j = p; j <= (r-1); ++j) {
    if (array[j] < x) {
      ++i;
      // swap positions
      int temp = array[j];
      array[j] = array[i];
      array[i] = temp;
    }
  }

  ++i;
  int temp = array[r];
  array[r] = array[i];
  array[i] = temp;

  return i;
}

void quickSort(int *array, int p, int r) {
  if (p < r) {
    int q = partition(array, p, r);
    quickSort(array, p, q-1);
    quickSort(array, q+1, r);
  }
  else
    return;
}


void printArray(int *array, int size) {
  cout << "\n";
  cout << "[ ";
  for (int i = 0; i < size; ++i)
    cout << array[i] << ((i < size-1) ? ", " : "");
  cout << " ]\n" << endl;
}
