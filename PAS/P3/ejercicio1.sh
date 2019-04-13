#! /bin/bash

cant1=$(find $1 -name "*.c" | wc -l)
cant2=$(find $1 -name "*.h" | wc -l)
echo "Tenemos  $cant1 ficheros con extenion .c y $cant2 ficheros con extension .h"

for x in $(find $1 -type f -name "*.c" -o -type f -name "*.h")
do
    echo "El fichero $x tiene $(cat $x |wc -l) lineas y $(cat $x |wc -c) caracteres"
done | sort -nr -k 8
