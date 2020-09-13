#include <stdio.h>

int **reservarMemoria (int nFil, int nCol){
  matriz=(int *)malloc(nFil*nCol*sizeof(int));
  return matriz;
}
