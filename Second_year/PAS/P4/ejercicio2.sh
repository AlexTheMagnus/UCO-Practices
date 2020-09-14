#!/bin/bash
#Se ha usado # en lugar de / como caracter separador del sed ya que era necesario
#usar / para detectar las fechas

if [ $# -ne 1 ]; then
    echo "Error. El método de uso correcto es: ./ejercicio2.sh <NombreDelFichero>"
else
    grep -Ev '^[=]*$' $1 | sed -r '
    s#^\((.*/.*/.*)\) -.*-$#|-> Fecha de estreno: \1#g;
    s#^Dirigida por (.*)$#|-> Director: \1#g;
    s#^(Reparto: .*)$#|-> \1#g;
    /^ .*$/d;
    s#^(.hr .*min)$#|-> Duración: \1#g;
    s#^([^|].*)$#Titulo: \1#g;
    '
fi
