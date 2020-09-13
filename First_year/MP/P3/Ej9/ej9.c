//#include <stdio.h>
#include "ej9.h"

int main(){
  int opcion, nRegistros=0;

  while (opcion != 7) {

    printf("Escriba el numero y pulse intro para seleccionar una opción:\n\n");
    printf("------------------------------------------------------\n");
    printf("1. Comprobar existencia.\n");
    printf("2. Anadir libro.\n");
    printf("3. Contar libro.\n");
    printf("4. Ver libros en stock.\n");
    printf("5. Vender un libro.\n");
    printf("6. Borrar registro sin stock.\n");
    printf("7. Salir.\n");
    printf("------------------------------------------------------\n");

    scanf("%d", &opcion);
    switch (opcion) {
      case 1:{
        printf("Entro al 1\n");
        /*if(CheckbyTittle() == 1){
          printf("El libro existe\n");
        }
        else{
          printf("El libro no existe\n");
        }*/
      }break;

      case 2:{
      //  AddBook();
        printf("Entro al 2\n");
      }break;

      case 3:{
        nRegistros = Countbook();
        printf("Hay %d libros distintos.\n", nRegistros);
        printf("Entro al 3\n");
      }break;

      case 4:{
        //CheckStock();
        printf("Entro al 4\n");
      }break;

      case 5:{
        printf("Entro al 5\n");
        //SellBook();
      }break;

      case 6:{
        printf("Entro al 6\n");
        //DeleteBook();
      }break;
    }
  }
  printf("He salido\n");
}
