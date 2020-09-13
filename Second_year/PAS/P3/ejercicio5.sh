#! /bin/bash

#arg1  \
#arg2   \
#...    /  ficheros $* $@
#argn /

#Crea ~/Copia si no existe
if ! [ -d ~/Copia ]; then
    mkdir ~/Copia
fi

#Crea el archivo comprimido
date=$(date +%s)
if [ $# -gt 0 ]; then
    tar -czf ~/Copia/copia-$(whoami)-$date.tar.gz $*
    echo "La copia de seguridad se ha creado correctamente."
else
    echo "Argumentos insuficientes para crear copia de seguridad"
fi


#Borra las copias antiguas
for x in $(find ~/Copia -type f)
do
    creation=$(stat $x -c %X)
    time=$[$date - $creation]
    if [ $time -gt 5 ]; then
        echo "Borrando $x de $time segundos..."
        rm -rf $x
    fi
done
