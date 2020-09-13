#!/bin/bash

if [ $# -ne 2 ] && [ -f $1 ]; then
    echo "Error. El método de uso correcto es: ./ejercicio3.sh <NombreDelFichero>"
else

    for x in $(grep -Eo '[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}' $1)
    do
        echo "$x" > aux.txt
        if [ $(grep -Eo '^[0-9]{1,3}' aux.txt) -lt 256 ]; then
            if pingRetVal=$(ping -c 1 -W "$2" $x); then
                echo $pingRetVal |sed -rn 's/.+[0-9]+ bytes from ([0-9\.]+): icmp_seq=1 ttl=[0-9]+ time=([0-9\.]+) ms.+\b/La IP \1 respondió en \2 milisegundos/p'
            else
                echo "La IP $x no respondio tras $2 segundos"
            fi
        fi
    done | sort -k7r -k6n
    rm -rf aux.txt
fi
