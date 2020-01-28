//
// Prof. Joe Hummel
// U. of Illinois, Chicago
// CS 251, Fall 2019
// Project #01: myvector
// 

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

#include "myvector.h"
#include "catch.hpp"

using namespace std;


TEST_CASE("Test 15", "[Project01]")
{
  myvector<int>  V;

  int N = 100;

  for (int i = 0; i < N; i++)
    V.push_back(i * 10);

  REQUIRE(V.size() == N);

  // range of 10 elements [2..12]:
  int* A = V.rangeof(2, 12);

  // just one element:
  int* B = V.rangeof(99, 99);

  // all 100 elements:
  int* C = V.rangeof(0, 99);

  for (int i = 2; i <= 12; ++i)
    REQUIRE(A[i-2] == (i * 10));

  REQUIRE(B[0] == (99 * 10));

  for (int i = 0; i <= 99; ++i)
    REQUIRE(C[i] == (i * 10));
}
