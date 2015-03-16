/*
 * @Name        : UnderstandingTraits.cpp
 * @Author      : Krunal Chande
 * @Created     : Mar 16, 2015
 * @Description : 
 */

#include <iostream>

using namespace std;

template <typename T>
struct myIs_void {
  static const bool value = false;
};

template <>
struct myIs_void< void > {
  static const bool value = true;
};

template <bool b>
struct algorithm_selector {
  template <typename T>
  static void implementation(T& object) {
    cout << "this generic guy called" << endl;
  }
};

template <>
struct algorithm_selector<true> {
  template<typename T>
  static void implementation(T& object) {
    cout << "specific guy called" << endl;
    object.optimized_implementation();
  }
};


template<typename T>
struct supports_optimised_implementation {
  static const bool value = false;
};

template< typename T >
void algorithm( T& object ) {
  algorithm_selector< supports_optimised_implementation< T >::value >::implementation(object);
}

class ObjectB {
public:
  void optimized_implementation() {
    cout << "optimized implementation in ObjectB" << endl;
  }
};
template<>
struct supports_optimised_implementation< ObjectB > {
  static const bool value = true;
};

class ObjectA {

};


int main() {
  myIs_void<int> m;
  cout << m.value << endl;

  myIs_void<void> n;
  cout << n.value << endl;

  ObjectA a;
  algorithm( a );
  // calls default implementation
  ObjectB b;
  algorithm( b );
  // calls
  // ObjectB::optimised_implementation();
}

