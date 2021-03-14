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
// #include "snowman.hpp"
#include <regex>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stdexcept>
// #include "snowman.hpp"

using namespace std;

const int validInputNumber = 8;

/**
 * All snowman body parts: head=0, nose=1, ... , base=7.
 */
enum parts { head, nose, leftEye, rightEye, leftArm, rightArm, torso, base };

const vector<string> H = {"       \n _===_ ", "  ___  \n ..... ", "   _   \n  /_\\  ", "  ___  \n (_*_) "};
const vector<string> N = {",", ".", "_", " "};
const vector<string> L = {".", "o", "O", "-"};
const vector<string> R = {".", "o", "O", "-"};
const vector<string> X1 = {" ", "\\", " ", " "};
const vector<string> X2 = {"<", " ", "/", " "};
const vector<string> Y1 = {" ", "/", " ", " "};
const vector<string> Y2 = {">", " ", "\\", " "};
const vector<string> T = {" : ", "] [", "> <", "   "};
const vector<string> B = {" : ", "\" \"", "___", "   "};

/**
 * @brief converting char '1'-'5' to its integer representation
 *        after that it decrease 1 from the number to fit the arrays range 0-4.
 *        Example: with the input char '1' the function returns 0.  
 *        Example: with the input char '5' the function returns 4.
 *        etc.  
 * 
 * @param c the char range from '1' to '5'
 * @return int input char represnted as int, minus 1.
 */
int toDigit(char c){
    return (c-'0')-1; 
}
using namespace std;
//Proper length of the number
const int ProperNumberOfCharacters = 8;

//arrays that represents a string of parts of the snowman's body
const string Hat[4] = {" _===_\n", "  ___\n .....\n", "   _ \n  /_\\\n", "  ___ \n (_*_)\n"};
const string LeftEye[4] = {".", "o", "O", "-"};
const string Mouth[4] = {",", ".", "_", " "};
const string RightEye[4] = {".", "o", "O", "-"};
const string LeftArm[5] = {"<", "\\", "/", " "};
const string Torso[4] = {" : ", "] [", "> <", "   "};
const string RightArm[5] = {">", "/", "\\", " "};
const string Base[4] = {" ( : )", " (\" \")", " (___)", " (   )"};

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

string snowmanE(int num){
    string n = to_string(num);
    if(n.size() != validInputNumber){
        throw invalid_argument{"The input number must be positive and have 8 digits range from 1 to 4!\n"};
    }

    //If some digit is NOT in the range 0-3, then an exception will be thrown.
    return H.at(toDigit(n[head])) + "\n"
        + X1.at(toDigit(n[leftArm])) + "(" + L.at(toDigit(n[leftEye])) + N.at(toDigit(n[nose]))+ R.at(toDigit(n[rightEye])) + ")" + Y1.at(toDigit(n[rightArm])) + "\n"
        + X2.at(toDigit(n[leftArm])) + "(" + T.at(toDigit(n[torso])) + ")" + Y2.at(toDigit(n[rightArm])) + "\n"
        + " (" + B.at(toDigit(n[base])) + ") ";
    }

string snowman2(int num){
    string str = std::to_string(num);
    string result = "";
    if(checkNegativeNumber(num) != -1 && checkValue(str) != -1 && checkSize(str) != -1){
      std::string number = "";
      int arr[8];
      for (size_t i = 0; i < str.size(); i++){
        int index = getIndex(str[i]);
        number += std::to_string(index);
        arr[i] = index;
      }
      int UpLeftArm = (str[4] == '2') ? 1 : 0;
      int UpRightArm = (str[5] == '2') ? 1 : 0;
      cout << "number2 = " << number << "\n";
      result += Hat[arr[0]];
      result += (UpLeftArm == 1) ? LeftArm[arr[4]] + "(" + LeftEye[arr[2]] : " (" + LeftEye[arr[2]];
      result += Mouth[arr[1]];
      result += (UpRightArm == 1) ? RightEye[arr[3]] + ")" + RightArm[arr[5]] + "\n" : RightEye[arr[3]] + ")\n";
      result += (UpLeftArm != 1) ? LeftArm[arr[4]] : " ";
      result += (UpRightArm != 1) ? "(" + Torso[arr[6]] + ")" + RightArm[arr[5]] + "\n": "(" + Torso[arr[6]] + ")\n";
      result += Base[arr[7]] + "\n";
    }
    return result;
  }
};


const int CorrectNumbers[] ={
		11111111,11111112,11111113,11111114,11111121,11111122,11111123,11111124,11111131,11111132,
		11111133,11111134,11111141,11111142,11111143,11111144,11111211,11111212,11111213,21223422,
		21223423,21223424,21223431,21223432,21223433,21223434,21223441,21223442,21223443,21223444,
		21224111,21224112,21224113,21224114,21224121,21224122,21224123,21224124,21224131,21224132,
		21224133,21224134,21224141,21224142,21224143,21224144,21224211,21224212,21224213,21224214,
		21224221,21224222,21224223,21224224,21224231,21224232,21224233,21224234,21224241,21224242,
		21224243,21224244,21224311,21224312,21224313,21224314,21224321,21224322,21224323,21224324,
		21224331,21224332,21224333,21224334,21224341,32133111,32133112,32133113,32133114,32133121,
		32133122,32133123,32133124,32133131,32133132,32133133,32133134,32133141,32133142,32133143,
		32133144,32133211,32133212,32133213,32133214,32133221,42244222,42244223,42244224,42244231,
		42244232,42244233,42244234,42244241,42244242,42244243,42244244,42244311,42244312,42244313,
		42244314,42244321,42244322,42244323,42244324,42244331,42244332,42244333,42244334};

string nospaces(string str){
  str.erase(remove(str.begin(), str.end(), ' '), str.end());
  str.erase(remove(str.begin(), str.end(), '\t'), str.end());
  str.erase(remove(str.begin(), str.end(), '\n'), str.end());
  str.erase(remove(str.begin(), str.end(), '\r'), str.end());
  return str;
}

int main(){
  int size = sizeof(CorrectNumbers)/sizeof(CorrectNumbers[0]);
  for (size_t i = 0; i < size; i++){
    if(nospaces(ariel::snowmanE(CorrectNumbers[i])) != nospaces(ariel::snowman2(CorrectNumbers[i]))){
      cout << "num = " << CorrectNumbers[i] << "\n";
      cout << "SnowMan-moti = \n" << ariel::snowman2(CorrectNumbers[i]) << "\n";
      cout << "SnowMan-eyal = \n" << ariel::snowmanE(CorrectNumbers[i]) << "\n\n";
    }
  }
  return 0;
}
