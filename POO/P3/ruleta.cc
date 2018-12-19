#include "ruleta.h"
//Voy por el punto 11
using std::list;
using std::string;

Ruleta::Ruleta(Crupier c){
  setBola(-1);
  setBanca(1000000);
  setCrupier(c);
}

bool Ruleta::setBanca(int aux){
  if(aux < 0){
    return false;
  }
  banca_ = aux;
  return true;
}

bool Ruleta::setBola(int aux){
  if(aux < 0 || aux > 36){
    return false;
  }
  bola_ = aux;
  return true;
}

bool Ruleta::addJugador(Jugador aux){
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

int Ruleta::deleteJugador(Jugador aux){
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

int Ruleta::deleteJugador(string aux){
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

void Ruleta::escribeJugadores(){
    std::ofstream file("jugadores.txt");
    list <Jugador>::iterator it;

    for(it = jugadores_.begin(); it != jugadores_.end(); it++){
        file << it->getDNI() << "," << it->getCodigo() << ","
        << it->getNombre() << "," << it->getApellidos() << ","
        << it->getDireccion() << "," << it->getLocalidad() << ","
        << it->getProvincia() << "," << it->getPais() << ","
        << it->getDinero() << std::endl;
    }
    file.close();
}


void Ruleta::leeJugadores(){
    jugadores_.clear();     //vacía la lista de jugadores
    Jugador aux("DefaultDNI","DefaultCode");
    string dato;

    std::ifstream file( "jugadores.txt" );
    for( getline(file, dato, ",") ){
        aux.setDNI(dato);
        getline(file, dato, ",")
        aux.setCodigo(dato);
        getline(file, dato, ",")
        aux.setNombre(dato);
        getline(file, dato, ",")
        aux.setApellidos(dato);
        getline(file, dato, ",")
        aux.setDireccion(dato);
        getline(file, dato, ",")
        aux.setLocalidad(dato);
        getline(file, dato, ",")
        aux.setProvincia(dato);
        getline(file, dato, ",")
        aux.setPais(dato);
        getline(file, dato, ",")
        aux.setDinero( stoi(dato) );

        jugadores_.push_back(aux);      //Añade el jugador extraido a la lista
    }
    file.close();
}
