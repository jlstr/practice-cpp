#include <iostream>
#include "Graphs/Graph.h"
#include "Graphs/Graph.cpp"
#include <map>
#include <queue>
using namespace std;

void dfs(Graph<char>&, const char&, std::map<char, bool>&, std::queue<char>&);

int main() {

  Graph<char> graph(3);

  graph.addEdge('a', 'b');
  graph.addEdge('a', 'c');
  graph.addEdge('a', 'd');
  graph.addEdge('d', 'e');
  graph.addEdge('e', 'f');

  std::map<char, bool> visited;
  std::queue<char> queue;

  dfs(graph, 'a', visited, queue);

  while (!queue.empty()) {
    cout << queue.front();
    queue.pop();
    cout << ((!queue.empty()) ? " -> " : "");
    if (queue.empty()) cout << endl;
  }

  return 0;
}

void dfs(Graph<char> &graph, const char &source, std::map<char, bool> &visited, std::queue<char> &queue) {
  Graph<char>::Vertex *s = const_cast<Graph<char>::Vertex*> (graph.getVertex(source));

  if (s == NULL) {
    return;
  }

 
  for (Graph<char>::Vertex *v = s; v != NULL; v = v->next) {
    if (v!= NULL && !visited[v->value]) {
      visited[v->value] = true;
      queue.push(v->value);
      dfs(graph, v->value, visited, queue);
    }
  }
}
