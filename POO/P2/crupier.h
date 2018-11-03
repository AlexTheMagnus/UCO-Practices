//Crupier.h
//la clase persona representa ciertos atributos de un crupier.
#ifndef   CRUPIER_H
#define CRUPIER_H

#include "persona.h"
#include <string>
using std::string;

class Crupier : public Persona {
  private:
    string codigo_;

  public:
    Crupier(string dni, string codigo, string nombre = "", string apellidos = "",
      int edad = 0, string direccion = "", string localidad = "",
      string provincia = "", string pais = "");

      inline string getCodigo(){return codigo_;};
      inline void setCodigo(string aux){ codigo_ = aux;};
  };

#endif
