/*!
	\file Monomio.hpp
	\brief Definición de la clase Monomio
*/

#ifndef _MONOMIO_HPP_
#define _MONOMIO_HPP_

// Para usar la funciones pow y std::abs
#include <cmath>
using std::abs;

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

#define COTA_ERROR 1.0e-6  //!< Cota de error para la comparación números reales

// Se incluye la clase Monomio dentro del espacio de nombre de la asigantura: ed
namespace ed
{
//!  Definición de la clase Monomio:  \f$ coeficiente \hspace{1ex} X^{grado} \f$
class Monomio
{
	//! \name Atributos privados de la clase Monomio
	private:

	double coeficiente_;
	int grado_;

	//! \name Funciones o métodos públicos de la clase Monomio
	public:

	//! \name Constructores de la clase Monomio

	/**
	 * \brief Constructor de la clase monomio
	 * \param double coeficiente: coeficiente del monomio a crear
	 * \param int grado: grado del monomio a crear
	 * \pre El grado debe ser mayor o igual que 0
	 * \note Valores por defecto: coeficiente = 0.0, grado = 0
	*/
	Monomio(double coeficiente=0.0, int grado=0);

	/**
	 * \brief Constructor de copia de la clase monomio
	 * \param Monomio &m:referencia del monomio a copiar
	*/
	Monomio(Monomio const &m); //de copia


	//! \name Observadores: funciones de consulta de la clase Monomio

	/**
	 * \brief Observador del grado de la clase monomio
	 * \retval int grado_: valor del grado del monomio
	*/
	inline int getGrado() const {return grado_;};

	/**
	 * \brief Observador del coeficiente de la clase monomio
	 * \retval double coeficiente_: valor del coeficiente del monomio
	*/
	inline double getCoeficiente() const {return coeficiente_;};


	//! \name Funciones de modificación de la clase Monomio

	/**
	 * \brief Modificador del grado de la clase monomio
	 * \param int n: nuevo grado a asignar al monomio que llama al método
	 * \pre El grado debe ser mayor o igual que 0
	*/
	inline void setGrado(int n){
		#ifndef NDEBUG
			assert(n >= 0);
		#endif

		grado_=n;

		#ifndef NDEBUG
			assert(this->getGrado() == n);
		#endif
	}

	/**
	 * \brief Modificador del coeficiente de la clase monomio
	 * \param double x: nuevo coeficiente a asignar al monomio que llama al método
	*/
	void setCoeficiente(double x){
		coeficiente_=x;
		#ifndef NDEBUG
			assert(abs(this->getCoeficiente() - x) < COTA_ERROR );
		#endif
	}

	/////////////////////////////////////////////////

	//! \name Operadores de la clase Monomio

	// Operadores de asignación

		/**
		 * \brief Operador de asignación de monomios
		 * \param Monomio &m: referencia de un objeto monomio al que igual el que llama al método
		 * \retval *this: puntero al objeto que llama al método
		*/
		Monomio & operator=(Monomio const &m);

		/**
		 * \brief Operador para asignar un real a un monomio
		 * \param double &x: referencia de double para asignar al monomio que llama al método
		 * \retval *this: puntero al objeto que llama al método
		*/
		Monomio & operator=(double const &x);


	// Operadores aritméticos y asignación

		/**
		 * \brief Operador para sumar un monomio a otro monomio y asignarlo a este
		 * \param Monomio &m: referencia al monomio a sumar al que llama al método
		 * \retval *this: puntero al objeto que llama al método
		*/
		Monomio & operator+=(Monomio const &m);

		/**
		 * \brief Operador para restar un monomio a otro monomio y asignarlo a este
		 * \param Monomio &m: referencia al monomio a restar al que llama al método
		 * \retval *this: puntero al objeto que llama al método
		*/
		Monomio & operator-=(Monomio const &m);

		/**
		 * \brief Operador para multiplicar un monomio por otro y asignarlo
		 * \param Monomio &m: referencia al monomio a multiplicar por el que llama al método
		 * \retval *this: puntero al objeto que llama al método
		*/
		Monomio & operator*=(Monomio const &m);

		/**
		 * \brief Operador para dividir un monomio por otro y asignarlo
		 * \param Monomio &m: referencia al monomio para dividir al que llama al método
		 * \retval *this: puntero al objeto que llama al método
		*/
		Monomio & operator/=(Monomio const &m);

		/**
		 * \brief Operador para multiplicar un monomio por un real y asignarlo
		 * \param double &x: referencia al real para multiplicar por el monomio que llama al método
		 * \retval *this: puntero al objeto que llama al método
		*/
		Monomio & operator*=(double const &x);

		/**
		 * \brief Operador para dividir un monomio entre un real y asignarlo
		 * \param double &x: referencia al real para dividir al monomio que llama al método
		 * \retval *this: puntero al objeto que llama al método
		*/
		Monomio & operator/=(double const &x);

	/////////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones lectura y escritura de la clase Monomio

	/**
	 * \brief Método de lectura de monomio por teclado
	*/
	void leerMonomio();

	/**
	 * \brief Método de escritura de monomio por pantalla
	*/
	void escribirMonomio();

	///////////////////////////////////////////////////////////////////////

	//! \name Funciones auxiliares de la clase Monomio

	/**
	 * \brief Método para calcular el valor de un monomio asignadole un valor a la incognita
	 * \param double &x: referencia al real asignado a la variable del monomio
	 * \retval double total: valor del monomio una vez calculado
	*/
	double calcularValor(double &x);

	/**
	 * \brief Método para elevar un monomio a un entero
	 * \param int &x: referencia del entero al que se va a elevar
	 * \retval Monomio &: valor del monomio una vez elevado
	*/
	ed::Monomio & Potencia(int &x);

	/**
	 * \brief Método para comprobar si un punto está en la gráfica de un monomio
	 * \param double &x: referencia del real simboliza la coordenada "x" del punto
	 * \parma double &y: referencia del real simboliza la coordenada "y" del punto
	 * \retval bool: Devuelve true si está en la gráfica, false en caso contrario
	*/
	bool Comprueba(double &x, double &y);



};  // Fin de la definición de la clase Monomio

}  //  Fin de namespace ed.

// _MONOMIO_HPP_
#endif
