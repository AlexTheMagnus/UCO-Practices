#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Error. El método de uso correcto es: ./ejercicio3.sh <NombreDelFichero>"
else

    echo "===="
    echo "Listado de archivos ocultos del directorio $HOME"
    #ls -a:Para ver los archivos ocultos, -S:Para ordenarlos por tamaño
    ls -a -S $HOME | grep '^\..*$'

    if [ -f $1 ]; then
        NombFich="$1.sinLineasVacias"
        echo "===="
        echo "El fichero a procesar es $(basename $1)"
        grep -Ev '^$' $1 > $NombFich
        echo "El fichero sin lineas vacias se ha guardado en $(basename $NombFich)"
    fi

    echo "===="
    echo "Listado de procesos ejectuados por el usuario $USER"
    ps -xu | sed -r -n 's/^[^ ]+ +([^ ]+) +([^ ]+ +){6}([0-9]+:[0-9]+) +[^ ]+ +(.+)$/PID: "\1" Hora: "\3" Ejecutable: "\4"/p'
fi
