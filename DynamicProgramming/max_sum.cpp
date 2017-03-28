#include <iostream>
using namespace std;

int maxContiguousSum(int*, int);
void printArray(int*, int);

int main() {
  //int array[] = { -7, 3, 9 };
  //
  int array[] = { 1, -3, 4, -2, -1, 6 };
  const int SIZE = sizeof(array) / sizeof(int);

  cout << "Max Sum for Array: ";
  printArray(array, SIZE);
  cout << " ==> " << maxContiguousSum(array, SIZE) << endl;

  return 0;
}


int maxContiguousSum(int *array, int size) {
  int maxSum = 0, currentSum = 0;

  for (int *p = array; p != (array+size-1); ++p) {
    currentSum = *p;
    for (int *q = (p+1); q != (array+size); ++q) {
      currentSum += *q;
      if (maxSum == 0 || currentSum > maxSum)
        maxSum = currentSum;
    }
  }

  return maxSum;
}

void printArray(int *array, int size) {
  cout << "[\t";
  for (int *p = array; p != (array+size); ++p)
    cout << *p << "\t";
  cout << " ]";
}
