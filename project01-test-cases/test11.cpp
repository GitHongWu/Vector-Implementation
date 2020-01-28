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


TEST_CASE("Test 11", "[Project01]")
{
  myvector<int>  V(25);

  REQUIRE(V.size() == 25);

  for (int i = 0; i < 25; ++i)
    REQUIRE(V[i] == 0);

  // copy constructor:
  myvector<int>  V2 = V;

  REQUIRE(V2.size() == 25);

  for (int i = 0; i < 25; ++i)
    REQUIRE(V2[i] == 0);

  V2[0] = 999;
  V2[1] = 998;
  V2[24] = 222;
  V2[12] = 989;
  V2[11] = 990;

  for (int i = 0; i < 25; ++i)
  {
    if (i == 0)
      REQUIRE(V2[0] == 999);
    else if (i == 1)
      REQUIRE(V2[1] == 998);
    else if (i == 11)
      REQUIRE(V2[11] == 990);
    else if (i == 12)
      REQUIRE(V2[12] == 989);
    else if (i == 24)
      REQUIRE(V2[24] == 222);
    else
      REQUIRE(V2[i] == 0);
  }

  // make sure original vector didn't change:
  for (int i = 0; i < 25; ++i)
    REQUIRE(V[i] == 0);
}
