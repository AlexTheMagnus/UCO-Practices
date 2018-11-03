//Jugador.h
//la clase persona representa ciertos atributos de un jugador.
#ifndef   JUGADOR_H
#define JUGADOR_H

#include "persona.h"
#include <string>
using std::string;
using std::list;

struct apuesta{
  int tipo;
  string valor;
  int cantidad;
}

class Jugador : public Persona {
  private:
    int dinero_;
    string codigo_;
    list <struct apuesta> apuestas;

  public:
    Jugador(string dni, string codigo, string nombre = "", string apellidos = "",
      int edad = 0, string direccion = "", string localidad = "",
      string provincia = "", string pais = "");

      inline string getCodigo(){return codigo_;};
      inline void setCodigo(string aux){ codigo_ = aux;};
      inline int getDinero(){return dinero_;};
      bool setDinero(int aux);
  };

#endif
