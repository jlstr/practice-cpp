#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int cutRod(int*, int, std::map<int, int>&);

int main() {

  int prices[] = { 0, 2, 3, 3, 4 };
  int rodLength = 4;
  
  // The HashTable to store computed solutions
  std::map<int, int> memo;

  int maxRevenue = cutRod(prices, rodLength, memo);
  cout << "Max Revenue for Rod of Length = " << rodLength << " is " << "$" << maxRevenue << endl;

  return 0;
}

int cutRod(int *prices, int n, std::map<int, int> &memo) {
  
  if (memo[n] > 0)
    return memo[n];

  int q;

  if (n == 0)
    q = 0;
  else {
    q = -666;
    for (int i = 1; i <= n; ++i)
      q = std::max(q, prices[i] + cutRod(prices, n - i, memo));
  }

  // Memoize Solution!
  memo[n] = q;

  return q;
}
