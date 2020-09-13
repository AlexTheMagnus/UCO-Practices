#!/bin/bash

peliculas="ficherosPr2/peliculas.txt"

echo "*******"
echo "1) Líneas con la duración de las películas:"
grep -E '^[0-9]+hr [0-9]+min$' $peliculas
echo "*******"

echo "2) Líneas con el país de las películas:"
grep -E "\-.*\-$" $peliculas
echo "*******"

echo "3) Solo el país de la película:"
grep -E -o "\-.*\-$" $peliculas
echo "*******"

pelis16=$(grep -E -c "/2016" $peliculas)
pelis17=$(grep -E -c "/2017" $peliculas)
echo "4) Hay $pelis16 películas del 2016 y $pelis17 del 2017."
echo "*******"

echo "5) Eliminar las líneas vacías:"
grep -v "^$" $peliculas
echo "*******"

echo "6) Líneas que empiezan por la letra E (con o sin espacios antes):"
grep "^ *E" $peliculas
echo "*******"

echo "7) Líneas que contienen d, l o t, una vocal y la misma letra:"
grep -e 't[a-u]t' -e 'd[a-u]d' -e 'l[a-u]l' $peliculas
echo "*******"

echo "8) Líneas que contienen 8 aes o más:"
grep -iE '(.*a.*){8,}' $peliculas
echo "*******"

echo "9) No empiezan por espacio y acaban con 3 puntos ('...'):"
grep -E '^[^ ].*\.{3}$' $peliculas
echo "*******"

echo "10) Mostrar entre comillas las vocales con tilde:"
sed -r 's/([ÁÉÍÓÚáéíóú])/"\1"/g' $peliculas
echo "*******"
