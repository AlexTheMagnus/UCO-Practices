#! /bin/bash

#Conteo e impresión del número de archivos en el directorio.
nArchivos=$(find . -maxdepth 1 -type f | wc -l)
echo "El número de archivos en la carpeta actual es $nArchivos"

#Lista de usuarios logeados en el sistema.
echo "$(who | awk '{print $1}' | sort | uniq)"

#Conteo de las veces que sale el caracter char en los nombres de los archivos.
read -t 5 -p '¿Qué carácter quieres contar?: ' char
if [ "$char" == "" ]; then
    char="a"
fi

for x in $(find)
do
    echo "$(basename $x)"
done | grep $char -o | wc -l > file.tmp

echo "El carácter $char aparece $(cat file.tmp) veces en nombres de ficheros o carpetas contenidos en la carpeta actual"
rm -rf file.tmp
