#! /bin/bash
#arg1: carpeta
#arg2: umbral1 \  opc
#arg3: umbral2 /

if [ $# -ne 1 ] && [ $# -ne 3 ]; then
    echo "Error. El método de ejecución correcto es: ./ejercicio3.sh <directorio> [umbral1 umbral2]"
else
    carpeta=$1

    if [ $# -eq 3 ]; then
        umbral1=$2
        umbral2=$3
    else
        umbral1=10000
        umbral2=100000
    fi

    if [[ -d "pequenos" || -d "medianos" || -d "grandes" ]]; then
        echo "Las carpetas de salida ya existen, se va a proceder a borrarlas..."
        rm -rf pequenos medianos grandes
        mkdir pequenos medianos grandes
    else
        echo "Creando las carpetas pequenos, medianos y grandes..."
        mkdir pequenos medianos grandes
    fi

    echo "Copiando los archivos..."
    for file in $(find $carpeta -size -"$umbral1"c -type f -o -size "$umbral1"c -type f)
    do
        cp $file pequenos
    done

    for file in $(find $carpeta -size +"$umbral1"c -type f -a -size -"$umbral2"c -type f)
    do
        cp $file medianos
    done

    for file in $(find $carpeta -size +"$umbral2"c -type f -o -size "$umbral2"c -type f)
    do
        cp $file grandes
    done
fi
