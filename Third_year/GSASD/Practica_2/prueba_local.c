#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Para strcmp
#include <math.h>   //Para fabs
#include <time.h> //Para medir lo que tarda la ejecución

#define COTA_ERROR 1.0e-6

void suma(float operando1, float operando2){
	float  result;

	result = operando1 + operando2;
	printf("El resultado es %.2f\n", result);
}

void multiplica(float operando1, float operando2){
	float  result;

	result = operando1 * operando2;
	printf("El resultado es %.2f\n", result);
}

void divide(float operando1, float operando2){
	float  result;

	result = operando1 / operando2;
	printf("El resultado es %.2f\n", result);
}


int main (int argc, char *argv[])
{
	char operation[1];

	char *argoperation = argv[1];

	float operando1 = atof(argv[2]);
    float operando2 = atof(argv[3]);

	if (argc < 4) {
		printf ("Uso: %s operación operando1 operando2\n", argv[0]);
		exit (1);
	}



	if (strcmp(argoperation, "suma") == 0 || strcmp(argoperation, "+") == 0) {

        time_t start, end; //Variables auxiliares para medir el tiempo
        time(&start);	//Apunta en momento de inicio

    	for (int i = 0; i < 100000; i++) {	//100.000 llamadas a sumar
            printf("%d.- ", i);
    		suma(operando1, operando2);
        }

    	time(&end);	//Apunta el momento de finalización
    	time_t time_taken = end - start;	//Se calcula el tiempo invertido

    	printf("Tiempo invertido = %li seg\n", time_taken);
	}

	else if (strcmp(argoperation, "multiplicacion") == 0 || strcmp(argoperation, "x") == 0) {
		multiplica(operando1, operando2);
	}

	else if (strcmp(argoperation, "division") == 0 || strcmp(argoperation, "/") == 0) {
		if(fabs( atof(argv[3]) ) < COTA_ERROR){
            printf("Valor = %f\nCOTA ERROR = %f", fabs( atof(argv[3]) ), COTA_ERROR);
			printf("ERROR. No se puede dividir entre 0.\n");
			exit(-1);
		}
		divide(operando1, operando2);
	}

	else{
		printf ("%s is not a valid operation\n", argv[2]);
		exit (2);
	}
}
