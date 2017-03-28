#include <iostream>
using namespace std;

int maxSum(int*, const int);

int main() {
  int array[] = { 1, 1, 1, 1 };
  const int SIZE = sizeof(array) / sizeof(int);
  // get max sum
  int max = maxSum(array, SIZE);
  cout << "MAX = " << max << endl;

  return 0;
}

int maxSum(int *array, const int size) {
  int *m = new int[size+1];

  m[0] = array[0];
  // m[1] = std::max(array[0], array[1]);
  m[1] = array[1];

  for (int i = 2; i < size; ++i) {
    m[i] = std::max((array[i] + m[i-2]), array[i-1]);
  }

  int maxSum = std::max(m[size-1], m[size-2]);
  delete [] m;

  return maxSum;
}
