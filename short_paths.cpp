#include <iostream>
#include "Graphs/Graph.h"
#include "Graphs/Graph.cpp"
#include <queue>
#include <utility>
#include <map>
#include <string>
using namespace std;

void shotest_paths(Graph<char>&, char, std::map<char, std::pair<int, std::string> >&);
void printTable(std::map<char, std::pair<int, std::string> >&);

int main() {
  const int NUM_VERTICES = 5;
  //
  Graph<char> graph(NUM_VERTICES);

  graph.addEdge('A', 'B');
  graph.addEdge('A', 'C');
  graph.addEdge('A', 'D');
  graph.addEdge('D', 'E');

  std::map<char, std::pair<int, std::string> > table;

  for (int i = 0; i < NUM_VERTICES; ++i) {
    const Graph<char>::Vertex *v = graph.getAdjacencyList()[i];
    table[v->value] = std::make_pair(-1, "");
  }

  shotest_paths(graph, 'D', table);
  //
  // Print Results
  printTable(table);

  return 0;
}


void shotest_paths(Graph<char> &graph, char source, std::map<char, std::pair<int, std::string> > &table) {
  const Graph<char>::Vertex *s = graph.getVertex(source);

  if (s == NULL)
    return;

  std::queue<char> vertexQueue;
  table[source].first = 0;
  //
  vertexQueue.push(source);

  while (!vertexQueue.empty()) {
    const Graph<char>::Vertex *v = graph.getVertex(vertexQueue.front());
    vertexQueue.pop();

    for (const Graph<char>::Vertex *w = v->next; w != NULL; w = w->next) {
      if (table[w->value].first == -1) {
        table[w->value].first = table[v->value].first + 1;
        table[w->value].second = table[v->value].second + v->value + ", ";
        vertexQueue.push(w->value);
      }
    }
  }
}

void printTable(std::map<char, std::pair<int, std::string> > &table) {
  std::map<char, std::pair<int, std::string> >::iterator it;
  cout << "\n" << endl;
  for (it = table.begin(); it != table.end(); ++it) {
    cout << it->first << "\t|\t" << it->second.first << "\t|\t" << it->second.second << endl;
  }
  cout << "\n" << endl;
}
