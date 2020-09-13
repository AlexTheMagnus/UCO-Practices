#include <stdio.h>
#include <stdlib.h> //exit, rand, srand
#include <unistd.h> //pipe, close, fork, usleep, read, write, getpid, getppid
#include <sys/wait.h> //wait
#include <errno.h> //Control de errores
#include <string.h> //strerror
//#include <time.h> //Para la semilla del generador de aleatorios


int es_primo(int numero) {
   int i;
   char es_primo = 1;
   i = 2;

   while( i<=numero/2 && es_primo==1 ) {
       if( numero % i == 0 ) {
           es_primo = 0;
       }
       i++;
    }
    return es_primo;
}



int main()
{
pid_t flag;
int status;
int tuberia1[2];
int tuberia2[2];
char i1[10];
char i2[10];
char *j1;
char *j2;
int i3;
int i4;
char *pr = "nada";
const int BSIZE = 22;
char buf[BSIZE];
ssize_t nbytes;

//Crea tuberia1
status = pipe(tuberia1);
if (status == -1 )
{
	perror("Error en pipe");
	exit(EXIT_FAILURE);
}

//Crea tuberia2
status = pipe(tuberia2);
if (status == -1 )
{
	perror("Error en pipe");
	exit(EXIT_FAILURE);
}

switch (fork())
{
	case -1: // Ocurrió un error al hacer fork()
		perror("No se ha podido crear el proceso hijo...");
		exit(EXIT_FAILURE);

	case 0: // El hijo lee desde la tubería1, no necesitamos escribir.
		if (close(tuberia1[1]) == -1)
		{
			perror("Error en close");
			exit(EXIT_FAILURE);
		}

        //No se necesita leer desde la tuberia2
        if (close(tuberia2[0]) == -1)
        {
            perror("Error en close");
            exit(EXIT_FAILURE);
        }

		// Leer la tuberia1 usando READ
		nbytes = read(tuberia1[0], buf, BSIZE);
		if (nbytes == -1)
		{
			perror("Error en read");
			exit(EXIT_FAILURE);
		}
		else if (nbytes == 0) //read() no ha leido nada -> Se ha llegado a EOF -> El padre ha cerrado la tuberia
			printf("[HIJO]: Detecto que mi padre ha cerrado la tuberia...\n");
		else{
			printf("[HIJO]: Leido %s de la tuberia.\n", buf);
            j1 = strtok(buf, ";");
            j2 = strtok(NULL, ";");
            i3 = atoi(j1);
            i4 = atoi(j2);

            if(abs(i3-i4)==2){
                pr = "gemelos";
            }
            else if (es_primo(i3) && es_primo(i4)) {
                pr = "primos";
            }
            else{
                pr = "no-primos";
            }
        }

		if (close(tuberia1[0]) == -1) //Cerramos tuberia1[0] para lectura
		{
			perror("Error en close");
			exit(EXIT_FAILURE);
		}
		else{
			printf("[HIJO]: Tuberia1 cerrada.\n");
        }

        // Escribimos datos en la tubería2
		if ( write(tuberia2[1], pr, BSIZE) == -1)
		{
			perror("Error en write");
			exit(EXIT_FAILURE);
		}

		// El padre verá FEOF (por hacer close)
		if (close(tuberia2[1]) == -1)
		{
			perror("Error en close");
			exit(EXIT_FAILURE);
		}
		else{
			printf("[HIJO]: Tuberia2 cerrada.\n");
        }

        //Acaba el hijo
		exit(EXIT_SUCCESS);



	default: // El padre escribe en la tubería
		// No se necesita leer por tuberia1
		if (close(tuberia1[0]) == -1)
		{
			perror("Error en close");
			exit(EXIT_FAILURE);
		}

        // No se necesita escribir por tuberia2
        if (close(tuberia2[1]) == -1)
        {
            perror("Error en close");
            exit(EXIT_FAILURE);
        }

        printf("Introduzca el primer entero: \n");
        scanf("%s", i1);

        printf("Introduzca el segundo entero: \n");
        scanf("%s", i2);

        //Se concatenan i1;i2
        strcat(i1,";");
        strcat(i1,i2);

		// Escribimos datos en la tubería1
		if ( write(tuberia1[1], i1, BSIZE) == -1)
		{
			perror("Error en write");
			exit(EXIT_FAILURE);
		}

		// El hijo verá FEOF (por hacer close)
		if (close(tuberia1[1]) == -1)
		{
			perror("Error en close");
			exit(EXIT_FAILURE);
		}
		else{
			printf("[PADRE]: Tuberia1 cerrada.\n");
        }

        // Leer la tuberia2 usando READ
        nbytes = read(tuberia2[0], buf, BSIZE);
        if (nbytes == -1)
        {
            perror("Error en read");
            exit(EXIT_FAILURE);
        }
        else if (nbytes == 0) //read() no ha leido nada -> Se ha llegado a EOF -> El hijo ha cerrado la tuberia
            printf("[PADRE]: Detecto que mi hijo ha cerrado la tuberia...\n");
        else{
            printf("[PADRE]: Los numeros son %s.\n", buf);
        }


		while ( (flag=wait(&status)) > 0 )
		{
			if (WIFEXITED(status))
			{
				printf("Proceso Padre, Hijo con PID %ld finalizado, status = %d\n", (long int)flag, WEXITSTATUS(status));
			} else if (WIFSIGNALED(status)) {  //Para seniales como las de finalizar o matar
				printf("Proceso Padre, Hijo con PID %ld finalizado al recibir la señal %d\n", (long int)flag, WTERMSIG(status));
			} else if (WIFSTOPPED(status)) { //Para cuando se para un proceso. Al usar wait() en vez de waitpid() no nos sirve.
				printf("Proceso Padre, Hijo con PID %ld parado al recibir la señal %d\n", (long int)flag,WSTOPSIG(status));
			} else if (WIFCONTINUED(status)){ //Para cuando se reanuda un proceso parado. Al usar wait() en vez de waitpid() no nos sirve.
				printf("Proceso Padre, Hijo con PID %ld reanudado\n",(long int) flag);
			}
		}
		if (flag==(pid_t)-1 && errno==ECHILD)
		{
			printf("Proceso Padre, valor de errno = %d, definido como %s, no hay más hijos que esperar!\n", errno, strerror(errno));
		}
		else
		{
			printf("Error en la invocacion de wait o la llamada ha sido interrumpida por una señal.\n");
			exit(EXIT_FAILURE);
		}

		exit(EXIT_SUCCESS);
	}//switch
}
