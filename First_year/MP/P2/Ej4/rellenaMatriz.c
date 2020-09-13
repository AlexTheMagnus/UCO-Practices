#include <stdio.h>
#include <time.h>
#include <cstdlib>

void rellenaMatriz (int **matriz, int nFil, int nCol){
  srand(time(0));
  for (int i =0; i<nFil; i++) {
    for (int j = 0; j<nCol; j++) {
      *(*matriz+i)+j=rand();
    }
  }
}
