/*!
   \file Polinomio.hpp
   \brief Definición de la clase Polinomio
*/

#ifndef _POLINOMIO_HPP_
#define _POLINOMIO_HPP_

// Control de asertos
#include <cassert>

// Vector de STL
#include <vector>

// Para usar la función abs
#include <cmath>

#include "PolinomioInterfaz.hpp"
#include "operadoresExternosMonomios.hpp"

// Se incluye la clase Polinomio dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase Polinomio que hereda de PolinomioInterfaz
class Polinomio: public ed::PolinomioInterfaz
{

  //! \name Atributos privados de la clase Polinomio
   private:

        std::vector<ed::Monomio> vector_;

   //! \name Funciones o métodos públicos de la clase Polinomio
   public:

	//! \name Constructores de la clase Polinomio

    Polinomio();

    Polinomio(Polinomio &p);

  //! \name Observadores: funciones de consulta de la clase Polinomio

  bool esNulo() const;

  inline int getGrado() const {return this->getVector().front().getGrado();};

  int getNumeroMonomios() const;

  bool existeMonomio(int n) const;

  Monomio & getMonomio(int n) const;

  //Incluido por mi
  inline std::vector <ed::Monomio> getVector() const {return vector_;};

	//! \name Funciones de modificación de la clase Polinomio

	void ordenarPolinomio();


 	////////////////////////////////////////////////////////////////

  //! \name Operadores de la clase Polinomio

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator=(Polinomio const &p);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator=(Monomio const &m);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator=(double const &x);

  // Operadores aritméticos y asignación

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator+=(Polinomio const &p);


	// COMPLETAR EL RESTO DE OPERADORES
    Polinomio & operator+=(ed::Monomio const &m);

    Polinomio & operator+=(double const &x);

    Polinomio & operator-=(Polinomio const &p);

    Polinomio & operator-=(ed::Monomio const &m);

    Polinomio & operator-=(double const &x);

    Polinomio & operator*=(Polinomio const &p);

    Polinomio & operator*=(ed::Monomio const &m);

    Polinomio & operator*=(double const &x);

    Polinomio & operator/=(Polinomio const &p);

    Polinomio & operator/=(ed::Monomio const &m);

    Polinomio & operator/=(double const &x);

  /////////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones lectura y escritura de la clase Polinomio

  void leerPolinomio();

  void escribirPolinomio() const;

	///////////////////////////////////////////////////////////////////////

	//! \name Funciones auxiliares de la clase Polinomio

  double calcularValor(double &x) const;

  //Funciones adicionales

  ed::Polinomio & Potencia(int &x);

  bool Comprueba(double &x, double &y);

}; // Fin de la definición de la clase Polinomio




} // \brief Fin de namespace ed.

//  _POLINOMIO_HPP_
#endif
