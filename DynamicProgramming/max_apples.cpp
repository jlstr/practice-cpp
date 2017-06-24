#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxApples(vector< vector<int> >);

int main() {
  const int ROWS = 3;
  const int COLS = 3;

  vector< vector<int> > matrix(ROWS, vector<int>(COLS));

  int matrixValues[ROWS][COLS] = {
    { 1, 2, 3 },
    { 4, 5, 6 },
    { 7, 8, 9 }
  };

  for (int i = 0; i < ROWS; i++)
    for (int j = 0; j < COLS; j++)
      matrix[i][j] = matrixValues[i][j];

  cout << "Max Apples = " << maxApples(matrix) << endl;

  return 0;
}


int maxApples(vector< vector<int> > A) {
  const int ROWS = A.size();
  const int COLS = A[0].size();

  vector< vector<int> > S(ROWS, vector<int>(COLS, 0));

  for (int i = 0; i < ROWS; i++)
    for (int j = 0; j < COLS; j++) {
      int top = (i > 0) ? S[i-1][j] : 0;
      int left = (j > 0) ? S[i][j-1] : 0;
      S[i][j] = A[i][j] + std::max(std::max(top, left), 0);
    }
      
  return S[ROWS-1][COLS-1];
}
