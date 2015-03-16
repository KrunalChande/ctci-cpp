/*
 * @Name        : 5-6.cpp
 * @Author      : Krunal Chande
 * @Created     : Mar 15, 2015
 * @Description : swap odd and even bits in an integer
 */

#include <CppUnitLite/TestHarness.h>
#include <iostream>

int swapOddEvenBits(int x) {
  return ( ((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1) );
}

/* ************************************************************************* */
TEST (swapOddEven, swapOddEvenBits) {
  int num = 0b1011;
  int expected = 0b0111;
  int actual = swapOddEvenBits(num);
  CHECK_EQUAL(expected, actual);
}
/* ************************************************************************* */
int main() {
  TestResult tr;
  return TestRegistry::runAllTests(tr);
}
/* ************************************************************************* */
