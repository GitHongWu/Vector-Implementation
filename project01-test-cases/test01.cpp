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


TEST_CASE( "Test 01", "[Project01]" ) 
{
  myvector<int>  V;
           
  REQUIRE(V.size() == 0);
}
