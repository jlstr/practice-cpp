#include <iostream>
using namespace std;

int main() {
  int a[] = { 1, 2, 3, 4};
  int b[] = { 4, 2, 1, 3 };

  const int A_SIZE = 4;
  int bSize = 4;

  bool setsAreEqual = true;

  for (int i = 0; i < A_SIZE; ++i)
    for (int j = 0; j < bSize; ++j)
      if (a[i] == b[j]) {
        --bSize;
        for (int k = j; k < bSize; ++k) // delete step
          b[k] = b[k + 1];              // delete step
        break;
      } else
        if (j == bSize - 1) setsAreEqual = false;

  cout << "A and B are " << (setsAreEqual ? "Equal" : "NOT Equal") << endl;
    

  return 0;
}
