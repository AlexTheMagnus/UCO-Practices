/*!
   \file operadoresExternosPolinomios.cpp
   \brief Fichero que contiene el código de las funciones de la clase Polinomio
*/


// Ficheros de cabecera
#include <iostream>
#include <string>
#include <cstdlib>

#include "operadoresExternosPolinomios.hpp"

// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed
{
////////////////////////////////////////////////////////////////////////////////////
// Operadores de igualdad
bool operator==(ed::Polinomio const & p1, ed::Polinomio const & p2)
{
	std::vector<ed::Monomio>::iterator it2 = p2.getVector().begin();

	if(p1.getNumeroMonomios() != p2.getNumeroMonomios()){
		return false;
	}
	else{
		for (std::vector<ed::Monomio>::iterator it = p1.getVector().begin() ; it != p1.getVector().end(); ++it){
			if(*it != *it2){
				return false;
			}
			it2++;
		}
	}

	return true;
}

bool operator==(ed::Polinomio const & p, ed::Monomio const & m)
{
	if(p.getNumeroMonomios() != 1){
		return false;
	}
	else{
		if(p.getMonomio( m.getGrado() ) != m){
			return false;
		}
	}

	return true;
}

bool operator==( ed::Monomio const & m, ed::Polinomio const & p)
{
	if(p.getNumeroMonomios() != 1){
		return false;
	}
	else{
		if(p.getMonomio( m.getGrado() ) != m){
			return false;
		}
	}

	return true;
}

bool operator==( ed::Polinomio const & p, double const & x)
{
	if(p.getNumeroMonomios() != 1){
		return false;
	}
	else{
		if(p.getMonomio(0) != x){
			return false;
		}
	}

	return true;
}

bool operator==( double const & x, ed::Polinomio const & p)
{
	if(p.getNumeroMonomios() != 1){
		return false;
	}
	else{
		if(p.getMonomio(0) != x){
			return false;
		}
	}

	return true;
}


////////////////////////////////////////////////////////////////////////////////////
// Operadores de desigualdad
bool operator!=(ed::Polinomio const & p1, ed::Polinomio const & p2)
{
	std::vector<ed::Monomio>::iterator it2 = p2.getVector().begin();

	if(p1.getNumeroMonomios() != p2.getNumeroMonomios()){
		return true;
	}
	else{
		for (std::vector<ed::Monomio>::iterator it = p1.getVector().begin() ; it != p1.getVector().end(); ++it){
			if(*it != *it2){
				return true;
			}
			it2++;
		}
	}

	return false;
}

bool operator!=(ed::Polinomio const & p, ed::Monomio const & m)
{
	if(p.getNumeroMonomios() != 1){
		return true;
	}
	else{
		if(p.getMonomio( m.getGrado() ) != m){
			return true;
		}
	}

	return false;
}

bool operator!=( ed::Monomio const & m, ed::Polinomio const & p)
{
	if(p.getNumeroMonomios() != 1){
		return true;
	}
	else{
		if(p.getMonomio( m.getGrado() ) != m){
			return true;
		}
	}

	return true;
}

bool operator!=(ed::Polinomio const & p, double const & x)
{
	if(p.getNumeroMonomios() != 1){
		return false;
	}
	else{
		if(p.getMonomio(0) != x){
			return false;
		}
	}

	return false;
}

bool operator!=(double const & x, ed::Polinomio const & p)
{
	if(p.getNumeroMonomios() != 1){
		return true;
	}
	else{
		if(p.getMonomio(0) != x){
			return true;
		}
	}

	return false;
}

//////////////////////////////////////////////////////////////////////////////////////

// Operadores unarios prefijo

//Operador unario prefijo suma
ed::Polinomio & operator+(ed::Polinomio const & p)
{
	// Se crea un nuevo objeto
	ed::Polinomio *nuevo = new ed::Polinomio();
	*nuevo = p;

	#ifndef NDEBUG
		assert(*nuevo == p);
	#endif

	// Se devuelve el resultado
	return *nuevo;
}


//Operador unario prefijo resta
ed::Polinomio & operator-(ed::Polinomio const & p)
{
	// Se crea un nuevo objeto
	ed::Polinomio *nuevo = new ed::Polinomio();
	*nuevo = p;

	for (std::vector<ed::Monomio>::iterator it = nuevo->getVector().begin() ; it != nuevo->getVector().end(); ++it){
		*it = -(*it);
	}

	#ifndef NDEBUG
		assert((p + *nuevo).esNulo());
		//*nuevo == -p
	#endif

	// Se devuelve el resultado
	return *nuevo;
}

//////////////////////////////////////////////////////////////////////////////////////

// Operadores binarios de la suma
ed::Polinomio & operator+(ed::Polinomio const &p1,  ed::Polinomio const &p2)
{
	// Se crea un nuevo objeto
	ed::Polinomio *nuevo = new ed::Polinomio();
	ed::Monomio *auxmono = new ed::Monomio();
	*nuevo = p1;
	bool sumado;

	for (std::vector<ed::Monomio>::iterator it2 = p2.getVector().begin() ; it2 != p2.getVector().end(); ++it2){
		sumado = false;
		for (std::vector<ed::Monomio>::iterator it = p1.getVector().begin(); it != p1.getVector().end() && sumado != true; ++it){
			if(it->getGrado() == it2->getGrado()){
				*auxmono = *it + *it2;
				nuevo->getVector().push_back(*auxmono);
				sumado = true;
			}
		}
		if(!sumado){
			*auxmono = *it2;
			nuevo->getVector().push_back(*auxmono);
		}
	}

	nuevo->ordenarPolinomio();
	// Se devuelve el resultado
	return *nuevo;
}

ed::Polinomio & operator+(ed::Polinomio const &p,  ed::Monomio const &m)
{
	bool sumado = false;
	ed::Polinomio *nuevo = new ed::Polinomio();
	*nuevo = p;

	for (std::vector<ed::Monomio>::iterator it = nuevo->getVector().begin(); it != nuevo->getVector().end() && sumado != true; ++it){
		if(it->getGrado() == m.getGrado()){
			*it += m;
			sumado = true;
		}
	}
	if(!sumado){
		nuevo->getVector().push_back(m);
	}

	nuevo->ordenarPolinomio();
	// Se devuelve el objeto nuevo
	return *nuevo;
}

ed::Polinomio & operator+(ed::Monomio const &m, ed::Polinomio const &p)
{
	bool sumado = false;
	ed::Polinomio *nuevo = new ed::Polinomio();
	*nuevo = p;

	for (std::vector<ed::Monomio>::iterator it = nuevo->getVector().begin(); it != nuevo->getVector().end() && sumado != true; ++it){
		if(it->getGrado() == m.getGrado()){
			*it += m;
			sumado = true;
		}
	}
	if(!sumado){
		nuevo->getVector().push_back(m);
	}

	nuevo->ordenarPolinomio();
	// Se devuelve el objeto nuevo
	return *nuevo;
}

ed::Polinomio & operator+(ed::Polinomio const &p, double const &x)
{
	bool sumado = false;
	ed::Polinomio *nuevo = new ed::Polinomio();
	*nuevo = p;

	for (std::vector<ed::Monomio>::iterator it = nuevo->getVector().begin(); it != nuevo->getVector().end() && sumado != true; ++it){
		if(it->getGrado() == 0){
			*it += x;
			sumado = true;
		}
	}
	if(!sumado){
		ed::Monomio monoaux(x,0);
		nuevo->getVector().push_back(monoaux);
	}

	nuevo->ordenarPolinomio();
	// Se devuelve el objeto nuevo
	return *nuevo;
}

ed::Polinomio & operator+(double const &x, ed::Polinomio const &p)
{
	bool sumado = false;
	ed::Polinomio *nuevo = new ed::Polinomio();
	*nuevo = p;

	for (std::vector<ed::Monomio>::iterator it = nuevo->getVector().begin(); it != nuevo->getVector().end() && sumado != true; ++it){
		if(it->getGrado() == 0){
			*it += x;
			sumado = true;
		}
	}
	if(!sumado){
		ed::Monomio monoaux(x,0);
		nuevo->getVector().push_back(monoaux);
	}

	nuevo->ordenarPolinomio();
	// Se devuelve el objeto nuevo
	return *nuevo;
}


/////////////////////////////

// Resta
ed::Polinomio & operator-(ed::Polinomio const &p1,  ed::Polinomio const &p2)
{
	// Se crea un nuevo objeto
	ed::Polinomio *nuevo = new ed::Polinomio();
	ed::Monomio *auxmono = new ed::Monomio();
	*nuevo = p1;
	bool restado;

	for (std::vector<ed::Monomio>::iterator it2 = p2.getVector().begin() ; it2 != p2.getVector().end(); ++it2){
		restado = false;
		for (std::vector<ed::Monomio>::iterator it = p1.getVector().begin(); it != p1.getVector().end() && restado != true; ++it){
			if(it->getGrado() == it2->getGrado()){
				*auxmono = *it - *it2;
				nuevo->getVector().push_back(*auxmono);
				restado = true;
			}
		}
		if(!restado){
			*auxmono = -(*it2);
			nuevo->getVector().push_back(*auxmono);
		}
	}

	nuevo->ordenarPolinomio();
	// Se devuelve el resultado
	return *nuevo;
}

ed::Polinomio & operator-(ed::Polinomio const &p,  ed::Monomio const &m)
{
	bool restado = false;
	ed::Polinomio *nuevo = new ed::Polinomio();
	*nuevo = p;

	for (std::vector<ed::Monomio>::iterator it = nuevo->getVector().begin(); it != nuevo->getVector().end() && restado != true; ++it){
		if(it->getGrado() == m.getGrado()){
			*it -= m;
			restado = true;
		}
	}
	if(!restado){
		nuevo->getVector().push_back(-m);
	}

	nuevo->ordenarPolinomio();
	// Se devuelve el objeto nuevo
	return *nuevo;
}

ed::Polinomio & operator-(ed::Monomio const &m, ed::Polinomio const &p)
{
	bool restado = false;
	ed::Polinomio *nuevo = new ed::Polinomio();
	*nuevo = -p;

	for (std::vector<ed::Monomio>::iterator it = nuevo->getVector().begin(); it != nuevo->getVector().end() && restado != true; ++it){
		if(it->getGrado() == m.getGrado()){
			*it += m;
			restado = true;
		}
	}
	if(!restado){
		nuevo->getVector().push_back(m);
	}

	nuevo->ordenarPolinomio();
	// Se devuelve el objeto nuevo
	return *nuevo;
}

ed::Polinomio & operator-(ed::Polinomio const &p, double const &x)
{
	bool restado = false;
	ed::Polinomio *nuevo = new ed::Polinomio();
	*nuevo = p;

	for (std::vector<ed::Monomio>::iterator it = nuevo->getVector().begin(); it != nuevo->getVector().end() && restado != true; ++it){
		if(it->getGrado() == 0){
			*it -= x;
			restado = true;
		}
	}
	if(!restado){
		ed::Monomio monoaux(x,0);
		nuevo->getVector().push_back(-monoaux);
	}

	nuevo->ordenarPolinomio();
	// Se devuelve el objeto nuevo
	return *nuevo;
}

ed::Polinomio & operator-(double const &x, ed::Polinomio const &p)
{
	bool restado = false;
	ed::Polinomio *nuevo = new ed::Polinomio();
	*nuevo = -p;

	for (std::vector<ed::Monomio>::iterator it = nuevo->getVector().begin(); it != nuevo->getVector().end() && restado != true; ++it){
		if(it->getGrado() == 0){
			*it += x;
			restado = true;
		}
	}
	if(!restado){
		ed::Monomio monoaux(x,0);
		nuevo->getVector().push_back(monoaux);
	}

	nuevo->ordenarPolinomio();
	// Se devuelve el objeto nuevo
	return *nuevo;
}


	/////////////////////
	// Multiplicación

ed::Polinomio & operator*(ed::Polinomio const &p1, ed::Polinomio const &p2)
{
	ed::Polinomio *auxp = new ed::Polinomio();

	for (std::vector<ed::Monomio>::iterator it = p1.getVector().begin() ; it != p1.getVector().end(); ++it){
		for (std::vector<ed::Monomio>::iterator it2 = p2.getVector().begin() ; it2 != p2.getVector().end(); ++it2){
			*auxp += (*it * *it2);
		}
	}

	auxp->ordenarPolinomio();
	// Se devuelve el objeto nuevo
	return *auxp;
}

ed::Polinomio & operator*(ed::Polinomio const &p, ed::Monomio const &m)
{
	ed::Polinomio *auxp = new ed::Polinomio();

	for (std::vector<ed::Monomio>::iterator it = p.getVector().begin() ; it != p.getVector().end(); ++it){
		*auxp += (*it * m);
	}

	auxp->ordenarPolinomio();
	// Se devuelve el objeto nuevo
	return *auxp;
}

ed::Polinomio & operator*(ed::Monomio const &m, ed::Polinomio const &p)
{
	ed::Polinomio *auxp = new ed::Polinomio();

	for (std::vector<ed::Monomio>::iterator it = p.getVector().begin() ; it != p.getVector().end(); ++it){
		*auxp += (*it * m);
	}

	auxp->ordenarPolinomio();
	// Se devuelve el objeto nuevo
	return *auxp;
}

ed::Polinomio & operator*(ed::Polinomio const &p, double const &x)
{
	ed::Polinomio *auxp = new ed::Polinomio();

	for (std::vector<ed::Monomio>::iterator it = p.getVector().begin() ; it != p.getVector().end(); ++it){
		*auxp = (*it * x);
	}

	auxp->ordenarPolinomio();
	// Se devuelve el objeto nuevo
	return *auxp;
}

ed::Polinomio & operator*(double const &x, ed::Polinomio const &p)
{
	ed::Polinomio *auxp = new ed::Polinomio();

	for (std::vector<ed::Monomio>::iterator it = p.getVector().begin() ; it != p.getVector().end(); ++it){
		*auxp = (*it * x);
	}

	auxp->ordenarPolinomio();
	// Se devuelve el objeto nuevo
	return *auxp;
}
////////////////////////////////////
// División

ed::Polinomio & operator/(ed::Polinomio const &p1, ed::Polinomio const &p2)
{//?
	#ifndef NDEBUG
		assert(p1.getGrado() >= p2.getGrado());
	#endif
	//p1.ordenarPolinomio();
	//p2.ordenarPolinomio();

	ed::Polinomio *cociente = new ed::Polinomio();
	ed::Polinomio *resto = new ed::Polinomio();
	ed::Monomio *divisor = new ed::Monomio();		//Monomio resultado de cada iteracion y divisor en ella
	*cociente = 0.0;
	*resto = p1; 		//También hará de dividento

	while(resto->getGrado() >= p2.getGrado()){
		*divisor = (resto->getVector().front() / p2.getVector().front());
		*cociente += *divisor;
		*resto = *resto - (*divisor * p2);
		for(std::vector<ed::Monomio>::iterator it = resto->getVector().begin() ; it != resto->getVector().end(); ++it){
			if(it->getGrado() == 0){ resto->getVector().erase(it); }
		}
	}

	cociente->ordenarPolinomio();
	// Se devuelve el objeto actual
	return *cociente;
}

ed::Polinomio & operator/(ed::Polinomio const &p,ed::Monomio const &m)
{
	#ifndef NDEBUG
		assert(p.getGrado() >= m.getGrado());
	#endif

	ed::Polinomio *auxp = new ed::Polinomio();

	for (std::vector<ed::Monomio>::iterator it = p.getVector().begin() ; it != p.getVector().end(); ++it){
		*auxp += (*it / m);
	}

	auxp->ordenarPolinomio();
	// Se devuelve el objeto actual
	return *auxp;
}

ed::Polinomio & operator/(ed::Monomio const &m, ed::Polinomio const &p)
{//? Esto es lo mismo que polinomio entre polinomio, investigar
	#ifndef NDEBUG
		assert(m.getGrado() >= p.getGrado());
	#endif

	//p.ordenarPolinomio();

	ed::Polinomio *cociente = new ed::Polinomio();
	ed::Polinomio *resto = new ed::Polinomio();
	ed::Monomio *divisor = new ed::Monomio();		//Monomio resultado de cada iteracion y divisor en ella
	*cociente = 0.0;
	*resto = m; 		//También hará de dividento

	while(resto->getGrado() >= p.getGrado()){
		*divisor = (resto->getVector().front() / p.getVector().front());
		*cociente += *divisor;
		*resto = *resto - (*divisor * p);
		for(std::vector<ed::Monomio>::iterator it = resto->getVector().begin() ; it != resto->getVector().end(); ++it){
			if(it->getGrado() == 0){ resto->getVector().erase(it); }
		}
	}
	
	cociente->ordenarPolinomio();	//solo por si acaso
	// Se devuelve el objeto actual
	return *cociente;
}

ed::Polinomio & operator/(ed::Polinomio const &p, double const &x)
{
	#ifndef NDEBUG
		assert(abs(x) > COTA_ERROR);
	#endif

	ed::Polinomio *auxp = new ed::Polinomio();

	for (std::vector<ed::Monomio>::iterator it = p.getVector().begin() ; it != p.getVector().end(); ++it){
		*auxp = (*it / x);
	}

	auxp->ordenarPolinomio();
	// Se devuelve el objeto actual
	return *auxp;
}

//El polinomio debe tener grado 0 y coef distinto de 0.0
ed::Polinomio & operator/(double const &x, ed::Polinomio const &p)
{
	#ifndef NDEBUG
		assert(abs(x) > COTA_ERROR);
		assert(p.getGrado() == 0);
	#endif

	ed::Polinomio *auxp = new ed::Polinomio();

	*auxp = (x / p.getVector().front());
	
	auxp->ordenarPolinomio();
	// Se devuelve el objeto actual
	return *auxp;
}

////////////////////////////////////////////////////////////////////////////

// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, Polinomio &p)
{
	char cdato;
	std::string dato;
	p.getVector().clear();
	ed::Monomio *m = new ed::Monomio();

	stream.get(cdato);
	while(cdato != '\n'){
		std::getline(stream, dato, ' ');
		dato = cdato + dato;
		m->setCoeficiente(std::atof(dato.c_str()));
		std::getline(stream, dato, ' ');
		m->setGrado(std::atoi(dato.c_str()));

		p.getVector().push_back(*m);
		stream.get(cdato);
	}

	p.ordenarPolinomio();
	// Se devuelve el flujo de entrada
	return stream;
}



// Sobrecarga del operador de salida
ostream &operator<<(ostream &stream, Polinomio const &p)
{
	for(std::vector<ed::Monomio>::iterator it = p.getVector().begin() ; it != p.getVector().end(); ++it){
		stream << it->getCoeficiente() << " " << it->getGrado() << " ";
	}
	stream << "\n";

	// Se devuelve el flujo de salida
	return stream;
}


} // Fin del espacio de nombres ed
