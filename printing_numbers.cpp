#include <iostream>


using namespace std;


int main(){
  int max_number = 101;
  for (int number = 1; number < max_number; number++){
    if (number%3 == 0 && number%5 == 0){
      cout << number << ": CracklePop" << endl;
    }
    else if (number%3 == 0){
      cout << number << ": Crackle" << endl;
    }
    else if (number%5 == 0){
      cout << number << ": Pop" << endl;
    }
    else {
      cout << number << endl;
    }
  }
}
