#include <stdio.h>
#include <string.h>

/*int cuentaletras (char c, char x, int *posicion){
  for(int i=0; i+posicion < (strlen(c)-1); i++){
    if(c[i+posicion] == x){
      posicion = posicion + i;
      return 1+cuentaletras(c, x, &posicion+1);
    }
  }
  return 0;
}*/

int main(){
  char c[100];
  char x[1];
  printf("Cadena: \n");
  fgets(c,100,stdin);
  printf("Letra\n");
  fgets(x,1,stdin);

  printf("Resultado %s, %s\n", c,x);
  int posicion = 0;
  //printf("Hay %d veces esa letra.\n", cuentaletras(c, x, &posicion));
}
