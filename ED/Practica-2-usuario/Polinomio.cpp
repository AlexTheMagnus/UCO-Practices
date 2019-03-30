/*!
   \file Polinomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Polinomio
*/


// Ficheros de cabecera
#include <iostream>

#include "macros.hpp"
#include "operadoresExternosPolinomios.hpp"

//Constructores
ed::Polinomio::Polinomio(){
	ed::Monomio m(0.0, 0);
	this->getVector().push_back(m);

	#ifndef NDBUG
		assert(esNulo());
	#endif
}

ed::Polinomio::Polinomio(Polinomio &p){
	this->getVector() = p.getVector();

	#ifndef NDBUG
		assert(this->getVector() == p.getVector());
	#endif
}

//Observadores
bool ed::Polinomio::esNulo() const {
	#ifndef NDBUG
	ed::Polinomio *VecOrdenado = new ed::Polinomio();
	*VecOrdenado = *this;
	VecOrdenado->ordenarPolinomio();

	std::vector<ed::Monomio>::iterator it2 = VecOrdenado->getVector().begin();
	for (std::vector<ed::Monomio>::iterator it = this->getVector().begin(); it != this->getVector().end(); ++it){
		assert(*it == *it2);
		it2++;
	}
	#endif

	ed::Monomio m(0.0, 0);
	if(this->getVector().front() == m){
		return true;
	}
	else{
		return false;
	}
}

int ed::Polinomio::getGrado() const{
	return this->getVector().begin()->getGrado();
}

int ed::Polinomio::getNumeroMonomios() const {
	int no = 0;
	for (std::vector<ed::Monomio>::iterator it = this->getVector().begin() ; it != this->getVector().end(); ++it){
		no++;
	}
	return no;
}

bool ed::Polinomio::existeMonomio(int n) const {
	#ifndef NDBUG
		assert(!(this->esNulo()));
	#endif

	for (std::vector<ed::Monomio>::iterator it = this->getVector().begin() ; it != this->getVector().end(); ++it){
		if(it->getGrado() == n){
			return true;
		}
	}
	return false;
}

ed::Monomio & ed::Polinomio::getMonomio(int n) const {
	#ifndef NDBUG
		assert(!(this->esNulo()));
	#endif

	if(this->existeMonomio(n)){
		for (std::vector<ed::Monomio>::iterator it = this->getVector().begin() ; it != this->getVector().end(); ++it){
			if(it->getGrado() == n){
				return *it;
			}
		}
	}
	
	//El monomio de grado n no existe
	ed::Monomio *monoaux = new ed::Monomio();
	monoaux->setCoeficiente(0.0);
	monoaux->setGrado(n);
	return *monoaux;
}

//Modificadores
void ed::Polinomio::ordenarPolinomio(){
	ed::Polinomio auxpoli;
	std::vector<ed::Monomio>::iterator mayor = this->getVector().begin();
	//ed::Monomio *auxmono = &(this->getVector()).front();
	int n = this->getNumeroMonomios();

	for ( int i = 0; i < n; i++){
		for (std::vector<ed::Monomio>::iterator it = this->getVector().begin(); it != this->getVector().end(); ++it){
			if(it->getGrado() > mayor->getGrado()){
				mayor = it;
			}
		}
		auxpoli.getVector().push_back(*mayor);
		this->getVector().erase(mayor);
	}
}


// Operadores de asignación

/////////////////////////////////////////////////////////////

ed::Polinomio & ed::Polinomio::operator=(ed::Polinomio const &p)
{
	if(this->getVector() != p.getVector()) {
		*this = p;
	}

	#ifndef NDBUG
		std::vector<ed::Monomio>::iterator it2 = p.getVector().begin();
	for (std::vector<ed::Monomio>::iterator it = this->getVector().begin(); it != this->getVector().end(); ++it){
		assert(*it == *it2);
		it2++;
	}
	#endif

	// Se devuelve el objeto actual
	return *this;
}


ed::Polinomio & ed::Polinomio::operator=(ed::Monomio const &m)
{
	//vacía el polinomio
	getVector().erase (getVector().begin(),getVector().end());
	this->getVector().push_back(m);

	#ifndef NDBUG
		assert(this->getNumeroMonomios() == 1);
		assert(this->getVector().front() == m);
	#endif

	// Se devuelve el objeto actual
	return *this;
}


