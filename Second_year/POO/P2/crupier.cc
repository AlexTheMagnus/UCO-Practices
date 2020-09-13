#include "crupier.h"
#include <string>

using std::string;

Crupier::Crupier(string dni, string codigo, string nombre, string apellidos,
  int edad, string direccion, string localidad, string provincia, string pais): Persona(dni, nombre, apellidos, edad, direccion, localidad, provincia,
  pais){setCodigo(codigo);}
