#include <stdio.h>

int main(){
  char nombre[100];
  int max, min, num;

  printf("Introduzca el nombre del fichero:\n");
  scanf("%s", nombre);
  printf("Introduzca el numero de elementos\n");
  scanf("%d\n", &num);
  printf("Introuzca el numero maximo\n");
  scanf("%d\n", &max);
  printf("Introuzca el numero minimo\n");
  scanf("%d\n", &min);

    int vec[];
    vec = (*int)malloc(num*sizeof(int));

  FILE* f = fopen(nombre, "wb");
}
