#include <iostream>
#include "Graphs/Graph.h"
#include "Graphs/Graph.cpp"
#include <queue>
#include <map>
using namespace std;

void bfs(Graph<char>&, const char&);

int main() {
  Graph<char> graph(4);

  graph.addEdge('A', 'B');
  graph.addEdge('B', 'C');

  bfs(graph, 'B');

  return 0;
}

void bfs(Graph<char> &graph, const char &source) {
  Graph<char>::Vertex *s = const_cast<Graph<char>::Vertex*> (graph.getVertex(source));
  if (s == NULL) {
    cout << "Vertex not found!" << endl;
    return;
  }

  std::map<char, bool> visited;
  //
  std::queue<Graph<char>::Vertex*> queue;
  // Mark source Vertex as visited
  queue.push(s); // enqueue source node

  while (!queue.empty()) {
    Graph<char>::Vertex *u = const_cast<Graph<char>::Vertex*> (graph.getVertex(queue.front()->value));  // De-Queue
    queue.pop();                                                                                        // De-Queue
    
    for (Graph<char>::Vertex *v = u; v != NULL; v = v->next) {
      if (v!= NULL && !visited[v->value]) {
        visited[v->value] = true;
        queue.push(v);
        cout << v->value << " - ";
      }
    }
  } // end of while

  cout << endl;
}
