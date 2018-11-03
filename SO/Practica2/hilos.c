#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

double counter = 0;

#define ITER	1000
#define NHILOS	4

/*Eligiendo es un int porque no existen los bool en c.
 El 1 será considerado true y el 0 false.*/
int Eligiendo[NHILOS];
int Numero[NHILOS];


int main()
{
    //Algoritmo de Lamport: inicialización
    for(int i = 0; i < NHILOS; i++){
      Eligiendo[i] = 0;
      Numero[i] = 0;
    }
    //-------------------------------------

    pthread_t hilos[NHILOS];
    int status, i, v[NHILOS];
    extern double counter;
    void *Proceso(void *);
    double *r_value;

    // Create NHILOS threads
    for (i = 0; i < NHILOS; i++) {
	v[i] = i;
	if ((status = pthread_create(&hilos[i], NULL, Proceso, (void *) &v[i])))
	    exit(status);
    }

    // Wait threads
    for (i = 0; i < NHILOS; i++) {
	pthread_join(hilos[i], (void **) &r_value);
	printf("Value returned by %lu thread: %lf\n", hilos[i], *r_value);
    }

    // Final result
    fprintf(stdout, "%f\n", counter);

    return 0;
}

/*Funcion default para los hilos------------------------------
void *adder(void *p)
{
    double l, *to_return;
    extern double counter;
    int *id, i;

    id = (int *) p;

    for (i = 0; i < ITER; i++) {
      //Sección Crítica
    	l = counter;
    	fprintf(stdout, "Hilo %d: %f\n", *id, counter);
    	l++;
    	counter = l;
      //Fin Sección Crítica
    }

    to_return = malloc(sizeof(double));

    *to_return = counter;

    pthread_exit((void *) to_return);
}----------------------------------------------------------*/


int maximo(){                 //Calcula el maximo de un vector
  extern int Numero[NHILOS];
  int aux = 0;                //Guarda el mayor elemento del vector
  int mayor = Numero[0];      //Guarda el indice del vector correspondiente al mayor elemento

  for(int i = 1; i < NHILOS; i++){
    if(Numero[i] > aux){
      mayor = i;
      aux = Numero[i];
    }
  }
  return aux;
}


void *Proceso(void *p){
  double l, *to_return;
  extern double counter;
  int *id, i;
  id = (int *) p;

  extern int Eligiendo[NHILOS];
  extern int Numero[NHILOS];
  int j;

  i = 0;
  while( i < ITER ){
    Eligiendo[*id] = 1;
    Numero[*id] = Numero[maximo()] + 1;
    Eligiendo[*id] = 0;

    for(j = 0; j < NHILOS; j++){
      while(Eligiendo[j]);
      while((Numero[j] != 0) && ( (Numero[j] < Numero[*id]) || ( Numero[j] == Numero[*id] && *id < j ) ) ){
        //Sección Crítica
        l = counter;
        fprintf(stdout, "Hilo %d: %f\n", *id, counter);
        l++;
        counter = l;
        //Fin Sección Crítica
        //Numero[*id]
      }
    }
    i++;
  }

  to_return = malloc(sizeof(double));

  *to_return = counter;

  pthread_exit((void *) to_return);
}
