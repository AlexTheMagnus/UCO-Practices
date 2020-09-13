#include <stdio.h>
#include <string.h>


/*int es_sufijo(char *cadena, char *sufijo){
  if( strstr(*cadena, *sufijo) == NULL ){
    return 0;
  }
  else{
    int sizesuf = strlen(sufijo);
    int sizecad = strlen(cadena);
    for ( ; sizesuf >= 0; sizecad--, sizesuf--) {
      if(sufijo[sizesuf]==cadena[sizecad]) {}
      else {return 0;}
    }
    return 1;
  }
}*/


int main(){
  char cadena[9]="bicicleta";
  printf("Introduzca la cadena donde buscar:\n");
  gets(&cadena);
  printf("Esta es su cadena: %c\n", cadena);
  char sufijo[2]="ta";
  printf("Introduzca el sufijo a buscar:\n");
  gets(&sufijo);
  printf("Este es su sufijo: %c\n", sufijo);

/*if (es_sufijo(&cadena, &sufijo) ==1)
  printf("'%s' es sufijo de la cadena '%s'\n", sufijo, cadena);
else
  printf("'%s' no es sufijo de la cadena '%s'\n", sufijo, cadena);
*/
  return 0;
}


//strlen(cad) -> devuelve el tmaño de cad
