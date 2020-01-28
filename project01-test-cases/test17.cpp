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


TEST_CASE("Test 17", "[Project01]")
{
  myvector<int>  V;

  int N = 50;

  for (int i = 0; i < N; i++)
    V.push_back(2000 - i);

  REQUIRE(V.size() == N);

  int x = V.erase(49);

  REQUIRE(V.size() == (N - 1));
  REQUIRE(x == (2000 - 49));

  for (int i = 0; i < (N-1); ++i)
    REQUIRE(V[i] == (2000 - i));
}
