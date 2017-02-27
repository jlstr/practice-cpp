#ifndef GRAPH_H
#define GRAPH_H
#include <string>

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
  
  private:
  typedef struct Vertex *List;
  List *adjList;

  const Vertex* findVertexInList(const V&);

  public:
  const Vertex* getVertex(const V&);
};

#endif
