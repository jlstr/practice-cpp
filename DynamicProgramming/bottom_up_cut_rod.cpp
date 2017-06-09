#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int bottomUpCutRod(int*, int);

int main() {
  int prices[] = { 0, 2, 3, 4 };
  int rodLength = 3;
  
  cout << "Max revenue of Rod of length " << rodLength << " is " << bottomUpCutRod(prices, rodLength) << endl;

  return 0;
}

int bottomUpCutRod(int *prices, int n) {
  std::map<int, int> memo; // Revenues Memo
  memo[0] = 0;

  for (int i = 1; i <= n; ++i) {
    int q = -666;

    for (int j = 1; j <= i; ++j)
      q = std::max(q, prices[j] + memo[i - j]);

    memo[i] = q;
  }

  return memo[n];
}
