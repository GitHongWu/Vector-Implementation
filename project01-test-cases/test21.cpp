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


TEST_CASE("Test 21", "[Project01]")
{
  myvector<int>  V;

  int N = 10;

  for (int i = 0; i < N; i++)
    V.push_back(i * 2);

  REQUIRE(V.size() == N);

  //
  // test interaction between .at() and [] and erase:
  //
  int x = V.at(2);
  int y = V.at(3);
  int z = V.at(4);

  REQUIRE(x == 4);
  REQUIRE(y == 6);
  REQUIRE(z == 8);

  // if vector is remembering last position, that's 4
  // so let's delete @ position 2 and make sure state 
  // is cleared / updated to remain correct:

  x = V.erase(2);

  REQUIRE(x == 4);

  // now everything to right should have moved left 1 position,
  // and any "last index" state invalidated (or updated) because 
  // positions have shifted:
  REQUIRE(V.size() == 9);

  int a = V.at(5);  // is now 12 since things shifted left:
  REQUIRE(a == 12);

  int b = V.at(1);
  REQUIRE(b == 2);
}
