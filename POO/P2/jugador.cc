#include "jugador.h"
#include <fstream>
#include <cstdlib>

using std::ifstream;

Jugador::Jugador(const string dni, const string codigo, const string nombre,
  const string apellidos, const int edad, const string direccion,
  const string localidad, const string provincia,
  const string pais): Persona(dni, nombre, apellidos, edad, direccion,
    localidad, provincia, pais){
    setDinero(1000);
    setCodigo(codigo);
  }

bool Jugador::setDinero(int aux){
  if(aux < 0){
    return false;
  }
  dinero_ = aux;
  return true;
}

void Jugador::setApuestas(){
  //Borra las apuestas
  apuestas_.clear();
  //Variables auxiliares para extarer los datos del fichero txt
  Apuesta apuesta;
  string dato, filename;
  //istream es un clase que se encarga de las funciones de ficheros (como su apertura y cierre)
  filename = getDNI() + ".txt";
  ifstream file(filename.c_str());
  //getline devuelve falso cuando no hay mas lineas por leer
  while(getline(file, dato, ',')){
    apuesta.tipo = atoi(dato.c_str());
    getline(file, dato, ',');
    apuesta.valor = dato;
    getline(file, dato, ',');
    apuesta.cantidad = atoi(dato.c_str());
    //Guarda la apuesta aux en la lista de apuestas
    apuestas_.push_back(apuesta);
  }
  file.close();
}
