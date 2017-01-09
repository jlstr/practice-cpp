#include <iostream>
#include <string>
using namespace std;

void permutation(string);
void permutation(string, string);

int main() {
  permutation("abc");

  return 0;
}

int count = 0;

void permutation(string str) {
  permutation(str, "");
}

void permutation(string str, string prefix) {
  if (str.length() == 0) cout << "\n" << "permutation = " << prefix << "\n" << endl;
  else
    for (string::size_type i = 0; i < str.length(); i++) {
      string rem = str.substr(0, i) + str.substr(i + 1);
      permutation(rem, prefix + str[i]);
    }
}
