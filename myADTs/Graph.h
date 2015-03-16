/*
 * @Name        : Graph.h
 * @Author      : Krunal Chande
 * @Created     : Jan 18, 2015
 * @Description :
 */

#pragma once
#include <iostream>
#include <assert.h>
#include <memory>
#include <vector>
#include <queue>

#ifndef DEBUG
#define DEBUG true
#endif

namespace myADTs {

//******************************************************************************
enum GraphType {
  directed, undirected
};
/**
 * Templated implementation of the graph class. Has functionality such as
 * adding and removing vertices. The edges of the graph are stored in a
 * 2 Dimensional adjacency matrix representation.
 */
template<class Item>
class Graph {
public:

  /**
   * Default Constructor
   */
  Graph() :
      max_(20), many_vertices_(0), graphType_(undirected) {
    if (DEBUG)
      std::cout << "Graph default constructor" << std::endl;
  }

  /**
   * Constructor
   */
  Graph(size_t max, GraphType graphType) :
      max_(max), edges_(max_, std::vector<bool>(max_)), labels_(max_, 0), many_vertices_(
          0), graphType_(graphType) {
    std::cout << "max: " << max_ << std::endl;
    if (DEBUG)
      std::cout << "Graph graphType constructor" << std::endl;
  }

  /**
   * Add a vertex to the graph. It is numbered incrementally.
   * No edges to this vertex are set when it is added.
   * @param label: label of the vertex to store
   */
  void add_vertex(const Item& label);

  /**
   * Add an edge between two vertices. There is a check for the source
   * and target to be within the number of vertices present.
   * @param source: edge from vertex
   * @param target: edge to vertex
   * NOTE!!! TODO: graph is not directional
   */
  void add_edge(size_t source, size_t target);

  /**
   * Removes the edge between two vertices. There is a check for the source
   * and target to be within the number of vertices present.
   * It does nothing if there wasn't an edge present.
   * @param source: edge from vertex
   * @param target: edge to vertex
   */
  void remove_edge(size_t source, size_t target);

  /**
   * Check if there is an edge between the given source and target vertex
   */
  bool is_edge(size_t source, size_t target);

  /**
   * Returns the object at the given vertex
   */
  Item& operator[](size_t vertex);

  /**
   * Return the total number of vertices of the graph
   */
  size_t size() {
    return many_vertices_;
  }

  size_t max_;
private:
//  typedef std::shared_ptr<bool> edgePtr;
//  std::shared_ptr < edgePtr > edges_;// edges are stored in a 2 dimensional matrix representation
  std::vector<std::vector<bool> > edges_;
  std::vector<Item> labels_; // labels_ denote the actual object that is stored
  size_t many_vertices_; // size of the current graph
  GraphType graphType_;
};

//******************************************************************************
/**
 * Iterator for the Graph class. To use call restart() to start, current()
 * to get the object at the current index and advance() to increment.
 */
template<class T>
class GraphNeighborIterator {
public:
  GraphNeighborIterator(Graph<T>& g);
  void restart(size_t vertex_num);
  void advance();
  size_t current();
  bool done();
  size_t graph_size() {
    return graph_ptr->size();
  }
private:
  size_t my_source;
  size_t my_target;
  std::shared_ptr<Graph<T> > graph_ptr;
};


//******************************************************************************
/**
 * Depth First traversal implementation for the Graph class.
 * Uses the NeighborIterator class.
 * @param f: Can pass a single parameter input function
 * @param g: The Graph object to implement search on
 * @param start: The initial index to start search from
 */
template<class Process, class Item, class SizeType>
void depth_first(Process f, Graph<Item>& g, SizeType start) {
  bool marked[g.max_];
  size_t i;
  assert(start < g.size());
  for (int i = 0; i < g.size(); i++)
    marked[i] = false;

  rec_dfs(f, g, start, marked);
}

/**
 * Helper function for the depth_first traversal function. Should not be used explicitly
 * by the end-user.
 * TODO: Add it to some class?
 */
template<class Process, class Item, class SizeType>
void rec_dfs(Process f, Graph<Item>& g, SizeType v, bool marked[]) {
  GraphNeighborIterator<Item> neighbors(g);
  marked[v] = true;
  f(g[v]);
  for (neighbors.restart(v); !neighbors.done(); neighbors.advance()) {
    if (!marked[neighbors.current()])
      rec_dfs(f, g, neighbors.current(), marked);
  }
}

//******************************************************************************
/**
 * Breath First traversal implementation for the Graph class
 * Uses NeighborIterator class to search all neighbors
 * @param f: Can pass a single parameter input function
 * @param g: The Graph object to implement search on
 * @param start: The initial index to start search from
 */
template<class Process, class Item, class SizeType>
void breadth_first(Process f, Graph<Item>& g, SizeType start) {
  bool marked[g.size()];
  size_t v;
  size_t next;
  GraphNeighborIterator<Item> neighbors(g);
  std::queue<size_t> vertex_queue;
  assert(start < g.size());

  for (v = 0; v < g.size(); v++) {
    marked[v] = false;
  }
  marked[start] = true;
  f(g[start]);
  vertex_queue.push(start);
  do {
    v = vertex_queue.front();
    vertex_queue.pop();
    for (neighbors.restart(v); !neighbors.done(); neighbors.advance()) {
      next = neighbors.current();
      if (!marked[next]) {
        marked[next] = true;
        std::cout << "next: " << next << std::endl;
        f(g[next]);
        vertex_queue.push(next);
      }
    }
  } while (!vertex_queue.empty());
}

//******************************************************************************
/**
 * Sample single parameter input function that can be used in conjunction with the
 * search functions. Prints out the value at that vertex.
 * @param g: Vertex of the tree
 */
template<class Item>
void print_value(Item g) {
  std::cout << g << std::endl;
}

/**
 * Test function to check passing of templated functions as parameters
 */
template<class Process, class Item, class SizeType>
void apply(Process f, Item data, SizeType n) {
  size_t i;
  for (i = 0; i < n; i++)
    f((data[n]));
}
}
#include "Graph-impl.cpp"
#include "GraphNeighborIterator-impl.cpp"
