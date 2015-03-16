/*
 * @Name        : 5-7.cpp
 * @Author      : Krunal Chande
 * @Created     : Mar 15, 2015
 * @Description : 
 */

#include <CppUnitLite/TestHarness.h>
#include <vector>
#include <iostream>

using namespace std;
int findMissing(vector<int> intList, unsigned int column = 0) {
  if (column >= sizeof(int) * 8){
    return 0;
  }
}
/* ************************************************************************* */
TEST (findMissing, test1) {
  cout << "not implemented" << endl;
}
/* ************************************************************************* */
int main() {
  TestResult tr;
  return TestRegistry::runAllTests(tr);
}
/* ************************************************************************* */



