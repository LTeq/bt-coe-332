#include <iostream>

int main() {
  int N = 0, greaterN = 0, i, j;
  std::cin>>N;
  
  //Recent Multiples Greater Than N
  for(i = 0; i <= 10; i++) {
    for(j = 0; j <= 10; j++) {
      if(i * j > N) {
	greaterN = 1;
	break;
      }
    }
    if(greaterN == 1) {
      break;
    }
  }
  std::cout<<i<<","<<j<<"\n";

  //Least Multiples Greater Than N
  greaterN = 0;
  int past = 0;
  for(int count = 0; count <= 20; count++) {
    if(count > 10) {
      past++;
    }
    for(i = 0 + past, j = count - past; j >= 0; i++, j--) {
      if(i * j > N) {
	greaterN = 1;
	break;
      }
    }
    if(greaterN == 1) {
      break;
    }
  }
  std::cout<<i<<","<<j<<"\n";
  return 0;
}
