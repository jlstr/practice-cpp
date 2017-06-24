// PROBLEM:
// https://community.topcoder.com/stat?c=problem_statement&pm=2402
// As suggested by TopCoder Dynamic programming Tutorial
// https://www.topcoder.com/community/data-science/data-science-tutorials/dynamic-programming-from-novice-to-advanced/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxDonation(vector<int>);

int main() {
  const int array[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
  const int SIZE = sizeof(array) / sizeof(int);

  vector<int> donations(array, array + SIZE);

  cout << maxDonation(donations) << endl;

  return 0;
}

int maxDonation(vector<int> A) {
  vector<int> dp(A.size());
  vector<bool> zero(A.size(), false);
  
  dp[0] = A[0];
  dp[1] = A[1];

  const int N = static_cast<int>(A.size());

  for (int i = 2; i < N; ++i) {
  
    if (dp[i-2] + A[i] > dp[i-1]) {
      dp[i] = dp[i-2] + A[i];
      zero[i] = true;
    } else {
      dp[i] = dp[i-1];
      zero[i] = zero[i-1];
    }

  }

  int answer = 0;
  
  if (zero[N-1] == true) {
    answer = std::max(dp[N-2], dp[N-3]);
  } else {
    answer = dp[N-1];
  }

  return answer;
}
