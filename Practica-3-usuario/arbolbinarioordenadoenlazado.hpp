#ifndef __ARBOLBINARIOORDENADO_HPP__
#define __ARBOLBINARIOORDENADOENLAZADO_HPP__

#include <iostream>
#include <cassert>
#include "arbolbinarioordenado.hpp"
#include "operadornodo.hpp"

using namespace std;
/*!
\brief Espacio de nombres para la asignatura Estructura de datos.
*/
namespace ed
{
	/*!\brief Interfaz para definir un ArbolBinario ordenado.

	Define una interfaz para definir un ArbolBinarioOrdenado.

	\arg G define el campo de información a contener en el arbol.
	\pre G debe tener definidos los operadores < y ==.
	*/
	template<class G>
	class ArbolBinarioOrdenadoEnlazado:public ArbolBinarioOrdenado<G>
	{
	private:

		/*!\brief Define un nodo del arbol binario.*/
		class NodoArbolBinario
		{
		private:
			G _info;  //Valor informativo almacenado en el nodo
			NodoArbolBinario * _izquierdo;  //Puntero al hijo izquierdo
			NodoArbolBinario * _derecho;  //Puntero al hijo derecho

		public:
			NodoArbolBinario (const G &info)
			{
				setInfo(info);
				setIzquierdo(NULL);
				setDerecho(NULL);
			}

			NodoArbolBinario (const NodoArbolBinario &n)
			{
				setInfo(n.getInfo());
				setIzquierdo(n.getIzquierdo());
				setDerecho(n.getDerecho());
			}

			/*!\brief Observadores.*/
			const G & getInfo() const
			{
				return _info;
			}

			NodoArbolBinario *getIzquierdo() const
			{
				return _izquierdo;
			}

			NodoArbolBinario *getDerecho() const
			{
				return _derecho;
			}

			bool esHoja() const
			{
				if(getIzquierdo() == NULL && getDerecho() == NULL){
					return true;
				}
				return false;
			}

			void recorridoPreOrden (OperadorNodo<G> &operador) const
			{
				operador.aplicar(getInfo());
				getIzquierdo()->recorridoPreOrden(operador);
				getDerecho()->recorridoPreOrden(operador);
			}

			void recorridoPostOrden (OperadorNodo<G> &operador) const
			{
				getIzquierdo()->recorridoPreOrden(operador);
				getDerecho()->recorridoPreOrden(operador);
				operador.aplicar(getInfo());
			}

			void recorridoInOrden (OperadorNodo<G> &operador) const
			{
				getIzquierdo()->recorridoPreOrden(operador);
				operador.aplicar(getInfo());
				getDerecho()->recorridoPreOrden(operador);
			}

			/*!\brief Modificadores. */
			void setInfo(const G &info)
			{
				_info = info;
			}

			void setIzquierdo(NodoArbolBinario *n)
			{
				_izquierdo = n;
			}

			void setDerecho(NodoArbolBinario *n)
			{
				_derecho = n;
			}

			NodoArbolBinario & operator=(const NodoArbolBinario &n)
			{
				if(*this != n){
					setInfo(n.getInfo());
					setIzquierdo(n.getIzquierdo());
					setDerecho(n.getDerecho());
				}

				#ifndef NDEBUG
					assert(*this == n);
				#endif

				return *this;
			}

		}; //Fin clase NodoArbolBinario

		//Implementación de la raíz
		NodoArbolBinario * _raiz; /*!<Cursor a la raiz del árbol*/
		NodoArbolBinario * _actual; /*!<Cursor al nodo actual*/
		NodoArbolBinario * _padre; /*!<Cursor al nodo padre*/

	public:

		ArbolBinarioOrdenadoEnlazado ()
		{
			_raiz = NULL;
			_actual = NULL;
			_padre = NULL;

			#ifndef NDEBUG
				assert(estaVacio());
			#endif
		}

		ArbolBinarioOrdenadoEnlazado (const ArbolBinarioOrdenadoEnlazado<G>& a)
		{
			*this = a;

			#ifndef NDEBUG
				assert(*this == a);
			#endif
		}

		~ArbolBinarioOrdenadoEnlazado ()
		{
			if (not estaVacio())
			borrarArbol();
			cout << "Destructor Usado \n";
		}

		ArbolBinarioOrdenadoEnlazado &operator=(const ArbolBinarioOrdenadoEnlazado& a)
		{
			_raiz = a._raiz;
			_actual = a._actual;
			_padre = a._padre;

			return *this;
		}

		bool insertar(const G &x)
		{
			bool insertado = false;

			if(estaVacio()){
				_raiz = new NodoArbolBinario(x);
				_actual = _raiz;
				insertado = true;
			}

			NodoArbolBinario * aux = _raiz;	//Para recorrer el árbol
			while(!insertado){
				if(x < aux->getInfo()){
					if(aux->getIzquierdo() != NULL){
						aux = aux->getIzquierdo();
					}
					else{
						aux->setIzquierdo(new NodoArbolBinario(x));
						insertado = true;
					}
				}
				else if (x > aux->getInfo()) {
					if(aux->getDerecho() != NULL){
						aux = aux->getDerecho();
					}
					else{
						aux->setDerecho(new NodoArbolBinario(x));
						insertado = true;
					}
				}
				else{	//Este es el caso en el que x sea igual al aux
					return false;
				}
			}

			return insertado;
		}

