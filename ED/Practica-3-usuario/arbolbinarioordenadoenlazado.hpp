#ifndef __ARBOLBINARIOORDENADO_HPP__
#define __ARBOLBINARIOORDENADOENLAZADO_HPP__
//ESTO REALMENTE ES UN .HPP. RECUERDA RENOMBRARLO ??
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
				setInfo(&info);
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
				operador.aplicar();
				getIzquierdo()->recorridoPreOrden(&operador);
				getDerecho()->recorridoPreOrden(&operador);
			}

			void recorridoPostOrden (OperadorNodo<G> &operador) const
			{
				getIzquierdo()->recorridoPreOrden(&operador);
				getDerecho()->recorridoPreOrden(&operador);
				operador.aplicar();
			}

			void recorridoInOrden (OperadorNodo<G> &operador) const
			{
				getIzquierdo()->recorridoPreOrden(&operador);
				operador.aplicar();
				getDerecho()->recorridoPreOrden(&operador);
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
			//? lo mismo que buscar - de hecho debo usarlo

			return false;
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
			#endif

			_actual = NULL;
			_padre = NULL;
			return true;

			#ifndef NDEBUG
				assert(estaVacio());
			#endif
		}

		void recorridoPreOrden (OperadorNodo<G> &operador) const
		{
			// TODO
		}

		void recorridoPostOrden (OperadorNodo<G> &operador) const
		{
			// TODO
		}

		void recorridoInOrden (OperadorNodo<G> &operador) const
		{
			// TODO
		}

		bool buscar(const G& x) const	//Lo tengo en el cuaderno de teoria
		{
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
				else if{
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
