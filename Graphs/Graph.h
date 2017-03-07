#ifndef GRAPH_H
#define GRAPH_H
#include <string>
#include <map>

template<class V>
class Graph {
  public:
  Graph(int numVertices, bool directed=true);
  void addEdge(const V&, const V&);

  private:
  int numVertices;
  bool directed;
  int position;

  public:
  struct Vertex {
    V value;
    std::string color;
    Vertex *next;
  };

  std::map<V, int> incidence;
  typedef struct Vertex *List;

  private:
  List *adjList;
  const Vertex* findVertexInList(const V&);
  Vertex* newVertex(const V&);
  void calculateIncidence(const V&, const V&);

  public:
  const Vertex* getVertex(const V&);
  List* getAdjacencyList();
};

#endif
