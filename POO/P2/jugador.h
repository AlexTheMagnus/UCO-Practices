//Jugador.h
//la clase persona representa ciertos atributos de un jugador.
#ifndef   JUGADOR_H
#define JUGADOR_H

#include "persona.h"
#include <list>

using std::list;

class Apuesta{
  int tipo;
  string valor;
  int cantidad;
};

class Jugador : public Persona {
  private:
    int dinero_;
    string codigo_;
    list <Apuesta> apuestas_;

  public:
    Jugador(const string dni, const string codigo, const string nombre = "",
      const string apellidos = "", const int edad = 0, const string direccion = "",
      const string localidad = "", const string provincia = "", const string pais = "");

      //Observadores y Modificadores
      inline string getCodigo()const {return codigo_;};
      inline void setCodigo(string aux){ codigo_ = aux;};
      inline int getDinero() const {return dinero_;};
      bool setDinero(int aux);
      inline list <Apuesta> getApuestas() const {return apuestas_;};
      void setApuestas();
  };

#endif
