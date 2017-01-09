#include <iostream>
#include <string>
using namespace std;

int main() {
  string s = "abcd";
  char c = '\0';

  string::iterator j;

  for (string::iterator i = s.begin(); i != s.end(); ++i) {
    if (j == s.end()) {
      c = *--i;
      break;
    }
    for (j = i + 1; j != s.end(); ++j)
      if (*i == *j) break;
  }

  if (c != '\0') cout << "First non-repeated char = " << c << endl;
  
  return 0;
}
