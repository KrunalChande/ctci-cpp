/*
 * @Name        : 4-1.cpp
 * @Author      : Krunal Chande
 * @Created     : Mar 11, 2015
 * @Description : Check if a binary tree is balanced
 */

#define DEBUG false

#include <myADTs/BinaryTree.h>
#include <iostream>

using namespace std;
using namespace myADTs;
int main() {
  BinaryTree<int> binaryTree;
  binaryTree.insert(10);
  binaryTree.insert(11);
  binaryTree.insert(7);
  binaryTree.print();
  cout << "Is tree balanced: " <<  binaryTree.isBalanced() << "\t" << binaryTree.isBalancedInefficient() << endl;
  cout << "height of tree:" << binaryTree.height() << endl;
  binaryTree.insert(12);
  binaryTree.print();
  binaryTree.insert(1);
  binaryTree.print();
  cout << "Is tree balanced: " <<  binaryTree.isBalanced() << "\t" << binaryTree.isBalancedInefficient() << endl;
  cout << "height of tree:" << binaryTree.height() << endl;
  binaryTree.insert(3);
  binaryTree.print();
  cout << "Is tree balanced: " <<  binaryTree.isBalanced() << "\t" << binaryTree.isBalancedInefficient() << endl;
  cout << "height of tree:" << binaryTree.height() << endl;
  return 0;
}
