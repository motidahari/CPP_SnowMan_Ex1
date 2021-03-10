 /**
  * Snowman
  * Create a snowman by getting a positive number with 8 digits in the range of 1-4
  * CPP course, Ariel University
  * For more documentation visit: 
  * https://codegolf.stackexchange.com/questions/49671/do-you-want-to-code-a-snowman
  * Created by: Moti Dahari
  * https://github.com/motidahari
  */
 
#include <iostream>
#include <string>
// #include <iostream>
#include <stdexcept>
#include "snowman.hpp"
#include <regex>
#include <algorithm>

using namespace std;
//Proper length of the number
const int ProperNumberOfCharacters = 8;

//arrays that represents a string of parts of the snowman's body
const string Hat[4] = {" _===_\n", "  ___\n .....\n", "   _ \n  /_\\\n", "  ___ \n (_*_)\n"};
const string LeftEye[4] = {".", "o", "O", "-"};
const string Mouth[4] = {",", ".", "_", " "};
const string RightEye[4] = {".", "o", "O", "-"};
const string LeftArm[5] = {"<", "\\", "/", " ", "\\"};
const string Torso[4] = {" : ", "] [", "> <", "   "};
const string RightArm[5] = {">", "/", "\\", " ", "/"};
const string Base[4] = {" ( : )", " (   )", " (___)", " (   )"};

/**
 * getIndex - Gets a char which represents a number (from ascii table) and returns its numeric value less 1
 * For example: if we get "1" we return 0, if we get "2" we return 1..
 * @param: c - char which represents a number
 * @return: index - The value from the ascii table is less than 1
 */
int getIndex(char c){
  int ascii = c;
  if (ascii >= 49 && ascii <= 52){
    switch (ascii - 1){
    case 48:
      return 0;
      break;
    case 49:
      return 1;
      break;
    case 50:
      return 2;
      break;
    case 51:
      return 3;
      break;
    }
  }
  return -1;
}


/**
 * checkNegativeNumber - Check whether the number is a negative number or not
 * @param: num - A number
 * @return: 1 - if it is a positive number, -1 if isn't.
 */
int checkNegativeNumber(int num){
  if(num <= 0){
    throw invalid_argument{"Error: The number is a negative number\n"};
    return -1;
  }else{
    return 1;
  }
}

/**
 * checkSize - Check whether the string size is 8
 * @param: x - A String
 * @return: 1 - If the string length is exactly 8, -1 if isn't.
 */
int checkSize(string x){
  if(x.size() > ProperNumberOfCharacters){
    throw invalid_argument{"Error: The number of characters is greater than 8\n"};
    return -1;
  }else if(x.size() < ProperNumberOfCharacters){
    throw invalid_argument{"Error: The number of characters is less than 8\n"};
    return -1;
  }
  return 1;
}

/**
 * checkValue - Check if all the characters in the string are in the range of 1-4
 * @param: x - A String
 * @return: 1 - If the string is really in the 1-4 range, -1 if isn't.
 */
int checkValue(string x){
  for (size_t i = 0; i < x.size(); i++){
    if (x[i] < 49 || x[i] > 52){
      throw invalid_argument{"Error: The input is not in the 1-4 range\n"};
      return -1;
    }
  }
  return 1;
}


/**
 * getRandomNum - Produces a random number in the range 1-4
 * @param: size - The number of characters in the number
 * @return: number - Positive number
 */
int getRandomNum(int size) {//1-4
    int number = 0;
    for (size_t i = 0; i < size; i++){
        number *= 10;
        number += (rand() % 4 + 1);//generate number between 1 and 4:
    }
    return number;
}

/**
 * getRandomNumFrom1To10 - Produces a random number in the range 1-10
 * @param: size - The number of characters in the number
 * @return: number - Positive number
 */
int getRandomNumFrom1To10(int size) {//1-10
    int number = 0;
    for (size_t i = 0; i < size; i++){
        number *= 10;
        number += (rand() % 4 + 1);//generate number between 1 and 10:
    }
    return number;
}

namespace ariel{
  /**
   * snowman - A function that receives a number, checks whether the input is correct, if the input is 
   * incorrect it throws an error, if the input is correct it returns a string representing a snowman 
   * which is constructed by each character in the string
   * @param: num - A number
   * @return: snowMan - A string representing a snowman, empty string and trow error if isn't.
   */
  string snowman(int num){
    string str = std::to_string(num);
    string result = "";

    if(checkNegativeNumber(num) != -1 && checkValue(str) != -1 && checkSize(str) != -1){
      int UpLeftArm = (str[4] == '2') ? 1 : 0;
      int UpRightArm = (str[5] == '2') ? 1 : 0;
      for (size_t i = 0; i < str.size(); i++){
        int index = getIndex(str[i]);
        if (i == 0){
          result += Hat[index];
        }else if (i == 1){
          if (UpLeftArm == 1){
            result += LeftArm[4] + "(" + LeftEye[index];
          }else{
          result += " (" + LeftEye[index];
          }
        }else if (i == 2){
          result += Mouth[index];
        }else if (i == 3) {
          if (UpRightArm == 1){
            result += RightEye[index] + ")" + RightArm[4] + "\n";
          }else{
            result += RightEye[index] + ")\n";
          }
        }else if (i == 4){
          if (UpLeftArm != 1){
            result += LeftArm[index];
          }else{
            result += " ";
          }
        }else if (i == 5){
          if (UpRightArm != 1){
            result += "(" + Torso[index] + ")";
          }else{
            result += "(" + Torso[index] + ")\n";
          }
        }else if (i == 6){
          if (UpRightArm != 1){
            result += RightArm[index] + "\n";
          }
        }
        else if (i == 7){
          result += Base[index];
        }
      }
      return result;  
    }
    return "";
  }
};


// int main(){

//   cout << ariel::snowman(33232124);
//   // int size = sizeof(CorrectNumbers)/sizeof(CorrectNumbers[0]);
//   // cout << "size = " << size ;
//   // string a = "";
//   // // cout << "const int arr[] = {";
//   // a +=  "const string snowman[] = {";
//   // for (size_t i = 0; i < size; i++){
//   //     // a +=  "\"" + nospaces(ariel::snowman(CorrectNumbers[i])) + "\"" + ",\n";
//   //     a += "val = " ;
//   //     a +=  "\n" ;
//   //     a +=  "\"" + ariel::snowman(CorrectNumbers[i]) + "\"" + ",\n";
//   //   // cout << ariel::snowman(CorrectNumbers[i]) << ",";
//   // }
//   // a +=   "};";
//   // // cout << "}";
//   // cout << a;
//   return 0;
// }
