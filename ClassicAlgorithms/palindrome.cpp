#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string);

int main() {
  
  const string s("ana");

  cout << ((isPalindrome(s)) ? "true" : "false") << endl;

  return 0;
}

bool isPalindrome(const string s) {
  if (s.length() <= 1)
    return true;
  else
    return s.at(0) == s.at(s.length() - 1) && isPalindrome(s.substr(1, s.length() -1));
}
