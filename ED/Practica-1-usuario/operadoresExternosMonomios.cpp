/*!
   \file  operadoresExternosMonomios.cpp
	\brief Ficheros con el código de los operadores externos de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>
#include <string>

#include "operadoresExternosMonomios.hpp"


//  Se incluyen los operadores sobrecargados dentro del espacio de nombres ed
namespace ed
{
	// Operadores de igualdad

	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2)
	{
		if((abs(m1.getGrado() - m2.getGrado()) < COTA_ERROR ) and (abs(m1.getCoeficiente() - m2.getCoeficiente()) < COTA_ERROR)){
			return true;
		}
		else{ return false; }
	}

	bool operator==(ed::Monomio const & m, double const & x)
	{
		if((abs(m.getGrado()) < COTA_ERROR ) and (abs(m.getCoeficiente() - x) < COTA_ERROR)){
			return true;
		}
		else{ return false; }
	}

	bool operator==(double const & x, ed::Monomio const & m)
	{
		if((abs(m.getGrado()) < COTA_ERROR ) and (abs(m.getCoeficiente() - x) < COTA_ERROR)){
			return true;
		}
		else{ return false; }
	}

	// Operadores de desigualdad

	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2)
	{
		if((abs(m1.getGrado() - m2.getGrado()) < COTA_ERROR ) and (abs(m1.getCoeficiente() - m2.getCoeficiente()) < COTA_ERROR)){
			return false;
		}
		else{ return true; }
	}

	bool operator!=(ed::Monomio const & m, double const & x)
	{
		if((abs(m.getGrado()) < COTA_ERROR ) and (abs(m.getCoeficiente() - x) < COTA_ERROR)){
			return false;
		}
		else{ return true; }
	}

	bool operator!=(double const & x, ed::Monomio const & m)
	{
		if((abs(m.getGrado()) < COTA_ERROR ) and (abs(m.getCoeficiente() - x) < COTA_ERROR)){
			return false;
		}
		else{ return true; }
	}


	////////////////////////////////////////////////////////////

	// Operadores unarios prefijos

	ed::Monomio & operator+(ed::Monomio const & m)
	{
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();
		*nuevo = m;

		#ifndef NDEBUG
			assert((nuevo->getGrado() == m.getGrado()) && (nuevo->getCoeficiente() == m.getCoeficiente()));
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator-(ed::Monomio const & m)
	{
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();
		*nuevo = m;
		nuevo->setCoeficiente(-(nuevo->getCoeficiente()));

		#ifndef NDEBUG
			assert((nuevo->getGrado() == m.getGrado()) && (nuevo->getCoeficiente() == (-(m.getCoeficiente()))));
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}

	////////////////////////////////////////////////////////////
	// Operadores aritméticos binarios

	// Suma
	ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		#ifndef NDEBUG
			assert(m1.getGrado() == m2.getGrado());
		#endif

		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();
		nuevo->setCoeficiente( m1.getCoeficiente() + m2.getCoeficiente() );
		nuevo->setGrado(m1.getGrado());

		#ifndef NDEBUG
			assert(nuevo->getGrado() == m1.getGrado());
			assert(abs(nuevo->getCoeficiente() - ( m1.getCoeficiente() + m2.getCoeficiente()) ) < COTA_ERROR );
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}

	////////////
	// Resta
	ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		#ifndef NDEBUG
			assert(m1.getGrado() == m2.getGrado());
		#endif

		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();
		nuevo->setCoeficiente( m1.getCoeficiente() - m2.getCoeficiente() );
		nuevo->setGrado(m1.getGrado());

		#ifndef NDEBUG
			assert(nuevo->getGrado() == m1.getGrado());
			assert(abs(nuevo->getCoeficiente() - ( m1.getCoeficiente() - m2.getCoeficiente()) ) < COTA_ERROR );
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}

	//////////////////
	// Multiplicación
	ed::Monomio & operator* (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();
		nuevo->setCoeficiente( m1.getCoeficiente() * m2.getCoeficiente() );
		nuevo->setGrado(m1.getGrado() + m2.getGrado());

		#ifndef NDEBUG
			assert(abs( nuevo->getGrado() - (m1.getGrado() + m2.getGrado())) < COTA_ERROR );
			assert(abs(nuevo->getCoeficiente() - ( m1.getCoeficiente() * m2.getCoeficiente()) ) < COTA_ERROR );
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator* (ed::Monomio const &m, double const &x)
	{
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();
		nuevo->setCoeficiente( m.getCoeficiente() * x );
		nuevo->setGrado(m.getGrado());

		#ifndef NDEBUG
			assert(abs( nuevo->getGrado() - m.getGrado() ) < COTA_ERROR );
			assert(abs(nuevo->getCoeficiente() - ( m.getCoeficiente() * x) ) < COTA_ERROR );
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator* (double const &x, ed::Monomio const &m)
	{
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();
		nuevo->setCoeficiente( m.getCoeficiente() * x );
		nuevo->setGrado(m.getGrado());

		#ifndef NDEBUG
			assert(abs( nuevo->getGrado() - m.getGrado() ) < COTA_ERROR );
			assert(abs(nuevo->getCoeficiente() - ( m.getCoeficiente() * x) ) < COTA_ERROR );
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}

	////////////
	// División

	ed::Monomio & operator/ (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		#ifndef NDEBUG
			assert( abs(m2.getCoeficiente()) > COTA_ERROR );
			assert( (m1.getGrado() > m2.getGrado()) || ((m1.getGrado() - m2.getGrado()) < COTA_ERROR ) );
		#endif

		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();
		nuevo->setCoeficiente( m1.getCoeficiente() / m2.getCoeficiente() );
		nuevo->setGrado(m1.getGrado() - m2.getGrado());

		#ifndef NDEBUG
			assert(abs( nuevo->getGrado() - (m1.getGrado() - m2.getGrado())) < COTA_ERROR );
			assert(abs(nuevo->getCoeficiente() - ( m1.getCoeficiente() / m2.getCoeficiente()) ) < COTA_ERROR );
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator/ (ed::Monomio const &m, double const &x)
	{
		#ifndef NDEBUG
			assert( abs(x) > COTA_ERROR );
		#endif

		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();
		nuevo->setCoeficiente( m.getCoeficiente() / x );
		nuevo->setGrado(m.getGrado());

		#ifndef NDEBUG
			assert(abs( nuevo->getGrado() - m.getGrado() ) < COTA_ERROR );
			assert(abs(nuevo->getCoeficiente() - ( m.getCoeficiente() / x) ) < COTA_ERROR );
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator/ (double const &x, ed::Monomio const &m)
	{
		#ifndef NDEBUG
			assert( (m.getGrado() < COTA_ERROR) && (abs(m.getCoeficiente()) > COTA_ERROR ) );
		#endif

		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();
		nuevo->setCoeficiente( x / m.getCoeficiente() );
		nuevo->setGrado(m.getGrado());

		#ifndef NDEBUG
			assert(abs(nuevo->getGrado()) < COTA_ERROR );
			assert(abs(nuevo->getCoeficiente() - (x / m.getCoeficiente()) ) < COTA_ERROR );
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}

	/////////////////////////////////////////////////////////////////////////////

	//  Sobrecarga del operador de entrada
	istream &operator>>(istream &stream, ed::Monomio &m)
	{
		std::string dato;
		std::getline(stream, dato, ' ');
		m.setCoeficiente(atof(dato.c_str()));
		std::getline(stream, dato, '\n');
		m.setGrado(atoi(dato.c_str()));

   		// Se devuelve el flujo de entrada
		return stream;
	}


	//  Sobrecarga del operador de salida
	ostream &operator<<(ostream &stream, ed::Monomio const &m)
	{
		stream << m.getCoeficiente() << " " << m.getGrado() << "\n";

		// Se devuelve el flujo de salida
		return stream;
	}


}  // namespace ed
