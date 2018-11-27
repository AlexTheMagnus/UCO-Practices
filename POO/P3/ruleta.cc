#include "ruleta.h"
//Voy por el punto 10
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
  string filename = getDNI() + ".txt";
  //Comprueba si el fichero ya existe y entra si no existe
  if( !(ifstream(filename)) ){
    jugadores_.push_back(aux);
    std::ofstream file (filename);  //crea el fichero de apuestas
    file.close();
    return true;
  }
  return false
}

int deleteJugador(Jugador aux){
  if(!jugadores_.size()){return 1;}     //Comprueba si la lista está vacía
  int del = -1;
  //Busca al jugador a borrar
  for(int i=0; i < jugadores_.size(); i++){
    if(aux.getDNI() == jugadores_[i].getDNI()){
      del = i;
    }
  }
  if(del == -1){return -2;}   //Comprueba que el jugador esté en la lista
  jugadores_.erase(del);
  return 1;
}

int deleteJugador(string aux){
  if(!jugadores_.size()){return 1;}     //Comprueba si la lista está vacía
  int del = -1;
  //Busca al jugador a borrar
  for(int i=0; i < jugadores_.size(); i++){
    if(aux == jugadores_[i].getDNI()){
      del = i;
    }
  }
  if(del == -1){return -2;}   //Comprueba que el jugador esté en la lista
  jugadores_.erase(del);
  return 1;
}
