/*!
	\file operadoresExternosMonomios.hpp
	\brief Ficheros con los prototipos de los operadores externos de la clase Monomio
*/

#ifndef _OperadoresExternosMonomios_HPP_
#define _OperadoresExternosMonomios_HPP_

// Facilita la entrada y salida
#include <iostream>

#include "Monomio.hpp"

// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

// Espacio de nombre de la asigantura: ed
namespace ed
{
//////////////////////////////////////////////////////////////////////////////////////
	// Operadores externos que no pertenecen a la clase Monomio

	//! \name Operadores de igualdad

	/*!
		\brief Operador de igualdad entre monomios
		\param Monomio &m1: Monomio a comparar por la izquierda del operador
		\param Monomio &m2: Monomio a comparar por la derecha del operador
		\retval bool: m1==m2 -> true / m1!=m2 -> false
	*/
	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2);

	/*!
		\brief Operador de igualdad entre un monomio y un real
		\param Monomio &m: Monomio a comparar por la izquierda del operador
		\param double &x: Real a comparar por la derecha del operador
		\retval bool: m==x -> true / m!=x -> false
	*/
	bool operator==(ed::Monomio const & m, double const & x);

	/*!
		\brief Operador de igualdad entre un real y un monomio
		\param double &x: Real a comparar por la izquierda del operador
		\param Monomio &m: Monomio a comparar por la derecha del operador
		\retval bool: x==m -> true / x!=m -> false
	*/
	bool operator==(double const & x, ed::Monomio const & m);


	//! \name Operadores de desigualdad

	/*!
		\brief Operador de desigualdad entre monomios
		\param Monomio &m1: Monomio a comparar por la izquierda del operador
		\param Monomio &m2: Monomio a comparar por la derecha del operador
		\retval bool: m1==m2 -> false / m1!=m2 -> true
	*/
	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2);

	/*!
		\brief Operador de desigualdad entre un monomio y un real
		\param Monomio &m: Monomio a comparar por la izquierda del operador
		\param double &x: Real a comparar por la derecha del operador
		\retval bool: m==x -> false / m!=x -> true
	*/
	bool operator!=(ed::Monomio const & m, double const & x);

	/*!
		\brief Operador de desigualdad entre un real y un monomio
		\param double &x: Real a comparar por la izquierda del operador
		\param Monomio &m: Monomio a comparar por la derecha del operador
		\retval bool: x==m -> false / x!=m -> true
	*/
	bool operator!=(double const & x, ed::Monomio const & m);

	///////////////////////////////////////////////////


	//! \name Operadores unarios prefijos

	/*!
		\brief Operador unario prefijo positivo
		\param Monomio &m: Monomio a copiar
		\retval Monomio *nuevo: Copia del parámetro con mismo signo
	*/
	ed::Monomio & operator+(ed::Monomio const & m);

	/*!
		\brief Operador unario prefijo negativo
		\param Monomio &m: Monomio a copiar
		\retval Monomio *nuevo: Copia del parámetro con signo opuesto
	*/
	ed::Monomio & operator-(ed::Monomio const & m);

	//////////////////////////////////////////////////////////

	//! \name Operador binario de la suma

	/*!
		\brief Operador binario de la suma
		\param Monomio &m1: Monomio a operar por la izquierda
		\param Monomio &m2: Monomio a operar por la derecha
		\retval Monomio *nuevo: Suma de los parámetros
	*/
	ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2);

	//////////////////////////////////////////////////////////

	//! \name Operador binario de la resta

	/*!
		\brief Operador binario de la resta
		\param Monomio &m1: Monomio a operar por la izquierda
		\param Monomio &m2: Monomio a operar por la derecha
		\retval Monomio *nuevo: Resta de los parámetros
	*/
 	ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2);

	///////////////////////////////////////////////////////////////////////////


	//! \name Operadores binarios de la multiplicación

	/*!
		\brief Operador binario de la multiplicación
		\param Monomio &m1: Monomio a operar por la izquierda
		\param Monomio &m2: Monomio a operar por la derecha
		\retval Monomio *nuevo: Multiplicación de los parámetros
	*/
	ed::Monomio & operator* (ed::Monomio const &m1, ed::Monomio const &m2);

	/*!
		\brief Operador binario de la multiplicación
		\param Monomio &m: Monomio a operar por la izquierda
		\param double &x: Real a operar por la derecha
		\retval Monomio *nuevo: Multiplicación de los parámetros
	*/
	ed::Monomio & operator* (ed::Monomio const &m, double const &x);

	/*!
		\brief Operador binario de la multiplicación
		\param Monomio &m: Real a operar por la izquierda
		\param double &x: Monomio a operar por la derecha
		\retval Monomio *nuevo: Multiplicación de los parámetros
	*/
	ed::Monomio & operator* (double const &x, ed::Monomio const &m);

	///////////////////////////////////////////////////////////////////////////


	//! \name Operadores binarios de la división

	/*!
		\brief Operador binario de la división
		\param Monomio &m1: Monomio a operar por la izquierda
		\param Monomio &m2: Monomio a operar por la derecha
		\retval Monomio *nuevo: División de los parámetros
		\pre El Coeficiente de m2 no puede ser 0.0
		\pre El grado de m1 debe ser mayor o igual al de m2
	*/
	ed::Monomio & operator/ (ed::Monomio const &m1, ed::Monomio const &m2);

	/*!
		\brief Operador binario de la división
		\param Monomio &m: Monomio a operar por la izquierda
		\param double &x: Real a operar por la derecha
		\retval Monomio *nuevo: División de los parámetros
		\pre El real no puede valer 0.0
	*/
	ed::Monomio & operator/ (ed::Monomio const &m, double const &x);

	/*!
		\brief Operador binario de la división
		\param Monomio &m: Real a operar por la izquierda
		\param double &x: Monomio a operar por la derecha
		\retval Monomio *nuevo: División de los parámetro
		\pre El grado de m debe ser 0 y su coeficiente distinto de 0.0
	*/
	ed::Monomio & operator/ (double const &x, ed::Monomio const &m);

	/////////////////////////////////////////////////////////////////////////////


	//! \name Sobrecarga de los operadores de entrada y salida

	/**
	* \brief Operador de entrada
	* \param istream &stream: Flujo de datos de entrada
	* \param ed::Monomio &m: Referencia al monomio a modificar
	* \retval Flujo de datos
	*/
	istream &operator>>(istream &stream, ed::Monomio &m);

	/**
	* \brief Operador de salida
	* \param istream &stream: Flujo de datos de salida
	* \param ed::Monomio &m: Referencia al monomio a escribir
	* \retval Flujo de datos
	*/
	ostream &operator<<(ostream &stream, ed::Monomio const &m);

}  // Fin de namespace ed.

#endif // _OperadoresExternosMonomios_HPP_
