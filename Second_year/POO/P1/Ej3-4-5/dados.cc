//dados.cc
//Cuerpo de los métodos de la clase Dados
#include <cstdlib>
#include <ctime>
#include "dados.h"

Dados::Dados(){
  srand(time(NULL));
  d1_=1;
  d2_=1;
  cont1_=0;
  cont2_=0;
}

void Dados::lanzamiento(){
  d1_= ((rand()%6)+1);
  cont1_++;
  d2_= ((rand()%6)+1);
  cont2_++;
}

int Dados::getDado1(){
  return d1_;
  }

int Dados::getDado2(){
  return d2_;
  }

bool Dados::setDado1(int value){
  if((value > 0) && (value < 7)){
    d1_=value;
    cont1_++;
    return true;
  }
  else{
    return false;
  }
}

bool Dados::setDado2(int value){
  if((value > 0) && (value < 7)){
    d2_=value;
    cont2_++;
    return true;
  }
  else{
    return false;
  }
}

int Dados::getSuma(){
  return (d1_ + d2_);
}

int Dados::getDiferencia(){
  int valor;
  if(d1_>d2_){
    valor = d1_-d2_;
    return valor;
  }
  valor = d2_-d1_;
  return valor;
}

int Dados::getLanzamientos1(){
  return cont1_;
}

int Dados::getLanzamientos2(){
  return cont2_;
}
