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


TEST_CASE("Test 14", "[Project01]")
{
  myvector<int>  V;

  int N = 100;

  for (int i = 0; i < N; i++)
    V.push_back(i * 10);

  REQUIRE(V.size() == N);

  // all 100 elements:
  int* C = V.rangeof(0, 99);

  for (int i = 0; i <= 99; ++i)
    REQUIRE(C[i] == (i * 10));
}
