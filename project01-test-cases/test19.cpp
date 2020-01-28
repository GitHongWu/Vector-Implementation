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


TEST_CASE("Test 19", "[Project01]")
{
  myvector<int>  V;

  int N = 120;

  for (int i = 0; i < N; i++)
    V.push_back(i+1);

  REQUIRE(V.size() == N);

  // delete every other element:
  for (int i = N-1; i >= 0; i = i - 2)
  {
    int x = V.erase(i);

    REQUIRE(x == (i + 1));
  }

  // make sure remaining elements are correct:
  REQUIRE(V.size() == (N/2));

  for (int i = 0; i < N / 2; i++)
    REQUIRE(V[i] == (2*i + 1));
}
