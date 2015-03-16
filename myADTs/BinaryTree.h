/*
 * @Name        : BinaryTree.h
 * @Author      : Krunal Chande
 * @Created     : Jan 16, 2015
 * @Description : BinaryTree class and some supporting functions. Based on the
 *                implementation from
 *                http://www.cs.armstrong.edu/liang/cpp3e/html/BinaryTree.htm?
 */

#pragma once

#include <iostream>
#include <memory>
#include <vector>

#ifndef DEBUG
#define DEBUG false
#endif

namespace myADTs {

/**
 * My BinaryTree implementation.
 */
template<typename T>
class BinaryTree {

  /**
   * BinaryTree consists of templated elements called TreeNode(s)
   */
//  template<typename dataType>
  class TreeNode {
  protected:
    friend class BinaryTree<T> ;
    typedef std::shared_ptr<TreeNode> ptr; // TODO! UGLY! How to get rid of this or same thing copied in class BinaryTree?
    T element_;
    ptr left_, right_;
  public:

    /**
     * @brief Templated constructor over the type of element to store
     * @param element object of any type
     */
    TreeNode(T element) :
        element_(element), left_(nullptr), right_(nullptr) {
    }
  };

  /**
   * Iterator which takes a function argument (TODO) and passes each node element
   * as a parameter to that function
   */
  class Iterator {
  private:
    int current_;
  public:
    /**
     *
     * @param p
     */
    Iterator(TreeNode *p) {
      if (p == NULL)
        current_ = -1;
      else {
        // get all nodes
      }
    }
  };

  typedef std::shared_ptr<TreeNode> ptr;
  ptr root_;
  size_t size_;

  /**
   * create a node with the new specified element
   * @param value
   * @return shared pointer to the new node
   */
  ptr createNewNode(T value) {
    return ptr(new TreeNode(value));
  }
public:
  BinaryTree() :
      root_(nullptr), size_(0) {
  }

  /**
   *
   * @param binTree
   */
  BinaryTree(const BinaryTree<T>& binTree) :
      root_(copy(binTree.root_)), size_(0) {
  }
  bool insert(T value);

  void copy(const ptr root);

  bool remove(T value);


  void inorder() const {
    inorder(root_);
  }
  bool isBalancedInefficient() const {
    return isBalancedInefficient(root_);
  }

  bool isBalanced() const {
    return isBalanced(root_);
  }

  int height() const {
    return height(root_);
  }

  void print() const {
    std::cout << "****************" << std::endl;
    print(root_, 0);
  }

private:
  void inorder(ptr node) const;
  bool isBalanced(ptr node) const;
  bool isBalancedInefficient(ptr node) const;
  int checkHeight(ptr node) const;
  int height(ptr node) const;
  void print(ptr node, int depth) const;
};
} // end namespace myADTs

#include "BinaryTree-impl.cpp"
