#ifndef __FUNCIONES_HPP
#define __FUNCIONES_HPP

#include <iostream>
#include <cstring>
#include <cstdlib> //Para usar system
#include <fstream> //Para trabajar con ficheros
#include <sstream> //Para usar stringstream;

#include "grafo.hpp"
#include "algoritmosgrafos.hpp"

using namespace std;
using namespace ed;

int menu()
{
    int opcion;

    system("clear");
    cout << "  0. Salir................................\n";
    cout << "  1. Cargar grafo desde fichero...........\n";
    cout << "  2. Algoritmo de Floyd (GD y GND)......\n";

    cout << "Introduzca opcion...:";
    cin >> opcion;

    return opcion;
}

template <class G_Nodo, class G_Lado>
bool cargarGrafo(Grafo<G_Nodo, G_Lado> * &g)
{
    string ficheroMatriz, ficheroEtiquetas, aux;
    ifstream inputFile;
    int nNodos = 0;
    int index = 0;
    G_Nodo Node;
    G_Lado Edge;

    cout << "Fichero de la matriz de conexion: ";
    cin >> ficheroMatriz;

    cout << "Fichero de las etiquetas: ";
    cin >> ficheroEtiquetas;

    std::cout << "fufo1" << '\n';
    // TODO
    //Calculo el numero de nodos para reservar la memoria necesaria para la matriz
    inputFile.open(ficheroEtiquetas.c_str());
    while(getline(inputFile, aux)){
        nNodos++;
    }
    inputFile.close();
    std::cout << "fufo2" << '\n';
    //Reservo la memoria
    g->ReservaMemoria(nNodos);
    std::cout << "fufo3" << '\n';
    //Cargo las valores del grafo
    //Primero, los de los nodos
    inputFile.open(ficheroEtiquetas.c_str());
    while (inputFile >> aux) {
        stringstream stream(aux);
        stream >> Node;
        g->setNode(index, Node);
        index++;
    }
    inputFile.close();
    std::cout << "fufo4" << '\n';
    //Ahora, los de los lados
    inputFile.open(ficheroMatriz.c_str());
    for(int i = 0; i < g->getNodeNumber(); i++){
        for(int j = 0; j < g->getNodeNumber() - 1; j++){ //Leer próximo comentario
            getline(inputFile, aux, ' ');
            stringstream stream(aux);
            stream >> Edge;
            g->setEdge(i,j,Edge);
        }
        //j va solo hasta getNodeNumber - 1, ya que para el ultimo elemento de
        //la linea, el caracter separador debe cambiar de ' ' a '\n'
        getline(inputFile, aux, '\n');
        stringstream stream(aux);
        stream >> Edge;
        g->setEdge(i,g->getNodeNumber() - 1,Edge);
    }
    inputFile.close();

    //Las muestra al usuario para que compruebe que estan correctas
    std::cout << "MATRIZ DE DISTANCIAS:\n";
    g->imprimeMatriz();
    std::cout << "VECTOR DE NODOS:\n";
    g->imprimeVector();

    return true;
}

template <class G_Nodo, class G_Lado>
void algoritmoFloyd(const Grafo<G_Nodo, G_Lado> &g)
{
    // TODO
}

#endif
