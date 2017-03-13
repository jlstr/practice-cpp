#include <iostream>
using namespace std;

bool binarySearch(int*, int, int, int);

int main() {

  int array[] = { 1, 2, 3, 4, 5 };
  const int SIZE = 5;

  const int e = 3;
  bool result = binarySearch(array, e, 0, SIZE-1);

  cout << e << " was found? " << (result ? "YES" : "NO") << endl;

  return 0;
}


bool binarySearch(int *array, int e, int low, int high) {

  while (low <= high) {
    int mid = (low + high) / 2;

    if (array[mid] == e)
      return true;

    if (array[mid] > e)
      high = mid - 1;
    else
      low = mid + 1;
  } // end of while

  return false;
}
