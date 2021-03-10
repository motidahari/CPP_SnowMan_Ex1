#include <iostream>
#include <string>
using namespace std;

string Hat[4] = {" _===_\n", "  ___\n .....\n", "   _ \n  /_\\\n", "  ___ \n (_*_)\n"};
string LeftEye[4] = {".", "o", "O", "-"};
string Mouth[4] = {",", ".", "_", " "};
string RightEye[4] = {".", "o", "O", "-"};
string LeftArm[5] = {"<", "\\", "/", " ", "\\"};
string Torso[4] = {" : ", "] [", "> <", "   "};
string RightArm[5] = {">", "/", "\\", " ", "/"};
string Base[4] = {" ( : )", " (   )", " (___)", " (   )"};

int getIndex(char c)
{
  int ascii = c;
  if (ascii >= 49 && ascii <= 52)
  {
    switch (ascii - 1)
    {
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
void printSnowMan(string str){
  int UpLeftArm = (str[4] == '2') ? 1 : 0;
  int UpRightArm = (str[5] == '2') ? 1 : 0;
  // cout << "UpLeftArm = " << UpLeftArm << "\n";
  // cout << "UpRightArm = " << UpRightArm <<  "\n";

  for (size_t i = 0; i < str.size(); i++){
    int index = getIndex(str[i]);
    if (i == 0){
      cout << Hat[index];
    }
    else if (i == 1){
      if (UpLeftArm == 1){
        cout << LeftArm[4] << "(";
        cout << LeftEye[index];
      }else{
        cout << " (" << LeftEye[index];
      }
    }
    else if (i == 2){
      cout << Mouth[index];
    }else if (i == 3) {
      if (UpRightArm == 1){
        cout << RightEye[index] << ")" << RightArm[4] << "\n";
      }else{
        cout << RightEye[index] << ")\n";
      }
    }
    else if (i == 4){
      if (UpLeftArm != 1){
        cout << LeftArm[index];
      }else{
        cout << " ";
      }
    }
    else if (i == 5){
      // cout << "(" << Torso[index] << ")";
      if (UpRightArm != 1){
        cout << "(" << Torso[index] << ")";
      }else{
        cout << "(" << Torso[index] << ")\n";
      }
    }else if (i == 6){
      // if (UpRightArm != 1){
      //   cout << RightArm[index] << "\n";
      // }
      if (UpRightArm != 1){
        cout << RightArm[index] << "\n";
      }
    }
    else if (i == 7){
      cout << Base[index];
    }
  }
}

bool checkValue(string x){
  if(x.size() != 8){
    return false;
  }
  bool flag = true;
  for (size_t i = 0; i < x.size(); i++){
    if (x[i] < 49 || x[i] > 52){
      return false;
    }
  }
  return true;
}

int main(){
  const char *arr[52]  = {
    "11111111",
    "21111111",
    "31111111",
    "41111111",
    "42111111",
    "43111111",
    "44111111",
    "44211111",
    "44311111",
    "44411111",
    "44421111",
    "44431111",
    "44441111",
    "44441111",
    "44442111",
    "44443111",
    "44444111",
    "44444211",
    "44444311",
    "44444411",
    "44444421",
    "44444431",
    "44444441",
    "44444442",
    "44444443",
    "11111111",
    "11111112",
    "11111113",
    "11111114",
    "11111114",
    "11111124",
    "11111134",
    "11111144",
    "11111244",
    "11111344",
    "11111444",
    "11112444",
    "11113444",
    "11114444",
    "11124444",
    "11134444",
    "11144444",
    "11244444",
    "11344444",
    "11444444",
    "12444444",
    "13444444",
    "14444444",
    "24444444",
    "34444444",
    "44444444",
    "44444444"
  };
  int size = (sizeof(arr)/sizeof(*arr));
   for (int i = 0; i < size; i++){
    if (checkValue(arr[i]) == true){
      cout << "\nx = " << arr[i] << "\n";
      printSnowMan(arr[i]);
    }else{
      cout << "error value";
    }
   }
  
return 0;
}