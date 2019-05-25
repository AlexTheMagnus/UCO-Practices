#!/bin/bash

#read -p "x=" x

#if [ -f ejemploCarpeta ];
#then
#    echo "correcto"
#else
#    echo "error"
#fi

#echo -n " Introduzca un número : " ; read x
#until [ $x -le 0 ]; do
#echo $x
#x=$(($x -1))
#sleep 1
#done
#echo " TERMINADO "

#hola(){
#   echo "Esto es la func hola y tiene arg1=$1"
#}

#echo "Llamo a la func hola"
#hola pepinillo
#echo "Se acabo la funch hola"

if [ -d "ejemdploCarpeta" ] || [ -f ejercicio3.sh ]
then
    echo "Lo hay"
else
    echo "Y una mierda"
fi
