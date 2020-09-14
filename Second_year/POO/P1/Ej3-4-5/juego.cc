#include <iostream>
#include "dados.h"

int main(){
  int aux;
  Dados d;
  d.lanzamiento();

  std::cout << "Lanzando los dados..." << '\n';
  std::cout << "Dado 1 = " << d.getDado1() << '\n';
    std::cout << "Dado 2 = " << d.getDado2() << '\n';

  std::cout << "Ahora introduzca los valores de forma manual: " << '\n';
  std::cout << "Dado 1 = ";
  std::cin >> aux;

  while(d.setDado1(aux) == false){
      std::cout << "El numero no esta en el rango [1,6]. Introduzca otro: ";
      std::cin >> aux;
  }

  std::cout << "Dado 2 = ";
  std::cin >> aux;

  while(d.setDado2(aux) == false){
      std::cout << "El numero no esta en el rango [1,6]. Introduzca otro: ";
      std::cin >> aux;
    }

  std::cout <<"\n" << "La suma de ambos valores es: " << d.getSuma() << '\n';
  std::cout << "La resta de ambos valores es: " << d.getDiferencia() << '\n' << '\n';

  std::cout << "El dado 1 ha sido lanzado "<< d.getLanzamientos1() << " veces." << '\n';
  std::cout << "El dado 2 ha sido lanzado "<< d.getLanzamientos2() << " veces." << '\n';
}
