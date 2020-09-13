#! /bin/bash

if [ $# -ne 1 ] && [ $# -ne 2 ]; then
    echo "Error. El método de ejecución correcto es: ./ejercicio2.sh <directorio> [numeroMinimoBytes]"
else

    if [ $# -eq 2 ]; then
    	nBytes=$2
    else
    	nBytes=0
    fi

    echo "Nombre LongitudUsuario FechaModificacion FechaAcceso Tamaño Bloques Permiso Ejecutable"

    for x in $(find $1 -size +"$nBytes"c -type f -o -size "$nBytes"c -type f)
    do
        let "longUsuario = $(stat -c %U $x | wc -m) - 1"

        if [ -x "$x" ]; then
            exec=1
        else
            exec=0
        fi

        echo "$(basename $x);$longUsuario;$(stat -c '%y;%X;%s;%b;%A' $x);$exec"
    done | sort -k 5 -n -t ';'
fi
