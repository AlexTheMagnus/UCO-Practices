#!/bin/bash

cat /proc/cpuinfo | sed -r -n '1,/^$/p' | sed -r -n '
	s/^model name[\t]+: (.+)$/Modelo: \1/p;
	s/^cpu MHz[\t]+: ([0-9\.]+)$/Megahercios: \1/p;
	s/^cpu cores[\t]+: ([0-9]+)$/Número de hilos máximo de ejecución: \1/p;
	'
#Se podría hacer todo esto en el mismo comando, pero se ha divido en varios para
#mantener el orden en el que se piden en el ejercicio
cat /proc/cpuinfo | sed -r -n '1,/^$/p' | sed -r -n 's/^cache size[\t]+: (.+)$/Tamaño de caché: \1/p;'
cat /proc/cpuinfo | sed -r -n '1,/^$/p' | sed -r -n 's/^vendor_id[\t]+: (.+)$/ID vendedor: \1/p;'

echo "Puntos de montaje:"
cat /proc/mounts | sed -r -n 's/^(.+) (.+) (.+) (.+) (.+) (.+)$/-> Punto de montaje: \1, Dispositivo: \2, Tipo de dispositivo: \3/p' | sort -r

echo "Particiones y número de bloques:"
cat /proc/partitions | sed -r -n '3,$ s/[0-9][ \t]+[0-9]+[ \t]+([0-9]+)[  \t]*([a-z0-9]+)$/-> Partición: \2, Numero Bloques: \1/p'
