//Algoritmo_SJF (Shorter Job First) - Manuel Alejandro Luque León
#include <stdio.h>
#include <string.h>

#define NPROC 5

typedef struct params
{
    char nombre[10];
    int t_ejec;  // Se introducen
    int t_lleg;
    int t_com;   // Se calculan
    int t_fin;
    int t_ret;
    int t_esp;

} parametros;

void main(){

    int i;
    int ciclo = 0;

    // Inicialización de los datos de procesos
    parametros procesos[NPROC];
    strcpy(procesos[0].nombre, "A");
    procesos[0].t_ejec = 8;
    procesos[0].t_lleg = 0;
    procesos[0].t_com = 0;
    procesos[0].t_fin = procesos[0].t_ejec;
    procesos[0].t_ret = procesos[0].t_fin;
    procesos[0].t_esp = 0;

    strcpy(procesos[1].nombre, "B");
    procesos[1].t_ejec = 4;
    procesos[1].t_lleg = 1;

    strcpy(procesos[2].nombre, "C");
    procesos[2].t_ejec = 9;
    procesos[2].t_lleg = 2;

    strcpy(procesos[3].nombre, "D");
    procesos[3].t_ejec = 5;
    procesos[3].t_lleg = 3;

    strcpy(procesos[4].nombre, "E");
    procesos[4].t_ejec = 2;
    procesos[4].t_lleg = 4;

    int orden[NPROC-1] = {1,2,3,4};
    int temp;

    for (int i=1; i < NPROC-1; i++){  //Ordena los procesos de menor a mayor tiempo de ejecución (4,1,3,2)
      for (int j=0 ; j < (NPROC - 2); j++){
           if ((procesos[orden[j]].t_ejec) > (procesos[orden[j+1]].t_ejec)){
                temp = orden[j];
                orden[j] = orden[j+1];
                orden[j+1] = temp;
            }
        }
    }

    for(i=0; i< NPROC; i++)
    {
        if(i==0){
            /*Ya que el procesos[0] no esta contemplado en orden[] por ser el
            primero en ejecutarse ya que es el unico en estado listo en q=0*/
            procesos[i].t_com = 0;
            procesos[i].t_fin = procesos[i].t_com + procesos[i].t_ejec;
            procesos[i].t_ret = procesos[i].t_fin - procesos[i].t_lleg;
            procesos[i].t_esp = procesos[i].t_ret - procesos[i].t_ejec;
        }
        else{
            if(i==1) {procesos[orden[i-1]].t_com = procesos[0].t_fin;}  //Lo mismo que en el comentario anterior
            else {procesos[orden[i-1]].t_com = procesos[orden[i-2]].t_fin;}
            procesos[orden[i-1]].t_fin = procesos[orden[i-1]].t_com + procesos[orden[i-1]].t_ejec;
            procesos[orden[i-1]].t_ret = procesos[orden[i-1]].t_fin - procesos[orden[i-1]].t_lleg;
            procesos[orden[i-1]].t_esp = procesos[orden[i-1]].t_ret - procesos[orden[i-1]].t_ejec;
        }
    }

    printf("\nProceso | t_comienzo | t_final | t_retorno | t_espera\n");
    printf("-------------------------------------------------------\n");
    for(i=0; i< NPROC; i++)
    {
        printf("   %s \t    %d \t\t %d \t   %d \t      %d\n", procesos[i].nombre,procesos[i].t_com, procesos[i].t_fin, procesos[i].t_ret, procesos[i].t_esp);
    }

}
