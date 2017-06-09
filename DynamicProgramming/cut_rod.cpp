#include <iostream>
#include <algorithm>
using namespace std;

int cutRod(int*, int);

int main() {

  int prices[] = { 0, 2, 3, 3, 4 };
  int rodLength = 3;

  int maxRevenue = cutRod(prices, rodLength);

  cout << "Max Revenue for Rod of Length = " << rodLength << " is " << "$" << maxRevenue << endl;

  return 0;
}

int cutRod(int *prices, int n) {
  // cout << "cutRod(prices, " << n << ")" << endl;

  if (n == 0)
    return 0;

  int q = -666; // Supposedly negative Infinity
  //
  //
  for (int i = 1; i <= n; ++i)
    q = std::max(q, prices[i] + cutRod(prices, n - i));

  return q;
}
