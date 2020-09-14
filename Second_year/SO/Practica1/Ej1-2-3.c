#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>

/*Aunque no se pedía en el ejercicio, he creado esta macro
 para poder controlar el rango de valores de los numeros del vector.
 El valor de MAX_NUMBER debe ser un número entero y positivo. */
#define MAX_NUMBER 9

int main(){
  void child1();
  void child2();
  void child3();
  int *v, shmid, status;
  key_t key;
  struct shmid_ds buf;

  //Memoria compartida
  key = ftok("Ej1-2-3.c", 1);
  if ((shmid = shmget(key, sizeof(int) * 100, IPC_CREAT | 0777)) == -1){
    exit(0);
  }
  v = (int*) shmat(shmid, NULL, 0);

  //Proceso padre
  srand(time(NULL));
  //Inicializa el vector con valores aleatorios
  for (int i = 0; i < 100; i++) {
    v[i] = ( rand() % (MAX_NUMBER + 1) );
  }

  //Imprime vector
  printf("Vector incial:\n");
  for(int i = 0; i < 100; i++){
    printf("%d -> %d\n", i, v[i] );
  }
  printf("\n");
  //


  if (!fork ()) {
      // Proceso hijo 1
      printf("Pid del hijo 1 = %d\n", getpid());
      child1();
      exit(1);
      //
    }

  if (!fork ()) {
      // Proceso hijo 2
      printf("Pid del hijo 2 = %d\n", getpid());
      child2();
      exit(2);
      //
    }

  if (!fork ()) {
      // Proceso hijo 3
      printf("Pid del hijo 3 = %d\n", getpid());
      child3();
      exit(3);
      //
    }

    for (int i = 0; i < 3; i++) {
    	pid_t pid = wait(&status);
    	printf("\nChild %d finished with status %d\n", pid, WEXITSTATUS(status));
    }

    //Imprime vector
    printf("Vector final:\n");
    for(int i = 0; i < 100; i++){
      printf("%d -> %d\n", i, v[i] );
    }
    printf("\n");
    //

    //Libero memoria compartida
    shmdt(v);

    //Elimino memoria compartida
    shmctl(shmid, IPC_RMID, &buf);
}

void child1(){
  int *v, shmid;
  key_t key;

  key = ftok("Ej1-2-3.c", 1);
  if ((shmid = shmget(key, (sizeof(int)*100), 0)) == -1){
    perror("Child1 error");
  }
  v = (int*) shmat(shmid, NULL, 0);

  //Proceso child1
  int aux, value;
  for (int i = 0; i < 10; i++) {
    printf("Introduzca el indice donde guardar el valor (entre 0 y 99):\n");
    scanf("%d", &aux);
    while (aux < 0 || aux > 99) {
      printf("Valor invalido. Introduzca un valor entre 0 y 99:\n");
      scanf("%d", &aux);
    }
    printf("Introduzca el valor a guardar en la posicion %d (entre 0 y %d):\n", aux, MAX_NUMBER);
    scanf("%d", &value);
    while (value < 0 || value > MAX_NUMBER) {
      printf("Valor invalido. Introduzca un valor entre 0 y %d:\n", MAX_NUMBER);
      scanf("%d", &value);
    }

    v[aux] = value;
  }
  //

  //Libero memoria
  shmdt(v);
}

void child2(){
  int *v, shmid;
  key_t key;

  key = ftok("Ej1-2-3.c", 1);
  if ((shmid = shmget(key, (sizeof(int)*100), 0)) == -1){
    perror("Child2 error");
  }
  v = (int*) shmat(shmid, NULL, 0);

  //Proceso child2
  for (int i = 0; i < 100; i++) {
    int aux, value;
    aux = ( rand() % 100 );
    value = ( rand() % ( MAX_NUMBER + 1 ) );
    v[aux] = value;
    sleep(1);
  }
  //

  //Libero memoria
  shmdt(v);
}

void child3(){
  int *v, shmid;
  key_t key;

  key = ftok("Ej1-2-3.c", 1);
  if ((shmid = shmget(key, (sizeof(int)*100), 0)) == -1){
    perror("Child3 error");
  }
  v = (int*) shmat(shmid, NULL, 0);

  //Proceso child3
  for (int j = 0; j < 5; j++) {
    int total = 0;
    for (int i = 0; i < 100; i++) {
      total += v[i];
    }
    printf("La suma es: %d\n", total);
    sleep(30);
  }
  //

  //Libero memoria
  shmdt(v);
}