ed::Polinomio & ed::Polinomio::operator=(double const &x)
{
	ed::Monomio m(x, 0);
	//vacía el polinomio
	getVector().erase (getVector().begin(),getVector().end());
	this->getVector().push_back(m);


	#ifndef NDBUG
		assert(this->getNumeroMonomios() == 1);
		assert(this->getVector().front() == x);
	#endif

	// Se devuelve el objeto actual
	return *this;
}

ed::Polinomio & ed::Polinomio::operator+=(ed::Polinomio const &p)
{
	bool sumado;

	for (std::vector<ed::Monomio>::iterator it2 = p.getVector().begin() ; it2 != p.getVector().end(); ++it2){
		sumado = false;
		for (std::vector<ed::Monomio>::iterator it = this->getVector().begin(); it != this->getVector().end() && sumado != true; ++it){
			if(it->getGrado() == it2->getGrado()){
				*it += *it2;
				sumado = true;
			}
		}
		if(!sumado){
			this->getVector().push_back(*it2);
		}
	}

	this->ordenarPolinomio();
	// Se devuelve el objeto actual
	return *this;
}

ed::Polinomio & ed::Polinomio::operator+=(ed::Monomio const &m)
{
	bool sumado = false;

	for (std::vector<ed::Monomio>::iterator it = this->getVector().begin(); it != this->getVector().end() && sumado != true; ++it){
		if(it->getGrado() == m.getGrado()){
			*it += m;
			sumado = true;
		}
	}
	if(!sumado){
		this->getVector().push_back(m);
	}

	this->ordenarPolinomio();
	// Se devuelve el objeto actual
	return *this;
}

ed::Polinomio & ed::Polinomio::operator+=(double const &x)
{
	bool sumado = false;
	ed::Monomio monoaux(x,0);

	for (std::vector<ed::Monomio>::iterator it = this->getVector().begin(); it != this->getVector().end() && sumado != true; ++it){
		if(it->getGrado() == 0){
			it->setCoeficiente(it->getCoeficiente() + x);
			sumado = true;
		}
	}
	if(!sumado){
		this->getVector().push_back(monoaux);
	}

	this->ordenarPolinomio();
	// Se devuelve el objeto actual
	return *this;
}

ed::Polinomio & ed::Polinomio::operator-=(ed::Polinomio const &p)
{
	bool sumado;

	for (std::vector<ed::Monomio>::iterator it2 = p.getVector().begin() ; it2 != p.getVector().end(); ++it2){
		sumado = false;
		for (std::vector<ed::Monomio>::iterator it = this->getVector().begin(); it != this->getVector().end() && sumado != true; ++it){
			if(it->getGrado() == it2->getGrado()){
				it->setCoeficiente(it->getCoeficiente() - it2->getCoeficiente());
				sumado = true;
			}
		}
		if(!sumado){
			this->getVector().push_back(-(*it2));
		}
	}

	this->ordenarPolinomio();
	// Se devuelve el objeto actual
	return *this;
}

ed::Polinomio & ed::Polinomio::operator-=(ed::Monomio const &m)
{
	bool sumado = false;

	for (std::vector<ed::Monomio>::iterator it = this->getVector().begin(); it != this->getVector().end() && sumado != true; ++it){
		if(it->getGrado() == m.getGrado()){
			it->setCoeficiente(it->getCoeficiente() - m.getCoeficiente());
			sumado = true;
		}
	}
	if(!sumado){
		this->getVector().push_back(-m);
	}

	this->ordenarPolinomio();
	// Se devuelve el objeto actual
	return *this;
}

ed::Polinomio & ed::Polinomio::operator-=(double const &x)
{
	bool sumado = false;
	ed::Monomio monoaux(x,0);

	for (std::vector<ed::Monomio>::iterator it = this->getVector().begin(); it != this->getVector().end() && sumado != true; ++it){
		if(it->getGrado() == 0){
			it->setCoeficiente(it->getCoeficiente() - x);
			sumado = true;
		}
	}
	if(!sumado){
		this->getVector().push_back(-monoaux);
	}

	this->ordenarPolinomio();
	// Se devuelve el objeto actual
	return *this;
}

ed::Polinomio & ed::Polinomio::operator*=(ed::Polinomio const &p)
{
	ed::Polinomio *auxp = new ed::Polinomio();

	for (std::vector<ed::Monomio>::iterator it = this->getVector().begin() ; it != this->getVector().end(); ++it){
		for (std::vector<ed::Monomio>::iterator it2 = p.getVector().begin() ; it2 != p.getVector().end(); ++it2){
			*auxp += (*it * *it2);
		}
	}

	*this = *auxp;
	this->ordenarPolinomio();

	// Se devuelve el objeto actual
	return *this;
}

