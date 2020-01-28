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


TEST_CASE("Test 09", "[Project01]")
{
  myvector<int>  V1;
  myvector<double> V2;
  myvector<char> V3;

  REQUIRE(V1.size() == 0);
  REQUIRE(V2.size() == 0);
  REQUIRE(V3.size() == 0);

  V1.push_back(123);

  REQUIRE(V1.size() == 1);
  REQUIRE(V2.size() == 0);
  REQUIRE(V3.size() == 0);

  V2.push_back(3.14);
  V2.push_back(999.0);

  REQUIRE(V1.size() == 1);
  REQUIRE(V2.size() == 2);
  REQUIRE(V3.size() == 0);
  REQUIRE(V1.at(0) == 123);
  
  V3.push_back('a');
  V3.push_back('-');
  V3.push_back('z');

  REQUIRE(V1.size() == 1);
  REQUIRE(V2.size() == 2);
  REQUIRE(V3.size() == 3);
  REQUIRE(V1.at(0) == 123);
  REQUIRE(V3.at(2) == 'z');
  REQUIRE(V3.at(1) == '-');
  REQUIRE(V3.at(0) == 'a');
}
