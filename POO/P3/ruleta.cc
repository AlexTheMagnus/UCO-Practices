#include "ruleta.h"
#include "crupier.h"
//Voy por el punto 7
using std::list;
using std::string;

Ruleta::Ruleta(Crupier c){
  setBola(-1);
  setBanca(1000000);
  setCrupier(c);
}

bool Persona::setBanca(int aux){
  if(aux < 0){
    return false;
  }
  banca_ = aux;
  return true;
}

bool Persona::setBola(int aux){
  if(aux < 0 || aux > 36){
    return false;
  }
  bola_ = aux;
  return true;
}

bool addJugador(Jugador aux){
  jugadores_.insert(aux);
  //crear fichero texto
  return true;
}
