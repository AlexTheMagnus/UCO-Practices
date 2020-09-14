#include <iostream>
#include "dados.h"

int main(){
  int aux;
  Dados d;
  d.lanzamiento();
  d.getUltimos1();
  d.getUltimos2();

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
  d.getUltimos1();

  std::cout << "Dado 2 = ";
  std::cin >> aux;

  while(d.setDado2(aux) == false){
      std::cout << "El numero no esta en el rango [1,6]. Introduzca otro: ";
      std::cin >> aux;
    }
  d.getUltimos2();

  std::cout << "\n" << "La suma de ambos valores es: " << d.getSuma() << '\n';
  std::cout << "La resta de ambos valores es: " << d.getDiferencia() << '\n';

  std::cout << '\n'<< "El dado 1 ha sido lanzado "<< d.getLanzamientos1() << " veces." << '\n';
  std::cout << "El dado 2 ha sido lanzado "<< d.getLanzamientos2() << " veces." << '\n';

  std::cout <<"\n" << "La media de los valores del dado 1 es " << d.getMedia1() << '\n';
  std::cout << "La media de los valores del dado 2 es " << d.getMedia2() << '\n';

  std::cout << '\n';
  d.showUltimos1();
  d.showUltimos2();
}
