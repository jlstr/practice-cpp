#include <iostream>
#include <utility>
#include <string>
#include <map>
#include <queue>
using namespace std;

int main() {

  std::map<char, std::pair<int, string> > table;

  table['A'] = std::make_pair(0, "");
  table['A'].first = ++table['A'].first;
  
  std::priority_queue<int, vector<int>, std::greater<int> > queue;
  

  queue.push(666);
  queue.push(123);
  queue.push(1);

  cout << queue.top() << endl;

  return 0;
}
