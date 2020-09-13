#ifndef __GRAFO_HPP__
#define __GRAFO_HPP__

#include <cassert>
#include <iostream>

using namespace std;

namespace ed
{

	template <class G_Nodo, class G_Lado>
	class Grafo
	{
	private:

		G_Lado **_lados;
		G_Nodo *_nodos;
		int *_numeroNodos;

	public:

		// constructores
		// TODO
		Grafo(){
			_numeroNodos = new int;
			*_numeroNodos = 0;
			_nodos = new G_Nodo;
			_lados = new G_Lado*;
		}

		Grafo(int n){
			ReservaMemoria(n);
		}

		Grafo(const Grafo &g){
			*this = g;
		}

		// destructor
		// TODO
		~Grafo(){
			borrarGrafo();
		}

		//Observadores
		inline int getNodeNumber() const {
			return *_numeroNodos;
		}

		inline G_Nodo getNode(int index) const {
			return _nodos[index];
		}

		inline G_Lado getEdge(int row, int column) const {
			return _lados[row][column];
		}

		void imprimeMatriz(){
			for(int i = 0; i < getNodeNumber(); i++){
				for(int j = 0; j < getNodeNumber(); j++){
					std::cout << getEdge(i, j) << " ";
				}
				std::cout << '\n';
			}
			std::cout << '\n';
		}

		void imprimeVector(){
			for(int i = 0; i < getNodeNumber(); i++){
				std::cout << getNode(i) << " ";
			}
			std::cout << '\n';
		}

		//Modificadores
		void setNode(int index, G_Nodo node) {
			_nodos[index] = node;
		}

		void setEdge(int row, int column, G_Lado edge) {
			_lados[row][column] = edge;
		}

		// funciones
		// TODO
		void borrarGrafo() {	// cabecera indicada para que compile
			delete [] _nodos;

			for(int i = 0; i < *_numeroNodos; i++){
				delete [] _lados[i];
			}
			delete [] _lados;

			delete _numeroNodos;

			_nodos = NULL;
			_lados = NULL;
			_numeroNodos = NULL;
		}


		Grafo& operator=(const Grafo &g){
			//Copia el _numeroNodos
			_numeroNodos = new int;
			*_numeroNodos = g.getNodeNumber();

			//Copia el _nodos
			_nodos = new G_Nodo[*_numeroNodos];
			for(int i = 0; i < *_numeroNodos; i++){
				_nodos[i] = g.getNode(i);
			}

			//Copia el _lados
			_lados = new G_Lado*[*_numeroNodos];
			for(int i = 0; i < *_numeroNodos; i++){
				_lados[i] = new G_Lado[*_numeroNodos];
			}
			//Igualo
			for(int i = 0; i < *_numeroNodos; i++){
				for(int j = 0; j < *_numeroNodos; j++){
					_lados[i][j] = g.getEdge(i,j);
				}
			}

			return *this;
		}


		void ReservaMemoria(int nNodos){
			_numeroNodos = new int;
			*_numeroNodos = nNodos;

			_nodos = new G_Nodo[nNodos];

			_lados = new G_Lado*[nNodos];
			for(int i = 0; i < nNodos; i++) {
				_lados[i] = new G_Lado[nNodos];
			}
		}

	};
}

#endif
