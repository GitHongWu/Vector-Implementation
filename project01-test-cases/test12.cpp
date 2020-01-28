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


TEST_CASE("Test 12", "[Project01]")
{
  myvector<int>  V;

  int N = 100;

  for (int i = 0; i < N; i++)
    V.push_back(i * 10);

  REQUIRE(V.size() == N);

  // range of 10 elements [0..9]:
  int* A = V.rangeof(0, 9);

  for (int i = 0; i < 10; ++i)
    REQUIRE(A[i] == (i * 10));
}
