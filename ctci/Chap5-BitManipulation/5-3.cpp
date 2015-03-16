/*
 * @Name        : 5-3.cpp
 * @Author      : Krunal Chande
 * @Created     : Mar 15, 2015
 * @Description : Given a positive integer, print the next smallest and largest number
 *              : that have the same number of 1 bits in their binary representation
 */

#define DEBUG false
#include <CppUnitLite/TestHarness.h>
#include <iostream>
#include <bitset>

using namespace std;

/**
 * Loop through all bits in an integer, check if a bit is set and if it is then increment the set bit count
 * Time Complexity: \Theta(logn) // Upper and lower
 * @param num input number
 * @return number of ones in binary representation
 */
int numOnesSimple(int num) {
  int count = 0;
  while (num) {
    if (DEBUG) cout << "numOnesSimple num: " << num << "\tIn binary: " << bitset<32>(num) << endl;
    // num = 1011 -> num(1011) & 0001 = 0001 -> binary2decimal(0001) = 1
    count += num & 1;

    num = num >>  1; // num => 101
  }
  return count;
}

/**
 * Faster than numOnesSimple, Brian Kernighan's Algorithm subtracts 1 from a num, which toggles all bits
 * till the rightmost set but. Sub a number and do bitwise with itself, unsets the rightmost set bit.
 * Counting the number of times this is executed will give the number of set bits in an integer
 * Time Complexity: O(logn) // Upper bound
 * @param num
 * @return number of set bits in an integer
 */
int numOnesBrianKernighans(int num) {
  int count = 0;
  while(num) {
    if (DEBUG) {
      cout << "num: \t \t" << bitset<16>(num) << "\nnum-1: \t\t" << bitset<16>(num-1) << endl;
      cout << "num&num-1:\t" << bitset<16>(num & (num-1)) << "\n************"<< endl;
    }
    num &= (num-1);
    count++;
  }
  return count;
}

/**
 * Get the next number simply by incrementing and checking the number of ones
 * @param num
 * @return next num
 */
int getNextBruteForce(int num) {
  int numNumOnes = numOnesBrianKernighans(num);

  int currentNum = num + 1;
  int nextNumOnes = numOnesBrianKernighans(currentNum);
  while (nextNumOnes != numNumOnes) {
    currentNum++;
    nextNumOnes = numOnesBrianKernighans(currentNum);
  }
  return currentNum;
}

pair<int, int> getc0Andc1(int num) {
  int c = num;
  int c0 = 0;
  int c1 = 0;
  while (((c&1) == 0) && (c!=0) ){
    c0++;
    c = c >> 1;
  }

  while ((c & 1 ) == 1) {
    c1++;
    c = c >> 1;
  }

  if (c0 + c1 == 31 || c0 + c1 == 0) {
    return make_pair(-1, -1);
  }
  return make_pair(c0, c1);
}

/**
 * More efficient bit manipulative way of finding the num
 * @param num
 * @return next Num
 */
int getNextBitManipulation(int num) {

  auto c0Andc1 = getc0Andc1(num);

  int p = c0Andc1.first + c0Andc1.second; // Position of rightmost non-trailing zero
  num |= (1<<p); // flip it
  num &= ~((1<<p)-1); // clear all bits to the right of p
  num |= (1 << (c0Andc1.second - 1)) - 1; // insert (c1-1) to the right
  return num;
}

int getNextArithmetic(int num) {
  auto c0Andc1 = getc0Andc1(num);
  return num + (1 << c0Andc1.first) + (1 << (c0Andc1.second - 1)) - 1;
}

/* ************************************************************************* */
TEST (numOnesSimple, test1) {
  int num = 11; // 1011
  int expected = 3;
  int actual = numOnesSimple(num);
  CHECK_EQUAL(expected, actual);
}

/* ************************************************************************* */
TEST (numOnesBrianKernighans, test1) {
  int num = 11; // 1011
  int expected = 3;
  int actual = numOnesBrianKernighans(num);
  CHECK_EQUAL(expected, actual);
}

/* ************************************************************************* */
TEST (NextAndPrevNum, nextBrute) {
  int num = 11; // 1011
  int expected = 13; // 111
  int actual = getNextBruteForce(num);
  CHECK_EQUAL(expected, actual);
}

/* ************************************************************************* */
TEST (NextAndPrevNum, nextBitManipulation) {
  int num = 11; // 1011
  int expected = 13; // 111
  int actual = getNextBitManipulation(num);
  CHECK_EQUAL(expected, actual);
}

/* ************************************************************************* */
TEST (NextAndPrevNum, nextArithematic) {
  int num = 11; // 1011
  int expected = 13; // 111
  int actual = getNextArithmetic(num);
  CHECK_EQUAL(expected, actual);
}
/* ************************************************************************* */
int main() {
  TestResult tr;
  return TestRegistry::runAllTests(tr);
}
/* ************************************************************************* */
