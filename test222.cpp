#include <iostream>
#include <string>
using namespace std;

int getRandomNum(int size) {
    int number = 0;
    for (size_t i = 0; i < size; i++){
        number *= 10;
        number += (rand() % 4 + 1);//generate number between 1 and 10:
    }
    return number;
}
// bool checkSize(int x){
//     std::string text = "";
//     text += std::to_string(x);
//     return text.size() == 8;   
// }
// bool checkValue(int x){
//     std::string text = "";
//     text += std::to_string(x);
//   for (size_t i = 0; i < text.size(); i++){
//     if (text[i] < 49 || text[i] > 52){
//       return false;
//     }
//   }
//   return true;
// }
int checkSize(int x){
    std::string text = "";
    text += std::to_string(x);
    return (text.size() == 8) ? 1 : -1;
}
int checkValue(int x){
    std::string text = "";
    text += std::to_string(x);
  for (size_t i = 0; i < text.size(); i++){
    if (text[i] < 49 || text[i] > 52){
      return -1;
    }
  }
  return 1;
}

int main(){
    for (size_t i = 0; i < 100; i++){
    int a = getRandomNum(8);
    cout << "getRandomNum = " << a << "\n";
    bool FLAG = checkSize(a);
    cout << "checkSize = " << FLAG << "\n";
    FLAG = checkValue(a);
    cout << "checkValue = " << FLAG << "\n\n";

    }

    
   


return 0;
}