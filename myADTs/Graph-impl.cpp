/*
 * @Name        : Graph.cpp
 * @Author      : Krunal Chande
 * @Created     : Jan 18, 2015
 * @Description :
 */

#include <assert.h>
namespace myADTs {
//******************************************************************************
template<class Item>
void Graph<Item>::add_vertex(const Item& label) {
  size_t new_vertex_number = many_vertices_;
  size_t other_number;
  assert(many_vertices_ < max_);
  many_vertices_++;
  for (other_number = 0; other_number < many_vertices_; other_number++) {
    edges_[other_number][new_vertex_number] = false;
    edges_[new_vertex_number][other_number] = false;
  }
  labels_[new_vertex_number] = label;
}

//******************************************************************************
template<class Item>
void Graph<Item>::add_edge(size_t source, size_t target) {
  std::cout << size() << std::endl;
  assert(source < size());
  assert(target < size());
  edges_[source][target] = true;
  if (graphType_ == undirected)
    edges_[target][source] = true;
}

//******************************************************************************
template<class Item>
void Graph<Item>::remove_edge(size_t source, size_t target) {
  assert(source < size());
  assert(target < size());
  edges_[source][target] = false;
  if (graphType_ == undirected)
    edges_[target][source] = false;
}

//******************************************************************************
template<class Item>
Item& Graph<Item>::operator [](size_t vertex) {
  assert(vertex < size());
  return labels_[vertex];
}

//******************************************************************************
template<class Item>
bool Graph<Item>::is_edge(size_t source, size_t target) {
  assert(source < size());
  assert(target < size());

  return edges_[source][target];
}
}