ed::Polinomio & ed::Polinomio::operator*=(ed::Monomio const &m)
{
	ed::Polinomio *auxp = new ed::Polinomio();

	for (std::vector<ed::Monomio>::iterator it = this->getVector().begin() ; it != this->getVector().end(); ++it){
		*auxp += (*it * m);
	}

	*this = *auxp;
	this->ordenarPolinomio();

	// Se devuelve el objeto actual
	return *this;
}
ed::Polinomio & ed::Polinomio::operator*=(double const &x)
{
	ed::Polinomio *auxp = new ed::Polinomio();

	for (std::vector<ed::Monomio>::iterator it = this->getVector().begin() ; it != this->getVector().end(); ++it){
		*auxp = (*it * x);
	}

	*this = *auxp;
	this->ordenarPolinomio();

	// Se devuelve el objeto actual
	return *this;
}

ed::Polinomio & ed::Polinomio::operator/=(ed::Polinomio const &p)
{//?
	#ifndef NDEBUG
		assert(this->getGrado() >= p.getGrado());
		assert(!(p.esNulo()));
	#endif

	*this = *this / p;
	this->ordenarPolinomio();

	// Se devuelve el objeto actual
	return *this;
}

ed::Polinomio & ed::Polinomio::operator/=(ed::Monomio const &m)
{
	#ifndef NDEBUG
		assert(this->getGrado() >= m.getGrado());
		assert(!(this->esNulo()));
		assert(abs(m.getCoeficiente()) > COTA_ERROR);	// m != 0.0
	#endif


	ed::Polinomio *auxp = new ed::Polinomio();

	for (std::vector<ed::Monomio>::iterator it = this->getVector().begin() ; it != this->getVector().end(); ++it){
		*auxp += (*it / m);
	}

	*this = *auxp;
	this->ordenarPolinomio();

	// Se devuelve el objeto actual
	return *this;
}
ed::Polinomio & ed::Polinomio::operator/=(double const &x)
{
	ed::Polinomio *auxp = new ed::Polinomio();

	for (std::vector<ed::Monomio>::iterator it = this->getVector().begin() ; it != this->getVector().end(); ++it){
		*auxp = (*it / x);
	}

	*this = *auxp;
	this->ordenarPolinomio();

	// Se devuelve el objeto actual
	return *this;
}
///////////////////////////////////////////////////////////////////////


// Funciones lectura y escritura de la clase Polinomio

void ed::Polinomio::leerPolinomio()
{
	int n;
	ed::Monomio *nuevo = new ed::Monomio();
	//vacía el polinomio
	this->getVector().erase (this->getVector().begin(), this->getVector().end());

	std::cout << BIGREEN;
	std::cout << "Introduzca el numero de monomios que va a tener el polinomio:" << '\n';
	std::cout << RESET;
	std::cin >> n;

	for(int i = 0; i < n; i++)
	{
		nuevo->leerMonomio();
		*this += *nuevo;
	}

	this->ordenarPolinomio();
}

void ed::Polinomio::escribirPolinomio() const
{
	for (std::vector<ed::Monomio>::iterator it = this->getVector().begin() ; it != this->getVector().end(); ++it){
		it->escribirMonomio();
		std::cout << ' ';
	}	
	//? std::cout << '\n';

}

///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Polinomio

double ed::Polinomio::calcularValor(double &x) const
{
	double total = 0.0;
	
	for (std::vector<ed::Monomio>::iterator it = this->getVector().begin() ; it != this->getVector().end(); ++it){
		total += it->calcularValor(x);
	}	

	return total;
}

//Funciones adicionales

ed::Polinomio & ed::Polinomio::Potencia(int &x){
	ed::Polinomio *nuevo = new ed::Polinomio();
	
	for(std::vector<ed::Monomio>::iterator it = this->getVector().begin() ; it != this->getVector().end(); ++it){
		*nuevo += it->Potencia(x);
	}

	return *nuevo;
}

bool ed::Polinomio::Comprueba(double &x, double &y){
	double aux;
	aux = this->calcularValor(x);
	if(abs(aux - y) < COTA_ERROR){
		return true;
	}
	else{return false;}
}