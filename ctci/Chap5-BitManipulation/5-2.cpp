/*
 * @Name        : 5-2.cpp
 * @Author      : Krunal Chande
 * @Created     : Mar 15, 2015
 * @Description : Given a real num between 0 and 1, print the binary representation
 */

#define DEBUG false
#include <CppUnitLite/TestHarness.h>
#include <iostream>
#include <string>

using namespace std;

string printBinary(double num) {
  if (DEBUG) cout << "Num: " << num << endl;

  if (num >= 1 && num <= 0) {
    return string("Error: Number should be between 0 and 1");
  }
  string binaryString = ".";
  double frac = 0.5;
  while (num > 0) {
    if (binaryString.length() >= 32) {
      return "Error: binaryString length exceeds 32";
    }

    if (num >= frac) {
      binaryString.append("1");
      num -= frac;
    }
    else {
      binaryString.append("0");
    }
    frac /= 2;
    if (DEBUG) {
      cout << "binaryString: " << binaryString << endl;
      cout << "r: " << frac << endl;
      cout << "num: " << num << endl;
    }
  }

  return binaryString;
}

/* ************************************************************************* */
TEST (Double2Binary, test1) {
  string actual = printBinary(0.72);
  cout << "actual : " << actual << endl;
  cout << "DOES NOT WORK!!" << endl;
}
/* ************************************************************************* */
int main() {
  TestResult tr;
  return TestRegistry::runAllTests(tr);
}
/* ************************************************************************* */
