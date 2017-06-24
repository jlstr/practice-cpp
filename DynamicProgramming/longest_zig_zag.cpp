#include <iostream>
#include <vector>
using namespace std;

int longestZigZag(vector<int>);

int main() {
  const int array[] = { 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 };
  
  int N = sizeof(array) / sizeof(int);

  vector<int> sequence(array, array + N);

  cout << "Longest = " << longestZigZag(sequence) << endl;


  return 0;
}

int longestZigZag(vector<int> A) {
  vector<int> dp(A.size(), 1);
  vector<int> signs(A.size());
  signs[0] = 0;

  for (int i = 1; i < static_cast<int>(A.size()); ++i) {

    for (int j = i - 1; j >= 0; --j) {
      // 3 Cases
      if (signs[j] == 0 || (signs[j] >= 0 && A[i] - A[j] < 0) || (signs[j] < 0 && A[i] - A[j] >= 0)) {
        dp[i] = dp[j] + 1;
        signs[i] = A[i] - A[j];
        break;
      }
    }

  }

  return dp[A.size() - 1];
}
