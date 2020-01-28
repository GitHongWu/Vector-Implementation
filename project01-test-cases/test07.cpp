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


TEST_CASE("Test 07", "[Project01]")
{
  myvector<int>  V;

  REQUIRE(V.size() == 0);

  int N = 301;

  for (int i = 0; i < N; ++i)
    V.push_back(-3 * i);

  REQUIRE(V.size() == N);

  for (int i = 0; i < N; ++i)
    REQUIRE(V.at(i) == (-3*i));

  REQUIRE(V.at(1) == -3);
  REQUIRE(V.at(0) == 0);
  REQUIRE(V.at(0) == 0);
  REQUIRE(V.at(300) == -900);
  REQUIRE(V.at(300) == -900);
  REQUIRE(V.at(299) == (-3*299));
  REQUIRE(V.at(150) == -450);

  V.at(0) = -990;
  V.at(1) = -989;
  V.at(300) = 123;
  V.at(299) = 122;
  V.at(150) = 12345;
  V.at(121) = -1;
  V.at(119) = -1;

  REQUIRE(V.at(1) == -989);
  REQUIRE(V.at(0) == -990);
  REQUIRE(V.at(300) == 123);
  REQUIRE(V.at(299) == 122);
  REQUIRE(V.at(150) == 12345);
  REQUIRE(V.at(120) == -360);
}
