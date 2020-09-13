//Problema Productor-Consumidor. Modelo 2 (P productor y C consumidor).

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>         //--Para srand y rand--
#include <semaphore.h>

#define TAMBUFFER 10
#define NPRODUCTOS 100     //Es el número de productos a producir y consumir
#define NPRODUCTORES 2
#define NCONSUMIDORES 2
int buffer[TAMBUFFER];
int producido = 0, consumido = 0;
int prodit = 0, consit = 0;     //Iteradores de los hilos productores y consumidores respectivamente

//Declaración de semáforos
sem_t lleno;       //Número de huecos ocupados en el buffer
sem_t vacio;        //Número de huecos libres en el buffer
sem_t stop;         //Semáforo binario para exclusión de sección crítica
sem_t semprodit;
sem_t semconsit;

//Declaración de funciones
void * produciendo();
void * consumiendo();
int RandomNumber();

int main(){
    extern sem_t lleno, vacio, stop;

    //Creación de hilos
    pthread_t productor[NPRODUCTORES];
    pthread_t consumidor[NCONSUMIDORES];
    int status;

    extern int producido;
    extern int consumido;


    //Inicialización de los semáforos
    /*El segundo arg es 0 si el semaforo va a ser usado por hilos de un mismo proceso,
      si fueran procesos distintos, dicho arg debería valer 1.*/
    if((sem_init(&lleno, 0, 0)) == -1) {printf("Error. Fallo al inicializar el semáforo lleno\n");}
    if((sem_init(&vacio, 0, TAMBUFFER)) == -1) {printf("Error. Fallo al inicializar el semáforo vacio\n");}
    if((sem_init(&stop, 0, 1)) == -1) {printf("Error. Fallo al inicializar el semáforo stop\n");}
    if((sem_init(&semprodit, 0, 1)) == -1) {printf("Error. Fallo al inicializar el semáforo semprodit\n");}
    if((sem_init(&semconsit, 0, 1)) == -1) {printf("Error. Fallo al inicializar el semáforo semconsit\n");}



    //Creación de los hilos productores
    int nprod[NPRODUCTORES];
    for (int i = 0; i < NPRODUCTORES; i++) {
        nprod[i] = i;
        if ((status = pthread_create(&productor[i], NULL, produciendo, NULL /*(void *) &nprod[i]*/ ))){
            printf("Error al crear el hilo productor nº %d\n", i);
            exit(status);
        }
    }

    //Creación de hilos consumidores
    int ncons[NPRODUCTORES];
    for (int i = 0; i < NCONSUMIDORES; i++) {
        ncons[i] = i;
        if ((status = pthread_create(&consumidor[i], NULL, consumiendo, NULL /*(void *) &ncons[i]*/ ))){
            printf("Error al crear el hilo consumidor nº %d\n", i);
            exit(status);
        }
    }



    int *suma = 0;

    //Recogida de los hilos productores
    for (int i = 0; i < NPRODUCTORES; i++) {
        if( status = pthread_join(productor[i], (void *) &suma )){
            printf("Error a recoger el hilo productor nº %d\n", nprod[i]);
        };
        printf("Total producido por el hilo nº %d = %d\n", nprod[i], *suma);
    }
    printf("hola no funcio4\n");
    //Recogida de los hilos productores
    for (int i = 0; i < NCONSUMIDORES; i++) {
        if( status = pthread_join(consumidor[i], (void *) &suma )){
            printf("Error a recoger el hilo consumidor nº %d\n", ncons[i]);
        };
        printf("Total consumido por el hilo nº %d = %d\n", ncons[i], *suma);
    }
    printf("hola no funcio5\n");
    //Producción y consumición total de todos los hilos
    printf("Se ha producido entre todos los hilos: %i\n", producido);
    printf("Se ha consumido entre todos los hilos: %i\n", consumido);

}

//Función del hilo productor
void *produciendo(){
    extern int buffer[TAMBUFFER], producido, prodit;
    extern sem_t stop, lleno, vacio, semprodit;
    int *suma, total = 0;
    printf("hola no produzco\n");
    sem_wait(&semprodit);
    for(; prodit < NPRODUCTOS;) {       //for(;prodit < NPRODUCTOS;)
        sem_wait(&vacio);
        sem_wait(&stop);
        buffer[ prodit % TAMBUFFER ] = RandomNumber();
        producido += buffer[ prodit % TAMBUFFER ];
        total += buffer[ prodit % TAMBUFFER ];
        prodit++;
        sem_post(&stop);
        sem_post(&lleno);

        sem_post(&semprodit);
        //printf("%d\n", prodit);
        if(prodit < NPRODUCTOS) {sem_wait(&semprodit);}
    }
    printf("hola no produzco nah\n");

    //Retorno del total producido del hilo
    suma = malloc(sizeof(int));
    *suma = total;
    pthread_exit( (void*)suma );
}


//Función del hilo consumidor
void *consumiendo(){
    extern int buffer[TAMBUFFER], consumido, consit;
    extern sem_t stop, lleno, vacio, semprodit;
    int *suma, total = 0;
    printf("hola no consumo\n");
    sem_wait(&semconsit);
    for(; consit < NPRODUCTOS;) {       //for(;consit < NPRODUCTOS;)
        sem_wait(&lleno);
        sem_wait(&stop);
        consumido += buffer[ consit % TAMBUFFER ];
        total += buffer[ consit % TAMBUFFER ];
        consit++;
        sem_post(&stop);
        sem_post(&vacio);

        sem_post(&semconsit);
        //printf("%d\n", consit);
        if(consit < NPRODUCTOS) {sem_wait(&semconsit);}
    }
    printf("hola no consumo nah\n");

    //Retorno del total consumido del hilo
    suma = malloc(sizeof(int));
    *suma = total;
    pthread_exit( (void*)suma );
}


int RandomNumber(){
    srand(time(NULL));
    return (rand() % 1001);
}
