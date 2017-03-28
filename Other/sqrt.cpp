#include <iostream>

using namespace std;

int sqrt(int);
int sqrtHelper(int, int, int);

int main() {
  /*
  int root = sqrt(30);

  cout << root << endl;

  */

  cout << 49/2 << endl;
  cout << 37/2 << endl;
  cout << 100/3 << endl;

  return 0;
}

int sqrtHelper(int n, int min, int max) {
  if (max < min) return -1;

  int guess = (min + max) / 2;

  if (guess * guess == n) return guess;
  else if (guess * guess < n)
    return sqrtHelper(n, guess + 1, max);
  else
    return sqrtHelper(n, 1, guess - 1);
}

int sqrt(int n) {
  return sqrtHelper(n, 1, n);
}
