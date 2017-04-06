#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

// params array of available coins (int*)
// NumCoins (int)
// Change to be given (int)
vector<int> coinChange(int*, const int, int);
void printArray(int*, int);

int main() {
  int coins[] = { 5, 1, 10, 25, 50 }; // Coin Denominations
  const int NUM_COINS = sizeof(coins) / sizeof(int);
  
  // Let's sort Coins Array to make the Algorithm work better
  std::sort(coins, coins + NUM_COINS);

  int change = 26;
  vector<int> whichCoins = coinChange(coins, NUM_COINS, change);
  cout << "Minimum number of coins to provide Change for $" << change << " is " << whichCoins.size() << endl;
  cout << "And the coins are: ";
  
  while (!whichCoins.empty()) {
    cout << "$" << whichCoins.back() << ((whichCoins.size() > 1) ? ", " : "");
    whichCoins.pop_back();
  }
  cout << endl;

  return 0;
}

vector<int> coinChange(int *coins, const int N, int change) {
  int *T = new int[change + 2];
  int *M = new int[change + 2];
  
  // Initialization Steps
  T[0] = 0;
  M[0] = 0;

  for (int i = 1; i <= change; ++i) {
    int coin = -1;
    int min = 999999; // Supposedly INFINITY

    for (int j = 0; j < N; ++j) {
      if (coins[j] <= i) {
        // Calculate new Minimum
        int newMin = std::min(min, 1 + T[i - coins[j]]);
        //
        if (newMin < min) {
          min = newMin;
          coin = j;
        }
      }
    }

    T[i] = min;
    M[i] = coin;
  }

  int start = change;
  std::vector<int> whichCoins;

  while (start > 0) {
    whichCoins.push_back(coins[M[start]]);
    start -= coins[M[start]];
  }

  delete [] T;
  delete [] M;

  return whichCoins;
}


void printArray(int *array, int SIZE) {
  cout << "[\t";
  for (int *p = array, *q = array+SIZE; p != q; ++p) {
    cout << *p << "\t";
  }
  cout << "]" << endl;
}
