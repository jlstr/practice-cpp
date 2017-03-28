#include <iostream>
#include "Graphs/Graph.h"
#include "Graphs/Graph.cpp"
#include <map>
#include <queue>
using namespace std;

void topological_sort(Graph<int>&, const int&, std::map<int, bool>&, std::queue<int>&);

int main() {
  Graph<int> graph(4);

  graph.addEdge(1, 2);
  graph.addEdge(1, 3);
  graph.addEdge(2, 4);
  graph.addEdge(3, 4);

  std::map<int, bool> visited;
  std::queue<int> orderQueue;

  topological_sort(graph, 1, visited, orderQueue);

  while (!orderQueue.empty()) {
    cout << orderQueue.front() << ((orderQueue.size() > 1) ? ", " : "");
    orderQueue.pop();
  }
  cout << endl;
}


void topological_sort(Graph<int> &graph, const int &source, std::map<int, bool> &visited, std::queue<int> &orderQueue) {
  Graph<int>::Vertex *u = const_cast<Graph<int>::Vertex*> (graph.getVertex(source));

  if (u == NULL)
    return;

  if (graph.incidence[u->value] == 0 && !visited[u->value]) {
    visited[u->value] = true;
    orderQueue.push(u->value);
  }

  for (const Graph<int>::Vertex *v = u->next; v != NULL; v = v->next) {
    graph.incidence[v->value] = --graph.incidence[v->value];
    topological_sort(graph, v->value, visited, orderQueue);
  }
}
