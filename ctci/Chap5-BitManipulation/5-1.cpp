/*
 * @Name        : 5-1.cpp
 * @Author      : Krunal Chande
 * @Created     : Mar 15, 2015
 * @Description : Given 2 nums, and 2 positions fit the second number inside the first one between the given positions
 */

#include <CppUnitLite/TestHarness.h>
#include <iostream>
#include <cmath> // pow

using namespace std;

int updateBits(int m, int n, int i, int j) {
  // Create mask to clear bits from j to i
  int allOnes = ~0; // 111111111111....
  int left = allOnes << (j + 1); // 1s before j and then 0s i.e. == 111000..
  int right = ((1<<i)-1); // 1s after i i.e. == ..00001111
  int mask = left|right; // 11100000111
  int n_cleared = n & mask;
  int m_shifted = m << i;
  return n_cleared | m_shifted;
}

/* ************************************************************************* */
TEST (BitFitting, test1) {
  int m = 19;
  int n = pow(2,10);
  int i = 2;
  int j = 6;
  int expected = 0b10001001100;
  int actual = updateBits(m, n, i, j);
  CHECK_EQUAL(expected, actual);
}
/* ************************************************************************* */
int main() {
  TestResult tr;
  return TestRegistry::runAllTests(tr);
}
/* ************************************************************************* */
