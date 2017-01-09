#include <iostream>
#include "HashTable/HashMap.h"
#include "HashTable/HashMap.cpp"
using namespace std;

int main() {

  int a[] = { 1, 2, 3, 4, 5, 7, 9, 6 };
  int b[] = { 6, 7, 8, 9, 10, 2, 5, 1 };
  const int SIZE = 8;

  HashMap<int, int> hashMap;

  for (int i = 0; i < SIZE; ++i) {
    int key = a[i];
    int value = b[i];
    hashMap.put(key, value);

    if (hashMap.containsKey(value) && hashMap[value] == key)
      cout << "Found symmetric pair: " << "{" << key << "," << value << "}" << endl;
  }


  return 0;
}
