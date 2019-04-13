#!/bin/bash

echo -n "Introduzca un número (1 <= x < 10): "; read numerote


if [ $numerote -ge 1 ] && [ $numerote -lt 10 ];
then
	echo "El número $numerote es correcto!"
else
	echo "Fuera de rango!"
fi
