#include <stdio.h>

int minimo(int num1, int num2){
	if(num1>=num2){
		return num2;}
		else{return num1;}
}

void minimo_referencia(int num1, int num2,int *resultado){
	if(num1>=num2){
		*resultado=num2;}
		else{*resultado=num1;}
}

int main(int argc, const char *argv[]){
	int num1, num2, resultado;
	printf("Introduzca el primer numero:\n");
	scanf("%d", &num1);
	printf("Introduzca el otro numero:\n");
	scanf("%d", &num2);

	printf("El menor de la primera version es %d\n", minimo(num1, num2));
	minimo_referencia(num1, num2, &resultado);
	printf("El menor de la segunda version es %d\n", resultado);

	return 0;
}
