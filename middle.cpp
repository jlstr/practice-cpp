#include <iostream>
using namespace std;

int main() {

  int start = 0, stop = 4;

  int a[] = { 1, 2, 3, 4, 5 };

  cout << "\n[\t";
  for (int i = 0; i < 5; ++i)
    cout << a[i] << "\t";
  cout << "]\n" << endl;

  while (start < stop) {
    int mid = (start + stop) / 2;
    cout << "MID = " << mid << ", MID ELEMENT = " << a[mid] << endl;
    stop = mid - 1;
  }

  return 0;
}
