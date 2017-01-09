#include <iostream>
#include <string>
using namespace std;

template<class T> void printer(T);
class Dog {};
class Tiger {};

int main() {

  printer<int> (1);
  printer<string> ("bola de longos");
  printer<char> ('a');

  return 0;
}

template<class T> void printer(T val) {

  string objType = typeid(val).name();
  char type;

  /*if (objType.find("string") != string::npos)
    type = 's';
  else
    type = objType.at(0); */

  type = (objType.find("string") != string::npos) ? 's' : objType.at(0);
  

  switch(type) {
    case 'i':
      cout << "Object is an Integer" << endl;
      break;
    case 's':
      cout << "Object is a String" << endl;
      break;
    case 'c':
      cout << "Object is a Char" << endl;
      break;
    default:
      cout << "What the hell is that!" << endl;
      break;
  };

}
