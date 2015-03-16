/*
 * @Name        : testGraph.cpp
 * @Author      : Krunal Chande
 * @Created     : Mar 14, 2015
 * @Description : 
 */

#include <myADTs/Graph.h>
#include <CppUnitLite/TestHarness.h>
#include <string>
using namespace myADTs;
//using namespace std;
/* ************************************************************************* */

/**
 * 1->2->3<-4   0
 * |     ^
 * - - - |
 */

TEST (Graph, insert) {
  Graph<int> graph(10, GraphType::directed);
  graph.add_vertex(0);
  graph.add_vertex(1);
  graph.add_vertex(2);
  graph.add_edge(1,2);
  graph.add_vertex(3);
  graph.add_edge(2,3);
  graph.add_edge(1,3);
  graph.add_vertex(4);
  graph.add_edge(4,3);
}

/* ************************************************************************* */
int main() {
  TestResult tr;
  return TestRegistry::runAllTests(tr);
}
/* ************************************************************************* */

