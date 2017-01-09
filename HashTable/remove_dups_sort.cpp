#include <iostream>
#include <string>
using namespace std;

int main() {

  string s = "asdajhsdkahsdkahsdkahsdkhaskdhaskdhaz";

  // First sort it!
  std::sort(s.begin(), s.end());

  
  for (string::size_type i = 0; i < s.size(); ++i)
    if (s[i] == s[i + 1]) {
      s = s.substr(0, i + 1) + s.substr(i + 2);
      i--;
    }
  

  cout << s << endl;
  

  return 0;
}
