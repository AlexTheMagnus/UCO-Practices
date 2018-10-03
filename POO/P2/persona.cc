#include "persona.h"

Person::Persona(){
  string aux;
  std::cout << "Introduzca su dni: " << std::endl;
  std::cin >> aux;
  setdni(aux);
  setnombre("");
  setapellidos("");
  setedad(0);
  setdireccion("");
  setlocalidad("");
  setprovincia("");
  setpais("");
}

inline string Persona::getdni(){
  return dni_;
}
inline void Persona::setdni(string aux){
  dni_=aux;
}

inline string Persona::getnombre(){
  return nombre_;
}
inline void Persona::setnombre(string aux){
  nombre_=aux;
}

inline string Persona::getapellidos(){
  return apellidos_;
}
inline void Persona::setapellidos(string aux){
  apellidos_=aux;
}

inline int Persona::getedad(){
  return edad_;
}
inline void Persona::setedad(string aux){
  edad_=aux;
}

inline string Persona::getdireccion(){
  return direccion_;
}
inline void Persona::setdireccion(string aux){
  direccion_=aux;
}

inline string Persona::getlocalidad(){
  return localidad_;
}
inline void Persona::setlocalidad(string aux){
  localidad_=aux;
}

inline string Persona::getprovincia(){
  return provincia_;
}
inline void Persona::setprovincia(string aux){
  provincia_=aux;
}

inline string Persona::getpais(){
  return pais_;
}
inline void Persona::setpais(string aux){
  pais_=aux;
}

getApellidosyNombre(){
  
}
