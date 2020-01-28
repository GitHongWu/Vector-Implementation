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


TEST_CASE("Test 10", "[Project01]")
{
  int N = 50;
  myvector<int>  V(N);

  REQUIRE(V.size() == N);

  for (int i = 0; i < N; ++i)
    REQUIRE(V[i] == 0);

  for (int i = 0; i < N; ++i)
    V[i] = i * 2;

  for (int i = N - 1; i >= 0; --i)
    REQUIRE(V[i] == i * 2);
}