		void borrarArbol()
		{
			#ifndef NDEBUG
				assert(this->_raiz != NULL);
			#endif

			_actual = NULL;
			_padre = NULL;
			_raiz = NULL;

			#ifndef NDEBUG
				assert(this->_raiz == NULL);
			#endif
		}

		bool borrar()
		{
			#ifndef NDEBUG
				assert(!estaVacio());
				G oldActual = _actual->getInfo();
			#endif

			if(_actual->esHoja()){		//Si es nodo hoja
				if(_actual == _raiz){
					borrarArbol();
				}
				else{
					if(_actual->getInfo() < _padre->getInfo()){	//Hijo izquierdo
						_padre->setIzquierdo(NULL);
					}
					else{										//Hijo derecho
						_padre->setDerecho(NULL);
					}
					_actual = _raiz;
					_padre = NULL;
				}
			}
			else{						//Si es un nodo rama
				NodoArbolBinario * aux = _padre;
				NodoArbolBinario * auxPadre = _actual;

				if(aux->getDerecho() != NULL){
					auxPadre = aux;
					aux = aux->getDerecho();

					//Seleccionar el  mayor inmediato si existe
					while(aux->getIzquierdo() != NULL){
						auxPadre = aux;
						aux = aux->getIzquierdo();
					}

					//Si el mayor inmediato tiene hijo derecho, se le engancha a su padre
					if(aux->getInfo() < auxPadre->getInfo()){
						auxPadre->setIzquierdo(aux->getDerecho());
					}
					//Caso donde el mayor inmediato es el hijo derecho del que se quiere borrar
					else{
						auxPadre->setDerecho(aux->getDerecho());
					}
				}
				else{
					auxPadre = aux;
					aux = aux->getIzquierdo();

					//Seleccionar el  menor inmediato
					while(aux->getDerecho() != NULL){
						auxPadre = aux;
						aux = aux->getDerecho();
					}
					//Se le engancha su hijo izquierdo a su padre
					if(aux->getInfo() > auxPadre->getInfo()){
						auxPadre->setDerecho(aux->getIzquierdo());
					}
					//Caso donde el menor inmediato es el hijo izquierdo del que se quiere borrar
					else{
						auxPadre->setIzquierdo(aux->getIzquierdo());
					}
				}
				_actual->setInfo(aux->getInfo());
			}

			#ifndef NDEBUG
				assert(!buscar(oldActual));
			#endif

			return true;
		}

		void recorridoPreOrden (OperadorNodo<G> &operador) const
		{
			_raiz->recorridoPreOrden(operador);
		}

		void recorridoPostOrden (OperadorNodo<G> &operador) const
		{
			_raiz->recorridoPostOrden(operador);
		}

		void recorridoInOrden (OperadorNodo<G> &operador) const
		{
			_raiz->recorridoInOrden(operador);
		}

		bool buscar(const G& x) 	//Lo tengo en el cuaderno de teoria
		{
			//Para recuperar sus valores en caso de no encontrar el elemento buscado
			NodoArbolBinario * actualCopia = _actual;
			NodoArbolBinario * padreCopia = _padre;

			bool encontrado = false;
			_actual = _raiz;
			_padre = NULL;

			while(_actual != NULL && !encontrado){
				if(_actual->getInfo() > x){
					_padre = _actual;
					if(_actual->getIzquierdo()!=NULL){
						_actual = _actual->getIzquierdo();
					}
					else{
					_actual = NULL;
					}
				}
				else if(_actual->getInfo() < x){
					_padre = _actual;
					if(_actual->getDerecho()!=NULL){
						_actual = _actual->getDerecho();
					}
					else{
						_actual = NULL;
					}
				}
				else{
					encontrado = true;
				}
			}
			if(!encontrado){
				_actual = actualCopia;
				_padre = padreCopia;
			}

			return encontrado;

			#ifndef NDEBUG
				assert((this->_actual)->getInfo() == x);
			#endif
		}

		bool estaVacio() const
		{
			if(_actual == NULL && _padre == NULL && _raiz == NULL){
				return true;
			}
			return false;
		}

		G raiz() const
		{
			#ifndef NDEBUG
				assert(!estaVacio());
			#endif

			return (this->_raiz)->getInfo();
		}

		bool existeActual() const
		{
			#ifndef NDEBUG
				assert(!estaVacio());
			#endif

			if(this->_actual == NULL){ return false; }
			else{ return true; }
		}

		G actual() const
		{
			#ifndef NDEBUG
				assert(existeActual());
			#endif

			return (this->_actual)->getInfo();
		}

		/*!@}*/
	};

} //namespace ed

#endif //__ARBOLORDENADO_HPP__
