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


TEST_CASE("Test 20", "[Project01]")
{
  myvector<int>  V;

  int N = 10;

  for (int i = 0; i < N; i++)
    V.push_back(i*2);

  REQUIRE(V.size() == N);

  // remove them all:
  for (int i = 0; i < N; ++i)
  {
    int x = V.erase(0);  // keep erasing the first element:

    REQUIRE(x == (i*2));
  }

  REQUIRE(V.size() == 0);

  V.push_back(123);

  REQUIRE(V.size() == 1);
  REQUIRE(V[0] == 123);

  V.push_back(456);

  REQUIRE(V.size() == 2);
  REQUIRE(V[1] == 456);
  REQUIRE(V[0] == 123);

  V.push_back(999);

  REQUIRE(V.size() == 3);
  REQUIRE(V[1] == 456);
  REQUIRE(V[0] == 123);
  REQUIRE(V[2] == 999);
}
