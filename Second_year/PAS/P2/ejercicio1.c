/*
Ejemplo extraído del estándar POSIX y glibc.
Enlace a la página de documentación de la implemencación de getopt de glibc:
http://pubs.opengroup.org/onlinepubs/9699919799/functions/getopt.html
http://www.gnu.org/software/libc/manual/html_node/Getopt.html
http://www.gnu.org/software/libc/manual/html_node/Example-of-Getopt.html
*/

/*
./a.out
./a.out -a -m
./a.out -a m
./a.out m -a
./a.out -b -c
./a.out -b -c hola
*/


#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <string.h>

int main (int argc, char **argv)
{
    int aflag = 0;
    int uflag = 0;
    int iflag = 0;
    int index;
    int c;

    char *lang = "LANG";
    char *value;
    //Si el valor devuelto en value es "ES" imprime Español, sino imprime INGLES.
    value = getenv(lang);

    char *lgn;
    int uid;
    char *grnam;
    int grid;
    struct passwd *pw;
    struct group *gr;
    struct group *auxgr;

    FILE *f;
    char *linea;
    char auxname[100];
    char auxid[100];
    size_t maxtam = 100;

    /* getopt_long guardará el índice de la opción en esta variable. */
    int option_index = 0;

    /* Estructura a utilizar por getoptlong */
    static struct option long_options[] =
    {
        /* Opciones que no van a actuar sobre un flag */
        /* "opcion", recibe o no un argumento, 0,
           identificador de la opción */
        {"usurname",	 required_argument,	   0, 'u'},
        {"useruid",  required_argument,	   0, 'i'},
        {"groupname",  required_argument, 0, 'g'},
        {"groupuid",  required_argument, 0, 'd'},
        {"allgroups",  no_argument, 0, 's'},
        {"allinfo",  required_argument, 0, 'a'},
        {"bactive",  no_argument, 0, 'b'},
        {"help",  no_argument, 0, 'h'},
        /* Necesario para indicar el final de las opciones */
        {0, 0, 0, 0}
    };

    /* IMPORTANTE:
     Las variables optind, optarg, opterr y optopt son variables externas incluidas en <unistd.h> */

    /*
     If getopt() does not recognize an option character, it prints an error message to stderr,
     stores the character in optopt, and returns '?'. The calling program may prevent the error
     message by setting opterr to 0 */
    //Prueba a ejecutar el programa comentando esta linea, podrás observar como se obtiene un
    // error por defecto por la salida estandar, en este caso el terminal.
    opterr = 0;

    if(argc==1){
        //Si se llama sin argumentos

        //DEVUELVE LA ESTRUCTURA TRAS RECIBIR lgn COMO PARÁMETRO
        if ((lgn = getenv("USER")) == NULL || (pw = getpwnam(lgn)) == NULL)
        {
            fprintf(stderr, "Get of user information failed.\n");
            exit(1);
        }


        if (strstr(value,"EN"))
        {
            //Aqui ya se dispone de la estructura que contiene informacion del usuario
            printf("Name: %s\n", pw->pw_gecos); //No es lo mismo el nombre de usuario asociado a un login que el propio login
            printf("Login: %s\n", pw->pw_name);
            printf("Password: %s\n", pw->pw_passwd);
            printf("UID: %d\n", pw->pw_uid);
            printf("Home: %s\n", pw->pw_dir);
            printf("Shell: %s\n", pw->pw_shell);
            printf("Main group number: %d\n", pw->pw_gid);

            // Obtenemos la estructura de información del grupo a través del número de grupo al que pertenece el usuario
            gr = getgrgid(pw->pw_gid);

            //Se imprime el campo de la estructura que nos interesa
            printf("Main group name: %s\n", gr->gr_name);
        }
        else
        {
            //Aqui ya se dispone de la estructura que contiene informacion del usuario
            printf("Nombre: %s\n", pw->pw_gecos); //No es lo mismo el nombre de usuario asociado a un login que el propio login
            printf("Login: %s\n", pw->pw_name);
            printf("Contraseña: %s\n", pw->pw_passwd);
            printf("UID: %d\n", pw->pw_uid);
            printf("Home: %s\n", pw->pw_dir);
            printf("Interprete por defecto: %s\n", pw->pw_shell);
            printf("Número de grupo principal: %d\n", pw->pw_gid);

            // Obtenemos la estructura de información del grupo a través del número de grupo al que pertenece el usuario
            gr = getgrgid(pw->pw_gid);

            //Se imprime el campo de la estructura que nos interesa
            printf("Nombre del grupo principal: %s\n", gr->gr_name);
        }
        exit(0);
    }
    else{
        //Si se ha llamado con argumentos

        // "abc:" -> busca como opciones a y b sin argumentos y c con un argumento OBLIGATORIO.
        // ':' indica que la opcion debe llevar un argumento obligario

        // getopt va iterando, y devuelve -1 si ya hemos consultado toda la linea de argumentos.
        // Sino, devuelve el caracter de opción encontrado para caracteres validos
        // o devuelve ? si el caracter no es valido segun la cadena especificada.
        while ((c = getopt_long (argc, argv, "u:i:g:d:sa:bh", long_options, &option_index))!=-1)
        {
            // Podemos observar qué pasa con las variables externas que va gestionando
            //   getopt() durante las sucesivas llamadas.
            //   - optind: Indice del siguiente elemento a procesar del vector argv[]
            //   - optarg: recoge el valor del argumento obligario de una opcion.
            //   - optopt: recoge el valor de la opcion cuando es desconocida (?) o INCOMPLETA respecto a las opciones indicadas.
            switch (c)
            {
    		    case 'u':
                uflag = 1;
                    lgn = optarg;

                    if ((pw = getpwnam(lgn)) == NULL) //DEVUELVE LA ESTRUCTURA TRAS RECIBIR lgn COMO PARÁMETRO
                    {
                        fprintf(stderr, "Get of user information failed.\n");
                        exit(1);
                    }

                    printf("Nombre: %s\n", pw->pw_gecos); //No es lo mismo el nombre de usuario asociado a un login que el propio login
                    printf("Login: %s\n", pw->pw_name);
                    printf("Contraseña: %s\n", pw->pw_passwd);
                    printf("UID: %d\n", pw->pw_uid);
                    printf("Home: %s\n", pw->pw_dir);
                    printf("Interprete por defecto: %s\n", pw->pw_shell);
                    printf("Número de grupo principal: %d\n", pw->pw_gid);
    		        break;
    		    case 'i':
                    iflag = 1;
                    uid = atoi(optarg);

                    if ((pw = getpwuid(uid)) == NULL) //DEVUELVE LA ESTRUCTURA TRAS RECIBIR lgn COMO PARÁMETRO
                    {
                        fprintf(stderr, "Get of user information failed.\n");
                        exit(1);
                    }

                    printf("Nombre: %s\n", pw->pw_gecos); //No es lo mismo el nombre de usuario asociado a un login que el propio login
                    printf("Login: %s\n", pw->pw_name);
                    printf("Contraseña: %s\n", pw->pw_passwd);
                    printf("UID: %d\n", pw->pw_uid);
                    printf("Home: %s\n", pw->pw_dir);
                    printf("Interprete por defecto: %s\n", pw->pw_shell);
                    printf("Número de grupo principal: %d\n", pw->pw_gid);
    		        break;
    		    case 'g':
                    grnam = optarg;

                    if ((gr = getgrnam(grnam)) == NULL) //DEVUELVE LA ESTRUCTURA TRAS RECIBIR lgn COMO PARÁMETRO
                    {
                        fprintf(stderr, "Get of group information failed.\n");
                        exit(1);
                    }
                    //Se imprime el campo de la estructura que nos interesa
                 	printf("ID del grupo principal: %d\n", gr->gr_gid);
    		        break;
                 case 'd':
                    grid = atoi(optarg);

                    if ((gr = getgrgid(grid)) == NULL) //DEVUELVE LA ESTRUCTURA TRAS RECIBIR lgn COMO PARÁMETRO
                    {
                        fprintf(stderr, "Get of group information failed.\n");
                        exit(1);
                    }
                    //Se imprime el campo de la estructura que nos interesa
                    printf("Nombre del grupo principal: %s\n", gr->gr_name);
                    break;
                case 's':
                    f = fopen("/etc/group", "r");
                    getline(&linea, &maxtam, f);
                    while (!feof(f)) {
                        int i = 0;
                        for(;linea[i] != ':';i++){
                            auxname[i] = linea[i];
                        }
                    getline(&linea, &maxtam, f);

                    if ((gr = getgrnam(auxname)) == NULL) //DEVUELVE LA ESTRUCTURA TRAS RECIBIR lgn COMO PARÁMETRO
                    {
                        fprintf(stderr, "Get of user information failed.\n");
                        exit(1);
                    }

                    printf("Nombre del grupo = %s, GID = %d\n", gr->gr_name, gr->gr_gid);
                    }
                    fclose(f);
                    break;




                    /*f = fopen("/etc/group", "r");
                    getline(&linea, &maxtam, f);
                    printf("%s\n", linea);
                    while (!feof(f)) {
                        auxname = strtok(linea, ":");
                        strtok(NULL, ":");
                        auxid = strtok(linea, ":");
                        printf("Nombre del grupo = %s, GID = %s\n", auxname, auxid);
                        getline(&linea, &maxtam, f);
                    }
                    fclose(f);
                    break;*/
                case 'a':
                    aflag = 1;
                    lgn = optarg;

                    if ((pw = getpwnam(lgn)) == NULL) //DEVUELVE LA ESTRUCTURA TRAS RECIBIR lgn COMO PARÁMETRO
                    {
                        fprintf(stderr, "Get of user information failed.\n");
                        exit(1);
                    }

                    printf("Nombre: %s\n", pw->pw_gecos); //No es lo mismo el nombre de usuario asociado a un login que el propio login
                    printf("Login: %s\n", pw->pw_name);
                    printf("Contraseña: %s\n", pw->pw_passwd);
                    printf("UID: %d\n", pw->pw_uid);
                    printf("Home: %s\n", pw->pw_dir);
                    printf("Interprete por defecto: %s\n", pw->pw_shell);
                    printf("Número de grupo principal: %d\n", pw->pw_gid);

                    // Obtenemos la estructura de información del grupo a través del número de grupo al que pertenece el usuario
                 	gr = getgrgid(pw->pw_gid);

                 	//Se imprime el campo de la estructura que nos interesa
                 	printf("Nombre del grupo principal: %s\n", gr->gr_name);
    		        break;
                case 'b':
                    //DEVUELVE LA ESTRUCTURA TRAS RECIBIR lgn COMO PARÁMETRO
                    if ((lgn = getenv("USER")) == NULL || (pw = getpwnam(lgn)) == NULL)
                    {
                        fprintf(stderr, "Get of user information failed.\n");
                        exit(1);
                    }

                    gr = getgrgid(pw->pw_gid);
                    printf("Número de grupo principal: %s\n", gr->gr_name);
                    printf("ID del grupo principal: %d\n", gr->gr_gid);
    	            break;
                case 'h':
                    printf("-h, --help\t\tImprimir esta ayuda\n");
                    printf("-u, --username\t\tNombre de Usuario\n");
                    printf("-i, --useruid\t\tIdentificar de Usuario\n");
                    printf("-h, --groupname\t\tNombre de Grupo\n");
                    printf("-g, --groupuid\t\tIdentificador de Grupo\n");
                    printf("-d, --allgroups\t\tMuestra info de todos los grupos del sistema\n");
                    printf("-a, --allinfo\t\tNombre de Usuario\n");
                    printf("-b, --bactive\t\tMuestra info grupo usuario Actual\n");
                    break;
    		    case '?': //Opcion no reconocida o INCOMPLETA (sin argumento). Probar tambien la diferencia entre ejecutar %$>./a.out m   ó   %$>./a.out -m
    		        if (optopt == 'u' || optopt == 'i' || optopt == 'g' || optopt == 'd' || optopt == 'a') //Para el caso de que una opción no tenga el argumento obligatorio.
    		            fprintf (stderr, "La opción %c requiere un argumento. Valor de opterr = %d\n", optopt, opterr);
    		        else{ //Opcion erronea
                        printf("-h, --help\t\tImprimir esta ayuda\n");
                        printf("-u, --username\t\tNombre de Usuario\n");
                        printf("-i, --useruid\t\tIdentificar de Usuario\n");
                        printf("-h, --groupname\t\tNombre de Grupo\n");
                        printf("-g, --groupuid\t\tIdentificador de Grupo\n");
                        printf("-d, --allgroups\t\tMuestra info de todos los grupos del sistema\n");
                        printf("-a, --allinfo\t\tNombre de Usuario\n");
                        printf("-b, --bactive\t\tMuestra info grupo usuario Actual\n");
                    }
    		        return 1;  //Finaliza el programa
    		    default:
    		        abort ();
            }
            if(aflag && uflag){
                printf("Error. Las opciones -a y -u no deben invocarse a la vez\n");
            }
            if(iflag && uflag){
                printf("Error. Las opciones -i y -u no deben invocarse a la vez\n");
            }
        }
    }

    //Este último bucle controla opciones introducidas por el usuario que no hayan sido procesadas
    //por ser no reconocidas al no llevar un guion "-" delante.
    //Compara el número de argumentos recibidos con el número de opciones reconocidas mediante "-".
    //Como getopt() internamente reordena los valores de argv, las primeras posiciones de argv
    //corresponden a opciones conocidas y las últimas, a partir de optind, a opciones no reconocidas.

    for (index = optind; index < argc; index++)
        printf ("Argumento \"%s\" de la línea de comandos que NO ES UNA OPCIÓN.\n\n", argv[index]);

    return 0;
}
