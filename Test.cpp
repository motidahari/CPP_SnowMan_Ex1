 /**
  * Snowman Tests
  * CPP course, Ariel University
  * For the full documentation visit: https://codegolf.stackexchange.com/questions/49671/         do-you-want-to-code-a-snowman

  * Created by: Moti Dahari
  * https://github.com/motidahari
  */
 

// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stdlib.h> 
// #include "snowman.hpp"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std; 
using namespace ariel;


/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string str){
  str.erase(remove(str.begin(), str.end(), ' '), str.end());
  str.erase(remove(str.begin(), str.end(), '\t'), str.end());
  str.erase(remove(str.begin(), str.end(), '\n'), str.end());
  str.erase(remove(str.begin(), str.end(), '\r'), str.end());
  return str;
}


/**
 * This test runs on an array of CorrectNumbers (whose range is not 1-4)
 */
TEST_CASE("Check Correct Numbers"){
    CHECK(nospaces(snowman(13231112)) == nospaces(" _===_ (o_O) <( : )> (" ")"));
    CHECK(nospaces(snowman(11114411)) == nospaces("  _===_ (.,.)  ( : )  ( : )"));
    CHECK(nospaces(snowman(33232124)) == nospaces("  ___  /_\\(o_O)  (] [)> (   )"));
    CHECK(nospaces(snowman(12222212)) == nospaces("  _===_\\(o.o)/ ( : )  (" ")"));
    CHECK(nospaces(snowman(42232124)) == nospaces("   _ (_*_)\\(o.O)  (] [)> (   )"));
    CHECK(nospaces(snowman(32443333)) == nospaces("  ___  /_\\ (-.-) /(> <)\\ (___)"));
    CHECK(nospaces(snowman(44444432)) == nospaces("   _(_*_) (- -)  (> <)  (" ")"));
    CHECK(nospaces(snowman(44114432)) == nospaces("   _ (_*_) (. .)  (> <)  (" ")"));
}

/**
 * This test runs on an array of IncorrectNumbers (whose range is not 1-4)
 */
TEST_CASE("Check Incorrect Numbers"){
  int size = sizeof(IncorrectNumbers)/sizeof(IncorrectNumbers[0]);
  for (size_t i = 0; i < size; i++){
    CHECK_THROWS(snowman(IncorrectNumbers[i]));
  }
}



/**
 * This test runs on an array of NegativeNumbers and check the function snowman
 */
TEST_CASE("Check Negative Numbers"){
  int size = sizeof(NegativeNumbers)/sizeof(NegativeNumbers[0]);
  for (size_t i = 0; i < size; i++){
    CHECK_THROWS(snowman(NegativeNumbers[i]));
  }
}


/**
 * This test runs on an array of smallerThan8Characters and check the function snowman
 */
TEST_CASE("Check smaller Than 8 Characters Numbers"){
  int size = sizeof(smallerThan8Characters)/sizeof(smallerThan8Characters[0]);
  for (size_t i = 0; i < size; i++){
    CHECK_THROWS(snowman(smallerThan8Characters[i]));
  }
}


/**
 * This test runs on an array of biggerThan8Characters and check the function snowman
 */
TEST_CASE("Check bigger Than 8 Characters Numbers"){
  int size = sizeof(biggerThan8Characters)/sizeof(biggerThan8Characters[0]);
  for (size_t i = 0; i < size; i++){
    CHECK_THROWS(snowman(biggerThan8Characters[i]));
  }
}

