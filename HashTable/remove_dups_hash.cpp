#include "HashTable/HashMap.h"
#include "HashTable/HashMap.cpp"
#include <iostream>
#include <string>
using namespace std;

int main() {
  HashMap<char, int> hashMap;

  string s = "aaaaaaaaabbbbcaaaazzzzrrrrdddasasadadasdas", newString;

  for (string::size_type i = 0; i < s.size(); ++i)
    if (!hashMap.containsKey(s.at(i))) {
      hashMap.put(s.at(i), 1);
      newString += s.at(i);
    }

  cout << newString << endl;

  return 0;
}
