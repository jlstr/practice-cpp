#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestIncreasingSubsequence(std::vector<int>);

int main() {
  const int array[] = { 4, 3, 1 ,2, 8, 3, 4 };
  vector<int> sequence(array, array + (sizeof(array) / sizeof(int)));

  cout << "Longest = " << longestIncreasingSubsequence(sequence) << endl;
  
  return 0;
}

int longestIncreasingSubsequence(std::vector<int> A) {
  int N = A.size();
  vector<int> dp(N, 1);
  int longest = 1;


  for (int i = 1; i < N; i++) {
    for(int j = i - 1; j >= 0; j--) {

      if (A[j] < A[i])
        dp[i] = std::max(dp[i], dp[j] + 1);
      
      longest = std::max(longest, dp[i]);
    }
  }

  return longest;
}
