//Problema Productor-Consumidor. Modelo 1 (1 productor y 1 consumidor).

#include <pthread.h>
#include <stdlib.h>         //--Para srand y rand--
#include <semaphore.h>

#define TAMBUFFER 10
int buffer[TAMBUFFER];
int producido = 0, consumido = 0;

//Declaración de semáforos
semp_t lleno;       //Número de huecos ocupados en el buffer
sem_t vacio;        //Número de huecos libres en el buffer
sem_t stop;         //Semáforo binario para exclusión de sección crítica

//Declaración de funciones
void * produciendo();
void * consumiendo();
int RandomNumber();

/*
sem_wait(&stop);
/*Sección crítica
sem_post(&stop);
    */

int main(){

    extern sem_t lleno, vacio, stop;

    //Creación de hilos
    pthread_t productor;
    pthread_t consumidor;
    int status;

    extern int producido;
    extern int consumido;


    //Inicialización de los semáforos
    /*El segundo arg es 0 si el semaforo va a ser usado por hilos de un mismo proceso,
      si fueran procesos distintos, dicho arg debería valer 1.*/
    if((sem_init(&lleno, 0, 0)) == -1) {perror("Error. Fallo al inicializar el semáforo lleno\n");}
    if((sem_init(&vacio, 0, TAMBUFFER)) == -1) {perror("Error. Fallo al inicializar el semáforo vacio\n");}
    if((sem_init(&stop, 0, 1)) == -1) {perror("Error. Fallo al inicializar el semáforo stop\n");}



    //Creación del hilo productor
    if((status = pthread_create(&productor, NULL, produciendo, NULL))) {
        perror("Error al crear el hilo productor\n");
        exit(status);
    }

    //Creación del hilo consumidor
    if((status = pthread_create(&consumidor, NULL, consumiendo, NULL))) {
        perror("Error al crear el hilo consumidor\n");
        exit(status);
    }



    //Recogida del hilo productor
    if(pthread_join(productor, NULL)){
        perror("Error a recoger el hilo productor\n");
    }
    printf("Se ha producido: %i\n", producido);

    //Recogida del hilo consumidor
    if(pthread_join(consumidor, NULL)){
        perror("Error a recoger el hilo consumidor\n");
    }
    printf("Se ha consumido: %i\n", consumido);

}

//Función del hilo productor
void *produciendo(){
    extern int buffer[TAMBUFFER], producido;
    extern sem_t stop, lleno, vacio;

    for(int i = 0; i < 100; i++) {
        sem_wait(&vacio);
        sem_wait(&stop);
        buffer[/*lleno*/] = RandomNumber();
        producido += buffer[/*lleno*/];
        sem_post(&stop);
        sem_post(&lleno);
    }

}


//Función del hilo consumidor
void *consumiendo(void *p){
    extern int buffer[TAMBUFFER], consumido;
    extern sem_t stop, lleno, vacio;

    for(int i = 0; i < 100; i++) {
        sem_wait(&lleno);
        sem_wait(&stop);
        consumido += buffer[/*lleno*/];
        sem_post(&stop);
        sem_post(&vacio);
    }

}


int RandomNumber(){
    srand(time(NULL));
    return (rand() % 1001);
}
