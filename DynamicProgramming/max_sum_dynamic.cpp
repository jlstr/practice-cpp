#include <iostream>
using namespace std;

int maxContiguousSum(int*, int);
void printArray(int*, int);


int main() {

  int array[] = { -7, 3, 9 };
  const int SIZE = sizeof(array) / sizeof(int);

  cout << "Max Sum (Dynamic) for Array: ";
  printArray(array, SIZE);
  cout << " ====> " << maxContiguousSum(array, SIZE) << endl;

  return 0;
}

int maxContiguousSum(int *array, int size) {
  int *m = new int[size];

  if (array[0] > 0)
    m[0] = array[0];
  else
    m[0] = 0;

  for (int i = 1; i < size; ++i) {
    if ((m[i-1] + array[i]) > 0)
      m[i] = m[i-1] + array[i];
    else
      m[i] = 0;
  }

  int maxSum = 0;

  for (int i = 0; i < size; ++i)
    if (m[i] > maxSum)
      maxSum = m[i];

  delete[] m;

  return maxSum;
}


void printArray(int *array, int size) {
  cout << "[\t";
  for (int *p = array; p != (array+size); ++p)
    cout << *p << "\t";
  cout << " ]";
}
