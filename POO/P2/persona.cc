#include "persona.h"
#include <iostream>
#include <string>
#include <cstdlib>

using std::string;

Persona::Persona(string dni, string nombre, string apellidos,
  int edad, string direccion, string localidad, string provincia, string pais){
  setDNI(dni);
  setNombre(nombre);
  setApellidos(apellidos);
  setEdad(edad);
  setDireccion(direccion);
  setLocalidad(localidad);
  setProvincia(provincia);
  setPais(pais);
}

bool Persona::setEdad(int aux){
  if(aux < 0){
    return false;
  }
  edad_ = aux;
  return true;
}

string Persona::getApellidosyNombre(){
  string apellidosynombre;
  apellidosynombre = apellidos_ + ", " + nombre_;
  return apellidosynombre;
}

bool Persona::mayor(){
  if( edad_ >= 18 ){
    return true;
  }
  return false;
}
