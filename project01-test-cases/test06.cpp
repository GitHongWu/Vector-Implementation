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


TEST_CASE("Test 06", "[Project01]")
{
  int N = 12;
  myvector<int>  V(N);

  REQUIRE(V.size() == N);

  for (int i = 0; i < N; ++i)
    REQUIRE(V.at(i) == 0);

  V.push_back(123);
  V.push_back(-9);
  V.push_back(451);
  V.push_back(-123);
  V.push_back(999);

  REQUIRE(V.size() == (N+5));

  for (int i = 0; i < N; ++i)
    REQUIRE(V.at(i) == 0);

  REQUIRE(V.at(N) == 123);
  REQUIRE(V.at(N + 3) == -123);
  REQUIRE(V.at(N+2) == 451);
  REQUIRE(V.at(N + 1) == -9);
  REQUIRE(V.at(N+4) == 999);

  V.at(2) = -2;

  int M = 184;

  for (int i = 0; i < M; ++i)
    V.push_back(i);

  REQUIRE(V.size() == (N+5+M));

  for (int i = 0; i < N; ++i)
  {
    if (i == 2)
      REQUIRE(V.at(2) == -2);
    else
      REQUIRE(V.at(i) == 0);
  }

  REQUIRE(V.at(N + 4) == 999);
  REQUIRE(V.at(N + 3) == -123);
  REQUIRE(V.at(N + 2) == 451);
  REQUIRE(V.at(N + 1) == -9);
  REQUIRE(V.at(N) == 123);

  for (int i = N + 5, j = 0; i < N + 5 + M; ++i, ++j)
    REQUIRE(V.at(i) == j);
}
