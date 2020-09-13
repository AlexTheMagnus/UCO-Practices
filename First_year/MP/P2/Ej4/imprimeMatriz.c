#include <stdio.h>

void imprimeMatriz (int **matriz, int nFil, int nCol){
  for (int i = 0; i < nFil; i++) {
    for (j = 0; j < nCol; j++) {
      printf("%d  ", *(*matriz+i)+j);
    }
    printf("\n");
  }
}
