#include <iostream>
using namespace std;

bool binarySearch(int*, int, int, int);

int main() {

  const int SIZE = 10;
  int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  
  const int E = 2;
  bool result = binarySearch(array, 0, SIZE-1, E);

  cout << E << " was found? " << (result ? "YES" : "NO") << endl;

  return 0;
}


bool binarySearch(int *array, int low, int high, int E) {
  if (low > high)
    return false;

  int mid = (low + high) / 2;

  if (array[mid] == E)
    return true;

  if (E < array[mid])
    return binarySearch(array, low, mid-1, E);
  else
    return binarySearch(array, mid+1, high, E);
}
