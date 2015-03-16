/*
 * @Name        : HashMap.h
 * @Author      : Krunal Chande
 * @Created     : Jan 18, 2015
 * @Description : 
 */

#pragma once
#include <memory>

#define TABLE_SIZE 100

namespace myADTs {
/**
 * HashNode represents a bucketnode in the HashTable
 */
template<typename T>
class HashNode {
private:
  size_t key_;
  T value_;
  typedef std::shared_ptr<HashNode<T> > HashNodePtr;
  HashNodePtr next_;
public:
  HashNode() :
      key_(0) {
  }

  HashNode(const size_t key, const T& value) :
      key_(key), value_(value), next_(nullptr) {
  }

  /// Accessor function to get key
  size_t key() {
    return key_;
  }

  /// Accessor function to get value
  T value() {
    return value_;
  }

  /// Function to set
  void set(T newVal) {
    value_ = newVal;
  }

  /// Returns a shared_ptr to the next element
  HashNodePtr next() {
    return next_;
  }

  /// Set the next element
  void setNext(HashNodePtr newNode) {
    next_ = newNode;
  }

  template<typename U, typename F>
  friend class HashMap;
};

unsigned long HashKey(size_t key) {
  return key % TABLE_SIZE;
}

template<typename T, typename F>
class HashMap {
public:
  HashMap() {
//    HashNode<T>* a = new HashNode<T>();
    std::shared_ptr<HashNode<T> > table1 = std::make_shared<HashNode<T> >();
//    table1->
  }
  void put(size_t key, T& value) {
    size_t hashKey = hashFunc_(key);
    HashNodePtr current = table_[hashKey];
    HashNodePtr previous = nullptr;
    while (current != nullptr && current.key() != key) {
      previous = current;
      current = previous.next();
    }
    if (current == NULL) {
      current = new HashNode<T>(value);
      if (previous == nullptr) {
        table_[hashKey] = current;
      } else {
        previous->next(current.next());
      }
    } else
      current->value(value);
  }
private:
  typedef std::shared_ptr<HashNode<T> > HashNodePtr;
//  std::shared_ptr < HashNodePtr > table_; // **table_
  HashNodePtr table_;
  F hashFunc_;
};
}
