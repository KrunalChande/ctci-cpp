/*
 * @Name        : QuickSort.cpp
 * @Author      : Krunal Chande
 * @Created     : Mar 16, 2015
 * @Description : 
 */

#include <iostream>

using namespace std;

template<typename BidirectionalIterator, typename Compare>
void quickSort(BidirectionalIterator first, BidirectionalIterator last, Compare cmp) {
  if (first != last) {
    BidirectionalIterator left = first;
    BidirectionalIterator right = last;
    BidirectionalIterator pivot = left++;

    while (left != right) {
      if (cmp(*left, *pivot)) {
        ++left;
      }
      else {
        while ((left != right) && cmp(*pivot, *right))
          --right;
        iter_swap(left, right);
      }
    }
    --left;
    iter_swap(pivot, left);

    quickSort(first, last, cmp);
    quickSort(right, last, cmp);
  }
}


template<typename BidirectionalIterator >
inline void quick_sort(BidirectionalIterator first, BidirectionalIterator last) {
  quickSort(first, last, less_equal < typename std::iterator_traits <BidirectionalIterator>::value_type > ());
}

int Partition(int* A, int start, int end) {
  int pivot = A[end];
  int partitionIndex = start;
  for (int i = start; i < end; i++) {
    if (A[i] < pivot) {
      partitionIndex++;
    }
  }
  swap(A[partitionIndex], A[end]);
  return partitionIndex;
}

void QuickSort(int* A, int start, int end) {
  if (start < end) {
    int partitionIndex = Partition(A, start, end);
    QuickSort(A, start ,partitionIndex - 1);
    QuickSort(A, partitionIndex+1, end);
  }
}

int main() {
  int A[] = {7,6,5,4,3,2,1,0, 8, 12};
  QuickSort(A, 0, 9);
  for (int i = 0; i < 10; i ++) cout << A[i] << " " << endl;
}
