#include <iostream>
#include "Graphs/Graph.h"
#include "Graphs/Graph.cpp"
#include <queue>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct QueueNode {
  QueueNode(const char &value, const int &priority): value(value), priority(priority) {}

  char value;
  int priority;
};

struct Comparator {
  bool operator() (const QueueNode &left, const QueueNode &right) const {
    return left.priority > right.priority;
  }
};

void dijkstra(Graph<char>&, char, std::map<char, std::pair<int, std::string> >&);
void printTable(std::map<char, std::pair<int, std::string> >&);
void updatePriority(std::priority_queue<QueueNode, vector<QueueNode>, Comparator>&, char, int);

int main() {
  const int NUM_VERTICES = 4;
  //
  Graph<char> graph(NUM_VERTICES);

  graph.addEdge('A', 'B', 2);
  graph.addEdge('A', 'D', 9);
  graph.addEdge('B', 'C', 3);
  graph.addEdge('C', 'D', 1);

  std::map<char, std::pair<int, std::string> > table;
  for (int i = 0; i < NUM_VERTICES; ++i) {
    const Graph<char>::Vertex *v = graph.getAdjacencyList()[i];
    table[v->value] = std::make_pair(-1, "");
  }

  // Execute Dijkstra
  dijkstra(graph, 'A', table);

  // Print Results
  printTable(table);

  return 0;
}


void dijkstra(Graph<char> &graph, char source, std::map<char, std::pair<int, std::string> > &table) {
  const Graph<char>::Vertex *s = graph.getVertex(source);

  if (s == NULL)
    return;

  std::priority_queue<QueueNode, vector<QueueNode>, Comparator> queue;
  table[source].first = 0;
  // Push source Node
  queue.push(QueueNode(source, 0));

  while (!queue.empty()) {
    const Graph<char>::Vertex *v = graph.getVertex(queue.top().value);
    queue.pop();

    for (const Graph<char>::Vertex *w = v->next; w != NULL; w = w->next) {
      const char key[] = { v->value, '-', '>', w->value, '\0' };
      const int newDistance = table[v->value].first + graph.distance[std::string(key)];

      if (table[w->value].first == -1) {
        table[w->value].first = newDistance;
        table[w->value].second = table[v->value].second + v->value + ", ";
        queue.push(QueueNode(w->value, newDistance));
      }

      if (newDistance < table[w->value].first) {
        table[w->value].first = newDistance;
        table[w->value].second = table[v->value].second + v->value + ", ";
        updatePriority(queue, w->value, newDistance);
      }
    }
  } // end of while
}

void updatePriority(std::priority_queue<QueueNode, vector<QueueNode>, Comparator> &queue, char w, int newPriority) {
  vector<QueueNode> temp;
 
  while (true) {
    QueueNode node = queue.top();
    queue.pop();

    if (node.value == w) {
      node.priority = newPriority;
      temp.push_back(node);
      break;
    } else
      temp.push_back(node);
  }

  while (!temp.empty()) {
    queue.push(temp.back());
    temp.pop_back();
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
