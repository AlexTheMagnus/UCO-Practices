#include "ruleta.h"
//Voy por el punto 13
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

string getColor_(){
    if(getBola() == 0) return "0";
    else{
        int negro[18] = {2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};
        for(int i = 0; i < 18; i++){
            if(getBola() == negro[i]) return "negro";
        }
    }
    return "rojo";
}

string getParImpar_(){
    if(getBola() == 0) return "0";
    if((getBola() % 2) == 0 ) return "par";
    else{ return "impar"; }
}

string getAltoBajo_(){
    if(getBola() == 0) return "0";
    if(getBola() <= 18 ) return "bajo";
    else{ return "alto"; }
}

void getPremios(){
    list <Jugador>::iterator jugador_it;    //Para iterar entre los distintos jugadores
    list <Apuesta> apuestas_aux;             //Para trabajar con las apuestas de un jugador temporalmente
    list <Apuesta>::iterator apuesta_it;    //Para iterar entre las apuestas de un mismo jugador

    for(jugador_it = jugadores_.begin(); jugador_it != jugadores_.end(); jugador_it++){

        jugador_it->setApuestas();      //Actualiza las apuesta de un jugador
        apuestas_aux = jugador_it->getApuestas();

        for(apuesta_it = apuestas_aux.begin(); apuesta_it != apuestas_aux.end(); apuesta_it++){

            switch (apuesta_it->tipo) {
                case 1:     //Apuesta sencilla
                    if( getBola() == stoi(apuesta_it->valor) ){
                        int ganado = 35 * (apuesta_it->cantidad);
                        jugador_it->setDinero( ganado + (jugador_it->getDinero()) );
                        setBanca( getBanca() - ganado );
                    }
                    else{
                        jugador_it->setDinero( (jugador_it->getDinero()) - (apuesta_it->cantidad) );
                        setBanca( getBanca() + (apuesta_it->cantidad) );
                    }
                break;

                case 2:     //Apuesta rojo/negro
                    if(apuesta_it->valor == getColor_()){
                        jugador_it->setDinero( (apuesta_it->cantidad) + (jugador_it->getDinero()) );
                        setBanca( getBanca() - (apuesta_it->cantidad) );
                    }
                    else{
                        jugador_it->setDinero( (jugador_it->getDinero()) - (apuesta_it->cantidad) );
                        setBanca( getBanca() + (apuesta_it->cantidad) );
                    }

                break;

                case 3:     //Apuesta par/impar
                    if(apuesta_it->valor == getParImpar_()){
                        jugador_it->setDinero( (apuesta_it->cantidad) + (jugador_it->getDinero()) );
                        setBanca( getBanca() - (apuesta_it->cantidad) );
                    }
                    else{
                        jugador_it->setDinero( (jugador_it->getDinero()) - (apuesta_it->cantidad) );
                        setBanca( getBanca() + (apuesta_it->cantidad) );
                    }
                break;

                case 4:     //Apuesta alto/bajo
                if(apuesta_it->valor == getAltoBajo_()){
                    jugador_it->setDinero( (apuesta_it->cantidad) + (jugador_it->getDinero()) );
                    setBanca( getBanca() - (apuesta_it->cantidad) );
                }
                else{
                    jugador_it->setDinero( (jugador_it->getDinero()) - (apuesta_it->cantidad) );
                    setBanca( getBanca() + (apuesta_it->cantidad) );
                }
                break;
            }
        }
    }
}
