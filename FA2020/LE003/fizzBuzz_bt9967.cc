#include<iostream>

int main() {
  int input = 0;
  std::cin>>input;
  if(input % 3 == 0 && input % 5 == 0) {
    std::cout<<"Fizzbuzz!\n";
  }
  else if(input % 3 == 0) {
    std::cout<<"Fizz!\n";
  }
  else if(input % 5 == 0) {
    std::cout<<"Buzz!\n";
  }  
  return 0;
}
