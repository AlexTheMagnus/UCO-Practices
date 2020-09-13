//guess.cc
//A program thats generate a random number

#include <iostream>
#include <cstdlib>
#include <ctime>

int main(int argc, char const *argv[]) {

  int i;
  int maxnumber = 10;
  int result;

  srand(time(NULL));
  result = (rand()%(maxnumber+1)+1);

  while (i != result) {
    std::cout << "Introduce un numero: ";
    std::cin >> i;
    if(i > result){
      std::cout << "Es menor, prueba otra vez.\n";
    }
    else{
      if(i < result){
      std::cout << "Es mayor, prueba otra vez.\n";
      }
      else{
          std::cout << "Acertaste, enhorabuena.\n";
      }
    }
  }

  return 0;
}
