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


TEST_CASE("Test 02", "[Project01]")
{
  myvector<int>  V(25);

  REQUIRE(V.size() == 25);

  for (int i = 0; i < 25; ++i)
    REQUIRE(V.at(i) == 0);
}
