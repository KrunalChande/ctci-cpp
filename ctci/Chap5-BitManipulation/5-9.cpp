/*
 * @Name        : 5-9.cpp
 * @Author      : Krunal Chande
 * @Created     : Mar 15, 2015
 * @Description : 
 */

#include <CppUnitLite/TestHarness.h>
#include <vector>
#include <iostream>

using namespace std;

/**
 * Draw a horizontal line from (x1,y) to (x2, y)
 * @param screen
 * @param width
 * @param x1
 * @param x2
 * @param y
 */
void drawHorizontalLine(char* screen, int width, int x1, int x2, int y) {
  int startOffset = x1 % 8;
  int first_full_byte = x1/8;
  if (startOffset != 0) {
    first_full_byte++;
  }
  int end_offset = x2%8;
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



