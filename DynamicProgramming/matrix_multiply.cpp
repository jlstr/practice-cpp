#include <iostream>
#include <vector>
using namespace std;

int main() {

  const int ROWS = 2;
  const int COLUMNS = 2;

  const int A[ROWS][COLUMNS] = {
    { 2, 2 },
    { 2, 2 }
  };

  const int B[ROWS][COLUMNS] = {
    { 2, 2 },
    { 2, 2 }
  };

  int C[ROWS][COLUMNS];

  for(int i = 0; i < ROWS; ++i) // Actually A.ROWS
    for(int j = 0; j < COLUMNS; ++j) { // Actually B.COLS
      int Cij = 0;

      for (int k = 0; k < ROWS; ++k) { // ROWS or COLS is fine
        Cij += (A[i][k] * B[k][j]);
        C[i][j] = Cij;
      }
    }


  for(int i = 0; i < ROWS; ++i) {
    cout << "\n" << endl;
    for(int j = 0; j < COLUMNS; ++j)
      cout << C[i][j] << "\t";
  }
  cout << "\n" << endl;

  return 0;
}
