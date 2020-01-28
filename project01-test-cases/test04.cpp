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


TEST_CASE("Test 04", "[Project01]")
{
  myvector<int>  V;

  REQUIRE(V.size() == 0);

  V.push_back(123);
  V.push_back(-9);
  V.push_back(451);

  REQUIRE(V.size() == 3);
  REQUIRE(V.at(0) == 123);
  REQUIRE(V.at(1) == -9);
  REQUIRE(V.at(2) == 451);

  V.push_back(-123);
  V.push_back(999);

  REQUIRE(V.size() == 5);
  REQUIRE(V.at(0) == 123);
  REQUIRE(V.at(1) == -9);
  REQUIRE(V.at(2) == 451);
  REQUIRE(V.at(3) == -123);
  REQUIRE(V.at(4) == 999);
}
