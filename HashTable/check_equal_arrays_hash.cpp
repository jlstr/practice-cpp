#include <iostream>
#include <vector>
#include "HashTable/HashMap.h"
#include "HashTable/HashMap.cpp"
using namespace std;

int main() {

  const int SIZE = 5;

  int a[] = { 1, 1, 1, 1, 2 };
  int b[] = { 1, 1, 1, 1, 1 };

  HashMap<int, int> hashMap;

  for (int i = 0; i < SIZE; ++i) {
    if (hashMap.containsKey(a[i])) {
      int value = hashMap[a[i]];
      hashMap.put(a[i], ++value);
    } else
      hashMap.put(a[i], 1);
  }
  

  bool setsAreEqual = true;

  for (int j = 0; j < SIZE; ++j) {
    if (!hashMap.containsKey(b[j])) {
      setsAreEqual = false;
      break;
    } else {
      int value = hashMap[b[j]];
      hashMap.put(b[j], --value);
    }
  }

  if (setsAreEqual) {
    for (int k = 0; k < SIZE; ++k)
      if (hashMap[b[k]] != 0) {
        setsAreEqual = false;
        break;
      }
  }

  cout << "Sets are " << (setsAreEqual ? "EQUAL" : "NOT EQUAL!") << endl;
    
  return 0;
}
