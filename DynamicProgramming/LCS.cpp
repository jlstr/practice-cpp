#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void printMatrix(int**, const int, const int);
vector<char> longestCommonSubsequence(const string&, const string&);

int main() {
  string X = "abcdaf";
  string Y = "acbcf";
  
  vector<char> lcs = longestCommonSubsequence(X, Y);

  cout << "Longest Common Subsequence between " << "\"" << X << "\"" << " and " << "\"" << Y << "\"" << " is: " << endl;

  while (!lcs.empty()) {
    cout << lcs.back() << ((lcs.size() >1) ? ", " : "");
    lcs.pop_back();
  }
  cout << endl;
  
  return 0;
}

vector<char> longestCommonSubsequence(const string &x_string, const string &y_string) {
  string X = x_string;
  string Y = y_string;

  int **matrix;
  matrix = new int* [X.size()+2];
  
  for (int i = 0; i < (int)X.size()+2; ++i)
    matrix[i] = new int[Y.size()+2];
    
  for (int i = 0; i < (int)X.size()+2; ++i)
    matrix[i][0] = 0;
 
  for (int j = 0; j < (int)(Y.size()+2); ++j)
    matrix[0][j] = 0;

  X.insert(0, "_");
  Y.insert(0, "_");

  for (int i = 1; i <= (int) X.size(); ++i)
    for (int j = 1; j <= (int) Y.size(); ++j) {
      if (X[i] == Y[j])
        matrix[i][j] = 1 + matrix[i-1][j-1];
      else
        matrix[i][j] = std::max(matrix[i][j-1], matrix[i-1][j]);
    };

  // Store common chars in vector
  vector<char> lcsChars;

  int i = (int) X.size()-1, j = (int) Y.size()-1;

  while (i != 0 || j != 0) {
    if ((matrix[i][j] != matrix[i][j-1]) && (matrix[i][j] != matrix[i-1][j])) {
      lcsChars.push_back(X[i]);
      --i;
      --j;
    } else {
      if (matrix[i][j] == matrix[i][j-1])
        --j;
      else if (matrix[i][j] == matrix[i-1][j])
        --i;
    }
  }

  return lcsChars;
}

void printMatrix(int **matrix, const int NUM_ROWS, const int NUM_COLS) {
  cout << "\n";
  for (int i = 0; i < NUM_ROWS; ++i) {
    for (int j = 0; j < NUM_COLS; ++j)
      cout << matrix[i][j] << "\t";
    cout << "\n\n";
  }
  cout << endl;
}
