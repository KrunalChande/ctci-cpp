/*
 * @Name        : testBinaryTree.cpp
 * @Author      : Krunal Chande
 * @Created     : Mar 11, 2015
 * @Description : 
 */

#include <myADTs/BinaryTree.h>
#include <CppUnitLite/TestHarness.h>
#include <string>
using namespace myADTs;
using namespace std;
/* ************************************************************************* */
TEST (BinaryTree, insert) {
	  BinaryTree<int> binaryTree;
	  binaryTree.insert(10);
	  binaryTree.insert(11);
	  binaryTree.insert(7);
	  binaryTree.insert(12);
	  binaryTree.insert(1);
	  binaryTree.insert(3);
	  binaryTree.inorder();
}

/* ************************************************************************* */
TEST (BinaryTree, remove) {
      BinaryTree<int> binaryTree;
      binaryTree.insert(10);
      binaryTree.insert(11);
      binaryTree.insert(7);
      binaryTree.insert(12);
      binaryTree.insert(1);
      binaryTree.insert(3);
      binaryTree.remove(11);
      binaryTree.inorder();
}

/* ************************************************************************* */
TEST (BinaryTree, constructor) {
      BinaryTree<int> binaryTree;
      binaryTree.insert(10);
      binaryTree.insert(11);
      binaryTree.insert(7);
      binaryTree.insert(12);
      binaryTree.insert(1);
      binaryTree.insert(3);
}

TEST (BinaryTree, stringTest) {
      BinaryTree<string> binaryTree;
      binaryTree.insert("The");
      binaryTree.insert("cake");
      binaryTree.insert("is");
      binaryTree.insert("a");
      binaryTree.insert("lie");
      binaryTree.inorder();
}

/* ************************************************************************* */
int main() {
  TestResult tr;
  return TestRegistry::runAllTests(tr);
}
/* ************************************************************************* */
