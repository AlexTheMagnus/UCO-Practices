#include <stdio.h>
#include <stdlib.h>

int mcd(int x, int y){
  if(y==0){
    return x;
  }

  if(y>0 && x>=y){
    mcd(y,(x%y));
  }
  else{
    printf("Por favor, introduzca primero el numero mayor.\n");
    exit(-1);
  }
}

int main(){
  int x, y, res;
  printf("\n\t\t---Maximo Comun Divisor---\n\n\tIntroduzca el primer numero: ");
  scanf("%d", &x);
  printf("\tIntroduzca el otro numero: ");
  scanf("%d", &y);

  res = mcd(x,y);
  printf("\n\tMCD(%d,%d) = %d\n\n", x,y,res);
}
