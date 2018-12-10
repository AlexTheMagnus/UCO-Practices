//Problema Productor-Consumidor. Modelo 1 (1 productor y 1 consumidor).

#include <pthread.h>
#include <semaphore.h>

#define NCONSUM 1

sem_t stop;

/*El segundo arg es 0 si el semaforo va a ser usado por hilos de un mismo proceso,
  si fueran procesos distintos, dicho arg debería valer 1.*/
sem_init (&stop, 0, 1);
sem_wait(&stop);
/*Sección crítica*/
sem_post(&stop);


int main(){
  pthread_t consumidores[NCONSUM];
  int v[NCONSUM], status, producido, consumido;

  //Creación de hilos consumidores
  for (i = 0; i < NCONSUM; i++) {
    v[i] = i;
    if ((status = pthread_create(&consumidores[i], NULL, consumiendo, (void *) &v[i])))
      exit(status);
  }

  //Recogida de hilos consumidores
  for (i = 0; i < NCONSUM; i++) {
    pthread_join(consumidores[i], (void **) &r_value);
    printf("Valor devuelto por el hilo %lu : %lf\n", consumidores[i], *r_value);
  }

  ??? produciendo();
  producido += returndeproduciendo;


}


void *consumiendo(void *p){

}

??? produciendo(){}
