#include "ej9.h"
#include <stdio.h>

/*int CheckbyTittle(){

  return ;// 0 -> no encontrado, 1 -> encontrado
}


void AddBook(){


}*/


int Countbook(){
  FILE* f;
  f=fopen("fichero9.txt", "r");
  int nRegistros = 0, precio, unidades;
  char titulo[100];
  char autor[100];


  while (fscanf("fichero9.txt", "%s%s%f%d", titulo, autor, &precio, &unidades) != EOF) {
    nRegistros++;
  }

  return nRegistros;
}


/*int CheckStock(){

  return ;// 0 -> no encontrado, 1 -> encontrado
}


void SellBook(){


}


void DeleteBook(){


}*/
