#include "Graph.h"
#include <iostream>

template<class V>
Graph<V>::Graph(int numVertices, bool directed) {
  this->numVertices = numVertices;
  this->directed = directed;
  this->adjList = new List[numVertices+1]; // List is Vertex*
  this->position = 0;
  
  for (int i = 0; i < numVertices; ++i) this->adjList[i] = NULL;
}

template<class V>
// where u is source and v is destination
void Graph<V>::addEdge(const V& u, const V& v) {
  if (this->position > this->numVertices)
    return;

  Vertex *vertex = const_cast<Vertex*> (findVertexInList(u));

  if (vertex == NULL) {
    vertex = new Vertex();
    vertex->value = u;
    vertex->next = NULL;
    this->adjList[this->position++] = vertex;
  }

  Vertex *dest = new Vertex();
  dest->value = v;
  // dest->next = NULL;
  dest->next = vertex->next;
  vertex->next = dest;

  vertex = const_cast<Vertex*> (findVertexInList(v));
  if (vertex == NULL) {
    vertex = new Vertex();
    vertex->value = v;
    vertex->next = NULL;
    this->adjList[this->position++] = vertex;
  }

  calculateIncidence(u, v);
}

template<class V>
void Graph<V>::calculateIncidence(const V &u, const V &v) {
  if (incidence[u] == 0)
    incidence[u] = 0;

  if (incidence[v] == 0)
    incidence[v] = 1;
  else
    incidence[v] = ++incidence[v];
}

template<class V>
const typename Graph<V>::Vertex* Graph<V>::findVertexInList(const V& u) {
  const Vertex *vertex = NULL;

  for (int i = 0; i < this->numVertices; ++i) {
    if (adjList[i] != NULL && adjList[i]->value == u) {
      vertex = adjList[i];
      break;
    }
  }

  return vertex;
}

template<class V>
const typename Graph<V>::Vertex* Graph<V>::getVertex(const V& s) {
  return this->findVertexInList(s);
}
