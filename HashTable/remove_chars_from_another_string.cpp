#include <iostream>
#include <string>
#include "HashTable/HashMap.h"
#include "HashTable/HashMap.cpp"
using namespace std;

int main() {
  string theString = "Ghost in the zShell with Scarlett";
  string notAllowed = "z";

  HashMap<char, bool> hashMap;

  for (string::iterator i = notAllowed.begin(); i != notAllowed.end(); ++i)
    hashMap.put(*i, true);
  
  string removed = "";

  for (string::iterator i = theString.begin(); i != theString.end(); ++i)
    if (!hashMap.containsKey(*i))
      removed += *i;

  cout << removed << endl;

  return 0;
}

