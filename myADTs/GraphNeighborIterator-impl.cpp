/*
 * @Name        : NeighborIterator.cpp
 * @Author      : Krunal Chande
 * @Created     : Jan 18, 2015
 * @Description :
 */

#include <assert.h>
namespace myADTs {
//******************************************************************************
template<class T>
GraphNeighborIterator<T>::GraphNeighborIterator(Graph<T>& g) {
  assert(g.size() > 0);
  graph_ptr = std::make_shared < Graph<T> > (g);
  restart(0);
}

//******************************************************************************
template<class T>
void GraphNeighborIterator<T>::advance() {
  assert(!done());
  do {
    my_target = my_target + 1;
  } while (my_target < graph_size() && !graph_ptr->is_edge(my_source, my_target));
}

//******************************************************************************
template<class T>
size_t GraphNeighborIterator<T>::current() {
  assert(!done());
  return my_target;
}

//******************************************************************************
template<class T>
bool GraphNeighborIterator<T>::done() {
  return (my_target == graph_size());
}

//******************************************************************************
template<class T>
void GraphNeighborIterator<T>::restart(size_t source) {
  my_source = source;
  my_target = 0;
  while (my_target < graph_size() && !graph_ptr->is_edge(my_source, my_target)) {
    my_target++;
  }
}
}
