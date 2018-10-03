//Persona.h
//la clase persona representa ciertos atributos de una persona.

#include <cstring>

class Persona{
  private:
    std::string dni_;
    std::string  nombre_;
    std::string apellidos_;
    int edad_;
    std::string direccion_;
    std::string localidad_;
    std::string provincia_;
    std::string pais_;

  public:
    void setdni(string aux);             //Permite cambiar el valor de dni_
    string getdni();                     //Devuelve el valor de dni_
    void setnombre(string aux);          //Permite cambiar el valor de nombre_
    string getnombre();                  //Devuelve el valor de nombre_
    void setapellidos(string aux);       //Permite cambiar el valor de apellidos_
    string getapellidos();               //Devuelve el valor de apellidos_
    void setedad(int aux);               //Permite cambiar el valor de edad_
    int getedad();                       //Devuelve el valor de edad_
    void setdireccion(string aux);       //Permite cambiar el valor de direccion_
    string getdireccion();               //Devuelve el valor de direccion_
    void setlocalidad(string aux);       //Permite cambiar el valor de localidad_
    string getlocalidad();               //Devuelve el valor de localidad_
    void setprovincia(string aux);       //Permite cambiar el valor de provincia_
    string getprovincia();               //Devuelve el valor de provincia_
    void setpais(string aux);            //Permite cambiar el valor de pais_
    string getpais();                    //Devuelve el valor de pais_
};
