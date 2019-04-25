#include <iostream>
#include <cstdlib> //para usar srand()

#include "arbolbinarioordenadoenlazado.hpp"
#include "operadornodo.hpp"
#include "persona.hpp"
#include "generarpersona.hpp"
#include "macros.hpp"

using namespace ed;
using std::cout;
using std::cin;

int main()
{
    srand(time(0));
    ArbolBinarioOrdenadoEnlazado<Persona> a;
    EscribirNodo<Persona> op;
    int opcion;


    cout << BIYELLOW;
    cout << "Test ArbolBinarioOrdenadoEnlazado:\n";
    cout << "\n" << RESET;

    while (opcion != 0) {
        cout << CLEAR_SCREEN;

        cout << BIBLUE;
        cout << "\t[1] Insertar personas en el arbol\n";
        cout << "\t[2] Buscar una persona\n";
        cout << "\t[3] Mostrar todas las personas del arbol\n";
        cout << "\t[4] Borrar una persona\n";
        cout << "\t[5] Borrar todas las personas\n";
        cout << RESET << BIRED;
        cout << "\t[0] Salir\n";
        cout << "\n" << RESET;

        cout << BIGREEN;
        cout << "Seleccione una opcion: ";
        cout << RESET;
        cin >> opcion;

        switch (opcion) {
            case 1:{            //Insertar personas en el arbol
                cout << CLEAR_SCREEN;
                cout << BIBLUE << "Insertar personas en el arbol\n" << RESET;
                cout << "\n";

                int n;
                cout << BIGREEN <<"Introduzca el numero de personas a insertar: " << RESET;
                cin >> n;

                for(int i = 0; i < n; i++){
                  a.insertar(generarDatosPersonales());
                }

                cout << BIGREEN << "DONE. Pulse intro para continuar" << RESET;
                getchar();
            }break;

            case 2:{            //Buscar una persona
                cout << CLEAR_SCREEN;
                cout << BIBLUE << "Buscar una persona\n" << RESET;

                if(! a.estaVacio()){
                    int auxDni;
                    Persona p;

                    cout << BIGREEN << "Introduzca el DNI de la persona a buscar: " << RESET;
                    cin >> auxDni;

                    p.dni(auxDni);
                    if(a.buscar(p)){
                        cout << BIGREEN << "Persona encontrada:\n" << RESET;
                        cout << a.actual() << '\n';
                    }
                    else{
                        cout << RED << "Error. La persona buscada no se encuentra en el arbol\n" << RESET;
                    }

                    cout << BIGREEN << "DONE. Pulse intro para continuar" << RESET;
                    getchar();
                }
                else{
                    cout << BIRED << "Error. Introduzca antes elementos en el arbol" << RESET;
                }
            }break;

            case 3:{            //Mostrar todas las persona
                cout << CLEAR_SCREEN;
                cout << BIBLUE << "Mostrar todas las personas del arbol\n" << RESET;

                if(! a.estaVacio()){
                    int opcion = -1;
                    while((opcion != 0) && (opcion != 1) && (opcion != 2)){
                      cout << BIGREEN << "Seleccione el método para mostrar:\n" << RESET;
                      cout << "\t[1] Pre-Orden\n";
                      cout << "\t[2] In-Orden\n";
                      cout << "\t[3] Post-Orden\n";
                      cout << "\n";
                      cout << "\tOpcion = ";
                      cin >> opcion;
                    }

                    switch (opcion)
                    {
                      case 1:
                        a.recorridoPreOrden(op);
                        break;
                      case 2:
                        a.recorridoInOrden(op);
                        break;
                      case 3:
                        a.recorridoPostOrden(op);
                        break;
                      default:
                        break;
                    }

                    cout << BIGREEN << "DONE. Pulse intro para continuar" << RESET;
                    getchar();
                }
                else{
                    cout << BIRED << "Error. Introduzca antes elementos en el arbol" << RESET;
                }
            }break;

            case 4:{            //Borrar una persona
                cout << CLEAR_SCREEN;
                cout << BIBLUE << "Borrar una persona\n" << RESET;

                if(! a.estaVacio()){
                    int auxDni;
                    Persona p;

                    cout << BIGREEN << "Introduzca el DNI de la persona a borrar: " << RESET;
                    cin >> auxDni;

                    p.dni(auxDni);
                    if(a.buscar(p)){
                        if(a.borrar()){
                            cout << BIGREEN << "Persona borrada" << RESET;
                        }
                        else{
                            cout << BIRED << "Error al borrar" << RESET;
                        }
                    }
                    else{
                        cout << "La persona a borrar no esta en el arbol";
                    }

                    cout << BIGREEN << "DONE. Pulse intro para continuar" << RESET;
                    getchar();
                }
                else{
                    cout << BIRED << "Error. Introduzca antes elementos en el arbol" << RESET;
                }
            }break;

            case 5:{            //Borrar todas las personas
                cout << CLEAR_SCREEN;
                cout << BIBLUE << "Borrar todas las personas\n" << RESET;
                a.borrarArbol();

                cout << BIGREEN << "DONE. Pulse intro para continuar" << RESET;
                getchar();
            }break;

            default:
                cout << BIRED << "Error. Opcion no valida, seleccione una del menu";
                cout << "Pulse intro para continuar" << RESET;
                getchar();
            break;
        }
    }
}
