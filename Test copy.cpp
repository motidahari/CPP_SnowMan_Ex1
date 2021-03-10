#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stdlib.h> 
#include "snowman.hpp"
#include <iostream>
#include <string>
using namespace std;





int[] arrayNum = {
  11111111,
  21111111,
  31111111,
  41111111,
  42111111,
  43111111
  };

string[] arrayPrint = {
  " _===_\n (.,.)\n<( : )>\n ( : )",
  "  ___\n .....\n (.,.)\n<( : )>\n ( : )\n",
  "   _\n   /_\\n (.,.)\n<( : )>\n ( : )\n",
  "  ___ \n (_*_)\n (.,.)\n<( : )>\n ( : )\n ",
  "  ___\n (_*_)\n (o,.)\n<( : )>\n ( : )\n",
  "  ___\n (_*_)\n (O,.)\n<( : )>\n ( : )\n"
};


int getRandomNum(int size) {//1-4
    int number = 0;
    for (size_t i = 0; i < size; i++){
        number *= 10;
        number += (rand() % 4 + 1);//generate number between 1 and 10:
    }
    return number;
}
int getRandomNum2(int size) {//1-10
    int number = 0;
    for (size_t i = 0; i < size; i++){
        number *= 10;
        number += (rand() % 4 + 1);//generate number between 1 and 10:
    }
    return number;
}
int checkSize(int x){
    std::string text = "";
    text += std::to_string(x);
    return (text.size() == 8) ? 1 : -1;
}
int checkValue(int x){
  
  std::string text = "";
  text += std::to_string(x);
  if(text.size() != 8){
    return -1;
  }
  for (size_t i = 0; i < text.size(); i++){
    if (text[i] < 49 || text[i] > 52){
      return -1;
    }
  }
  return 1;
}

// TEST_CASE("testing the length") {
//     for (size_t i = 0; i < 10; i++){
//         int a = getRandomNum(i);
//         bool FLAG = checkSize(a);
//         if(i != 8){
//             CHECK(FLAG == false);
//         }else{
//             CHECK(FLAG == true);
//         }
//     }
// }


TEST_CASE("testing the value") {
    for (size_t i = 0; i < 100; i++){
      int num = getRandomNum2(i);
      int flag = checkSize(num);
      if(flag == 1){
        CHECK(flag == 1);
      }else{
        CHECK(flag == -1);
      }
    }
}


TEST_CASE("testing the result of snowMan") {
  int size = (sizeof(arrayNum)/sizeof(*arrayNum));
    for (size_t i = 0; i < size; i++){
      int flag = checkSize(num); 
      if(flag == 1){
        cout << "checkSize = " << flag <<"\n";
        cout << "a = " << a <<"\n";
        cout << "checkValue = " << checkValue(a) <<"\n\n";
        CHECK(flag == 1);
        CHECK(nospaces(snowman(arrayNum[i])) == nospaces(arrayPrint[i]));

      }else{
        cout << "checkSize = " << flag <<"\n";
        cout << "a = " << a <<"\n";
        cout << "checkValue = " << checkValue(a) <<"\n\n";
        CHECK(nospaces(snowman(arrayNum[i])) == nospaces(arrayPrint[i]));
      }
    }
}







