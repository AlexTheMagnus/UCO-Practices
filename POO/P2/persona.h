//Persona.h
//la clase persona representa ciertos atributos de una persona.
#ifndef PERSONA_H
#define PERSONA_H


#include <string>
using std::string;

class Persona{
  private:
    string dni_;
    string  nombre_;
    string apellidos_;
    int edad_;
    string direccion_;
    string localidad_;
    string provincia_;
    string pais_;

  public:
    Persona(string dni, string nombre = "", string apellidos = "", int edad = 0,
     string direccion = "", string localizacion = "", string provincia = "",
     string pais = "");

     inline string getDNI(){return dni_;};
     inline void setDNI(string aux){ dni_ = aux;};
     inline string getNombre(){return nombre_;};
     inline void setNombre(string aux){nombre_=aux;};
     inline string getApellidos(){return apellidos_;};
     inline void setApellidos(string aux){apellidos_=aux;};
     inline int getEdad(){return edad_;};
     bool setEdad(int aux);
     inline string getDireccion(){return direccion_;};
     inline void setDireccion(string aux){direccion_=aux;};
     inline string getLocalidad(){return localidad_;};
     inline void setLocalidad(string aux){localidad_=aux;};
     inline string getProvincia(){return provincia_;};
     inline void setProvincia(string aux){provincia_=aux;};
     inline string getPais(){return pais_;};
     inline void setPais(string aux){pais_=aux;};

    string getApellidosyNombre();         //Pide el nombre y apellidos y devuelve un string en fomato "apellidos, nombre"
    bool mayor();                         //True -> El usuario es mayor de edad, False -> no lo es
};
#endif
