/*!
   \file  Monomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "macros.hpp"
#include "operadoresExternosMonomios.hpp"

//Constructores
ed::Monomio::Monomio(double coeficiente, int grado){
	#ifndef NDEBUG
		assert(grado >= 0);
	#endif

	this->setCoeficiente(coeficiente);
	this->setGrado(grado);

	#ifndef NDEBUG
		assert(this->getGrado() == grado);
		assert(std::abs(this->getCoeficiente() - coeficiente) < COTA_ERROR );
	#endif
}


ed::Monomio::Monomio(Monomio const &m){
	this->setCoeficiente(m.getCoeficiente());
	this->setGrado(m.getGrado());

	#ifndef NDEBUG
		assert(this->getGrado() == m.getGrado());
		assert(abs(this->getCoeficiente() - m.getCoeficiente()) < COTA_ERROR );
	#endif
}


// Operadores de asignación

ed::Monomio & ed::Monomio::operator=(ed::Monomio const &m)
{
	if(this != &m){
		this->setCoeficiente(m.getCoeficiente());
		this->setGrado(m.getGrado());
	}

	#ifndef NDEBUG
		assert(this->getGrado() == m.getGrado());
		assert(abs(this->getCoeficiente() - m.getCoeficiente()) < COTA_ERROR);
	#endif

	// Se devuelve el objeto actual
	return *this;
}


ed::Monomio & ed::Monomio::operator=(double const &x)
{
	//if(*this != x){
		this->setCoeficiente(x);
		this->setGrado(0);
	//}

	#ifndef NDEBUG
		assert(this->getGrado() == 0);
		assert(abs(this->getCoeficiente() - x) < COTA_ERROR );
	#endif

	// Se devuelve el objeto actual
	return *this;
}



//////////////////////////////////////////////////////////////

// Operadores aritméticos y asignación

ed::Monomio & ed::Monomio::operator+=(ed::Monomio const &m)
{
	#ifndef NDEBUG
		assert(this->getGrado() == m.getGrado());
		double oldcoef = this->getCoeficiente();
		int oldgrado = this->getGrado();
	#endif

	this->setCoeficiente((this->getCoeficiente())+(m.getCoeficiente()));

	#ifndef NDEBUG
		assert(this->getGrado() == oldgrado);
		assert(abs(this->getCoeficiente() - (oldcoef + m.getCoeficiente()) ) < COTA_ERROR );
	#endif
	// Se devuelve el objeto actual
	return *this;
}

ed::Monomio & ed::Monomio::operator-=(ed::Monomio const &m)
{
	#ifndef NDEBUG
		assert(this->getGrado() == m.getGrado());
		double oldcoef = this->getCoeficiente();
	#endif

	this->setCoeficiente((this->getCoeficiente())-(m.getCoeficiente()));

	#ifndef NDEBUG
		assert(this->getGrado() == m.getGrado());
		assert(abs(this->getCoeficiente() - (oldcoef - m.getCoeficiente())) < COTA_ERROR );
	#endif

	// Se devuelve el objeto actual
	return *this;
}

ed::Monomio & ed::Monomio::operator*=(ed::Monomio const &m)
{
	#ifndef NDEBUG
		double oldcoef = this->getCoeficiente();
		int oldgrado = this->getGrado();
	#endif

	this->setCoeficiente((this->getCoeficiente())*(m.getCoeficiente()));
	this->setGrado((this->getGrado())+(m.getGrado()));

	#ifndef NDEBUG
		assert( abs(this->getCoeficiente() - (oldcoef * m.getCoeficiente())) < COTA_ERROR );
		assert( this->getGrado() == (oldgrado + m.getGrado()) );
	#endif

	// Se devuelve el objeto actual
	return *this;
}

ed::Monomio & ed::Monomio::operator/=(ed::Monomio const &m)
{
	#ifndef NDEBUG
		assert(this->getGrado() >= m.getGrado());
		assert(m.getCoeficiente() > COTA_ERROR);
		double oldcoef = this->getCoeficiente();
		int oldgrado = this->getGrado();
	#endif

	this->setCoeficiente((this->getCoeficiente())/(m.getCoeficiente()));
	this->setGrado((this->getGrado())-(m.getGrado()));

	#ifndef NDEBUG
		assert( abs(this->getCoeficiente() - (oldcoef / m.getCoeficiente())) < COTA_ERROR );
		assert( this->getGrado() == (oldgrado - m.getGrado()) );
	#endif

	// Se devuelve el objeto actual
	return *this;
}

ed::Monomio & ed::Monomio::operator*=(double const &x)
{
	#ifndef NDEBUG
		double oldcoef = this->getCoeficiente();
		int oldgrado = this->getGrado();
	#endif

	this->setCoeficiente((this->getCoeficiente())*x);

	#ifndef NDEBUG
		assert(this->getGrado() == oldgrado);
		assert(abs( this->getCoeficiente() - (x * oldcoef) ) < COTA_ERROR );
	#endif

	// Se devuelve el objeto actual
	return *this;
}

ed::Monomio & ed::Monomio::operator/=(double const &x)
{
	#ifndef NDEBUG
		double oldcoef = this->getCoeficiente();
		int oldgrado = this->getGrado();
		assert(abs(x) > COTA_ERROR );
	#endif

	this->setCoeficiente((this->getCoeficiente())/x);

	#ifndef NDEBUG
		assert(this->getGrado() == oldgrado);
		assert(abs( this->getCoeficiente() - ( oldcoef / x) ) < COTA_ERROR );
	#endif

	// Se devuelve el objeto actual
	return *this;
}


///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Monomio

void ed::Monomio::leerMonomio(){
	double coefaux;
	int gradaux;

	std::cout << BIGREEN;
	std::cout << "Introduzca los valores:" << '\n';
	std::cout << "\tCoeficiente: ";
	std::cout << RESET;
	std::cin >> coefaux;
	std::cout << BIGREEN;
	std::cout << "\tGrado: ";
	std::cout << RESET;
	std::cin >> gradaux;


	this->setCoeficiente(coefaux);
	this->setGrado(gradaux);

	std::cin.ignore();		//Para limpiar el buffer
	#ifndef NDEBUG
		assert(this->getGrado() >= 0);
	#endif
}

void ed::Monomio::escribirMonomio(){
	//Impresión del coeficiente
	if(this->getCoeficiente()==1){/*No se imprime nada*/}
	else{
		if(this->getCoeficiente()==(-1)){
			std::cout << "-";
		}
		else{
			std::cout << this->getCoeficiente();
		}
	}
	//Impresión del grado
	if(this->getGrado()==0){
		if((abs(this->getCoeficiente()-(-1)) < COTA_ERROR ) or (abs(this->getCoeficiente()-1) < COTA_ERROR)){
			std::cout << "1";
		}
	}
	else{
		if(this->getGrado()==1){
			std::cout << "X";
		}
		else{
			std::cout << "X^" << this->getGrado();
		}
	}
}


///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Monomio

double ed::Monomio::calcularValor(double &x){
	double total;
	total=pow(x,this->getGrado());
	total=total*(this->getCoeficiente());

	return total;
}

////////////////////////////////////////////////////////////////////////

//Funciones adicionales

ed::Monomio & ed::Monomio::Potencia(int &x){
	ed::Monomio *nuevo = new ed::Monomio();

	nuevo->setCoeficiente(pow(this->getCoeficiente(), x));
	nuevo->setGrado(this->getGrado()*x);

	return *nuevo;
}

bool ed::Monomio::Comprueba(double &x, double &y){
	double c3po;
	c3po = calcularValor(x);
	if(abs(c3po - y) < COTA_ERROR){
		return true;
	}
	else{return false;}
}
