#include <iostream>
#include "Graphs/Graph.h"
#include "Graphs/Graph.cpp"
using namespace std;

int main() {
  Graph<int> graph(10);

  graph.addEdge(1, 2);
  graph.addEdge(1, 3);
  graph.addEdge(1, 5);
  graph.addEdge(2, 7);

  graph.print();

  return 0;
}
