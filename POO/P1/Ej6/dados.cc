//dados.cc
//Cuerpo de los métodos de la clase Dados
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "dados.h"

Dados::Dados(){
  srand(time(NULL));
  d1_=1;
  d2_=1;
  cont1_=0;
  cont2_=0;
  total1_=0;
  total2_=0;
  for(int i = 0; i < 5; i++){
    v1_[i]=0;
    v2_[i]=0;
  }
}

void Dados::lanzamiento(){
  d1_= ((rand()%6)+1);
  cont1_++;
  total1_+=d1_;

  d2_= ((rand()%6)+1);
  cont2_++;
  total2_+=d2_;
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
    total1_+=d1_;
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
    total2_+=d2_;
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
    valor = d1_ - d2_;
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

float Dados::getMedia1(){
  return (total1_/cont1_);
}

float Dados::getMedia2(){
  return (total2_/cont2_);
}

void Dados::getUltimos1(){
  v1_[4] = v1_[3];
  v1_[3] = v1_[2];
  v1_[2] = v1_[1];
  v1_[1] = v1_[0];
  v1_[0] = d1_;
}

void Dados::getUltimos2(){
  v2_[4] = v2_[3];
  v2_[3] = v2_[2];
  v2_[2] = v2_[1];
  v2_[1] = v2_[0];
  v2_[0] = d2_;
}

void Dados::showUltimos1(){
  std::cout << "Los últimos valores del dado 1 son: " << '\n' << '\t';
  for (int i = 0; i < 5; i++) {
    std::cout << v1_[i] << '\t';
  }
  std::cout << '\n';
}

void Dados::showUltimos2(){
  std::cout << "Los últimos valores del dado 2 son: " << '\n' << '\t';
  for (int i = 0; i < 5; i++) {
    std::cout << v2_[i] << '\t';
  }
  std::cout << '\n';
}
