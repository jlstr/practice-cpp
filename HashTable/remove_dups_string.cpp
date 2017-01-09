#include <iostream>
#include <string>
using namespace std;

int main() {
  string s = "aaaaaaaaac";

  for (string::size_type i = 0; i < s.size(); ++i)
    for (string::size_type j = i + 1; j < s.size(); ++j)
      if (s[i] == s[j]) {
        s[j--] = s[s.size() - 1];
        s = s.substr(0, s.size() - 1);
      }

  cout << s << endl;

  return 0;
}

