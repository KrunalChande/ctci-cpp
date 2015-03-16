/*
 * @Name        : 9-1.cpp
 * @Author      : Krunal Chande
 * @Created     : Mar 15, 2015
 * @Description : Number of ways to sum to n using steps of 1, 2 and 3
 */

#include <CppUnitLite/TestHarness.h>
#include <map>
#include <iostream>

using namespace std;
int n = 10;
int numSimpleCalls = 0;
int numDPCalls = 0;

/**
 * The complexity for this approach is exponential, specifically O(3^N)
 * @param n
 * @return
 */
int countWaysSimple(int n) {
  numSimpleCalls++;
  if (n < 0) {
    return 0;
  }
  else if (n == 0) {
    return 1;
  }
  else
    return countWaysSimple(n-1) + countWaysSimple(n-2) + countWaysSimple(n-3);
}


int countWaysDP(int n, map<int, int>& map) {
  numDPCalls++;
  if (n < 0) return 0;
  if (n == 0) return 1;
  else if (map.find(n) != map.end()) {
    return map[n];
  }
  else {
    map[n] = countWaysDP(n-1, map) +
             countWaysDP(n-2, map) +
             countWaysDP(n-3, map);
    return map[n];
  }
}
/* ************************************************************************* */
TEST (numWays, countWaysSimple) {
  cout << "countWaysSimple: " << countWaysSimple(n) << endl;
  cout << "numSimpleCalls: " << numSimpleCalls << endl;
}

/* ************************************************************************* */
TEST (numWays, countWaysDP) {
  map<int, int> map;
  cout << "countWaysDP: " << countWaysDP(n, map) << endl;
  cout << "numDPCalls: " << numDPCalls << endl;
}
/* ************************************************************************* */
int main() {
  TestResult tr;
  return TestRegistry::runAllTests(tr);
}
/* ************************************************************************* */
