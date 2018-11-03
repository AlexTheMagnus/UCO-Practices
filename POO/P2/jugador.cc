#include "persona.h"
#include <string>

using std::string;
using std::list;

Crupier::Crupier(string dni, string codigo, string nombre, string apellidos,
  int edad, string direccion, string localidad, string provincia, string pais): Persona(dni, nombre, apellidos, edad, direccion, localidad, provincia,
  pais){
    dinero_ = 1000;
    setCodigo(codigo);
  }

  bool Jugador::setDinero(int aux){
    if(aux < 0){
      return false;
    }
    edad_ = aux;
    return true;
  }
