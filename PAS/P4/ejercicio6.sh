#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Error. El método de uso correcto es: ./ejercicio3.sh <shell>"
else
    while read line; do
        echo $line | sed -rn "s#^(.+):x:(.+):(.+):(.+):(.+):($1)#==========\nLogname: \1\n-> UID: \2\n-> GID: \3\n-> gecos: \4\n-> Home: \5\n-> Shell por defecto: \6#p;"
    done </etc/passwd
fi
