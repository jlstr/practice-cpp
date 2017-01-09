#include <iostream>
using namespace std;

int main() {

  const int SIZE = 4;

  int a[] = { 3, 4, 2, 0 };
  int b[] = { 1, 4, 3, 2 };


  std::sort(a, a + SIZE);
  std::sort(b, b + SIZE);

  bool setsAreEqual = true;

  for (int *p = a, *q = b; (p != a + SIZE && q != b + SIZE); ++p, ++q) {
    if (*p != *q) {
      setsAreEqual = false;
      break;
    }
  }

  cout << "Arrays are " << (setsAreEqual ? "EQUAL" : "NOT EQUAL!") << endl;


  return 0;
}
