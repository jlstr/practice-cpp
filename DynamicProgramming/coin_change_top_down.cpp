#include <iostream>
#include <limits>
#include <map>
using namespace std;

int minimumChange(int, int*, const int, map<int, int>);
void printArray(int*, const int);

int main() {
  int coins[] = { 1, 2, 3 };
  const int SIZE = sizeof(coins) / sizeof(int);
  map<int, int> memo;

  int money = 21;
  int result = minimumChange(money, coins, SIZE, memo);

  cout << "\nMinimum number of coins to give a change of $" << money << " is " << result << endl;
  cout << "with coins: ";
  printArray(coins, SIZE);
  cout << endl;

  return 0;
}


int minimumChange(int money, int *coins, const int N, map<int, int> memo) {
  if (money == 0)
    return 0;

  if (memo[money] != 0)
    return memo[money];

  const int INF = std::numeric_limits<int>::max();
  int min = INF;

  for (int i = 0; i < N; ++i) {
    if (coins[i] > money)
      continue;

    int val = minimumChange(money - coins[i], coins, N, memo);

    if (val < min)
      min = val;
  }

  min = (min == INF) ? min : min + 1;
  memo[money] = min;

  return min;
}

void printArray(int *array, const int SIZE) {
  cout << "[\t";
  for (int *p = array, *q = array + SIZE; p != q; ++p) {
    cout << *p << "\t";
  }
  cout << "]" << endl;
}
