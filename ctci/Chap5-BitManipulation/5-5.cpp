/*
 * @Name        : 5-5.cpp
 * @Author      : Krunal Chande
 * @Created     : Mar 15, 2015
 * @Description : Number of bit flips required to change a number from A to B
 */

/**
 * Figure out the different bits using XOR
 */
#include <CppUnitLite/TestHarness.h>
#include <iostream>

int bitFlipsSimple(int a, int b) {
  int count = 0;
  for (int c = a ^ b; c != 0; c = c >> 1) {
    count += c & 1;
  }
  return count;
}

/**
 * c & (c-1) sets the least significant bit to zero. Doing it until c is 0 gives
 * the answer
 * @param a
 * @param b
 * @return
 */
int bitFlip2(int a, int b) {
  int count = 0;
  for (int c = a ^ b; c != 0; c = c & (c-1)) {
    count++;
  }
  return count;
}

/* ************************************************************************* */
TEST (bitFlips, simple) {
  int a = 0b1011;
  int b = 0b1111;
  int expected = 1;
  int actual = bitFlipsSimple(a, b);
  CHECK_EQUAL(expected, actual);
}

/* ************************************************************************* */
TEST (bitFlips, second) {
  int a = 0b1011;
  int b = 0b1111;
  int expected = 1;
  int actual = bitFlip2(a, b);
  CHECK_EQUAL(expected, actual);
}

/* ************************************************************************* */
int main() {
  TestResult tr;
  return TestRegistry::runAllTests(tr);
}
/* ************************************************************************* */
