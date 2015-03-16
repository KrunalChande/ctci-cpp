/*
 * @Name        : MergeSort.cpp
 * @Author      : Krunal Chande
 * @Created     : Mar 16, 2015
 * @Description : Implementing merge sort for funsies
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(const vector<int>& vec, const vector<int>& left, const vector<int>& right) {
  vector<int> result;
  unsigned left_it = 0, right_it = 0;

  while(left_it < left.size() && right_it < right.size()) {
    if (left[left_it] < right[right_it]) {
      result.push_back(left[left_it]);
      left_it++;
    }
    else {
      result.push_back(right[right_it]);
      right_it++;
    }
  }
  while (left_it < left.size()) {
    result.push_back(left[left_it]);
    left_it++;
  }
  while(right_it < right.size()) {
    result.push_back(right[right_it]);
    right_it++;
  }


  for (unsigned i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  cout << "*********" << endl;
  return result;
}

vector<int> merge_sort(const vector<int>& vec) {
  if (vec.size() == 1){
    return vec;
  }

  vector<int>::const_iterator middle = vec.begin() + (vec.size()/2);
  vector<int> left(vec.begin(), middle);
  vector<int> right(middle, vec.end());

  left = merge_sort(left);
  right = merge_sort(right);

  return merge(vec, left, right);
}

int main() {
  vector<int> arr;
  arr.push_back(5);
  arr.push_back(2);
  arr.push_back(4);
  arr.push_back(1);
  arr.push_back(6);
  for (auto i : arr) {
    cout << i << endl;
  }

  vector<int> sortedArr = merge_sort(arr);
  for (auto i : sortedArr) {
      cout << i << endl;
    }
}
