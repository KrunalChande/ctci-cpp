/*
 * BinaryTree-impl.cpp
 *
 *  Created on: Mar 14, 2015
 *      Author: krunal
 */
#include <algorithm>    // max
#include <iomanip> // setw

using namespace std;

namespace myADTs {

/* ************************************************************************* */
template<typename T>
void BinaryTree<T>::inorder(ptr node) const {
  if (DEBUG)
    cout << "inorder" << endl;
  if (node == NULL) {
    if (DEBUG)
      cout << "null node" << endl;
    return;
  }
  inorder(node->left_);
  cout << node->element_ << " " << endl;
  inorder(node->right_);
}

/* ************************************************************************* */
template<typename T>
bool BinaryTree<T>::remove(T value) {
  ptr parent = NULL;
  ptr current = root_;
  while (current != NULL) {
    if (value < current->element_) {
      parent = current;
      current = current->left_;
    } else if (value > current->element_) {
      parent = current;
      current = current->right_;
    } else
      break; // element exists in the tree
  }
  if (current == NULL)
    return false;
  if (current->left_ == NULL) {
    if (parent == NULL) {
      root_ = current->right_;
    } else {
      if (value < parent->element_) {
        parent->left_ = current->right_;
      } else
        parent->right_ = current->right_;
    }
  } else {
    // Case 2: The current node has a left child
    ptr parentOfRightMost = current;
    ptr rightMost = current->left_;

    while (rightMost->right_ != NULL) {
      parentOfRightMost = rightMost;
      rightMost = rightMost->right_; // Keep going to the right
    }

    // Replace the element in current by the element in rightMost
    current->element_ = rightMost->element_;

    // Eliminate rightmost node
    if (parentOfRightMost->right_ == rightMost)
      parentOfRightMost->right_ = rightMost->left_;
    else
      // Special case: parentOfRightMost->right == current
      parentOfRightMost->left_ = rightMost->left_;
  }
  size_--;
  return true; // Element inserted
}

/* ************************************************************************* */
template<typename T>
bool BinaryTree<T>::insert(T value) {
  if (root_ == NULL) {
    root_ = createNewNode(value);
    if (DEBUG)
      cout << root_->element_ << endl;
  } else {
    ptr parent = nullptr;
    ptr current = root_;
    while (current != NULL) {
      if (value < current->element_) {
        parent = current;
        current = current->left_;
      } else if (value > current->element_) {
        parent = current;
        current = current->right_;
      } else
        return false;
    }

    if (value < parent->element_)
      parent->left_ = createNewNode(value);
    else
      parent->right_ = createNewNode(value);
  }
  size_++;
  if (DEBUG)
    cout << "size: " << size_ << endl;
  return true;
}

/* ************************************************************************* */
template<typename T>
void BinaryTree<T>::copy(const ptr root) {
  if (root != NULL) {
    insert(root->element_);
    copy(root->left_);
    copy(root->right_);
  }
}

/* ************************************************************************* */
template<typename T>
bool BinaryTree<T>::isBalancedInefficient(ptr node) const {
  if (node == NULL)  return true;

  int heightDiff = height(node->left_) - height(node->right_);
  if (abs(heightDiff) > 1) return false;
  else
    return isBalancedInefficient(node->left_) && isBalancedInefficient(node->right_);
}

/* ************************************************************************* */
template<typename T>
int BinaryTree<T>::height(ptr node) const {
  if (node == NULL) return 0;
  else
    return max(height(node->left_), height(node->right_)) + 1;
}

/* ************************************************************************* */
template<typename T>
bool BinaryTree<T>::isBalanced(ptr node) const {
  if (checkHeight(node) == -1) return false;
  else return true;
}

/* ************************************************************************* */
template<typename T>
int BinaryTree<T>::checkHeight(ptr node) const {
  if (node == NULL) return 0;

  // Check if left tree is balanced
  int leftHeight = checkHeight(node->left_);
  if (leftHeight == -1) return -1;

  // Check if right tree is balanced
  int rightHeight = checkHeight(node->right_);
  if (rightHeight == -1) return -1;

  // Check if current node is balanced
  int heightDiff = leftHeight - rightHeight;
  if (abs(heightDiff) > 1) return -1;
  else return max(leftHeight, rightHeight) + 1;
}

/* ************************************************************************* */
template<typename T>
void BinaryTree<T>::print(ptr node, int depth) const{
  if (node != NULL) {
    print(node->right_, depth + 1);
    cout << setw(4*depth) << "";
    cout << node->element_ << endl;
    print(node->left_, depth + 1);
  }
}
}
