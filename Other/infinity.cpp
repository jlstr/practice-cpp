#include <iostream>
#include <limits>
using namespace std;

int main() {

  const double INFINITY = std::numeric_limits<double>::infinity();

  cout << ((10000 > INFINITY) ? "TRUE" : "FALSE") << endl;
  //
  // cout << INFINITY << endl;

  return 0;
}
