#! /bin/bash
#  arg1 = carpeta

function listar_archivos() {
    for x in $(find $1 -maxdepth 1)
    do
        if [ -d $x ] && [ $x != $1 ]; then
            echo "<ul><li><strong>$x</strong></li>" >> $output
            listar_archivos $x
            echo "</ul>" >> $output
        elif [ $x != $1 ]; then
            echo "<li>$x</li>" >> $output
        fi
    done
}

output=$1.html

if [ $# -ne 1 ]; then
    echo "Error. El método de ejecución correcto es: ./ejercicio6 <directorio>"
else
    cd $1
    echo "Generando el listado de la carpeta $(pwd)/ sobre el fichero $output..."
    cd ..

    echo "<html>" > $output
    echo "<head>" >> $output
    echo "<title><h3>Listado del directorio $1</h3></title>" >> $output #<h3> ??
    echo "</head>" >> $output

    echo "<body>" >> $output
    echo '<style type="text/css">' >> $output
    echo "  body { font-family: sans-serif;}" >> $output
    echo "</style>" >> $output
    echo "<h1>Listado del directorio $1</h1>" >> $output
    echo "<ul>" >> $output
    listar_archivos $1
    echo "</ul>" >> $output
    echo "</body>" >> $output
    echo "</html>" >> $output

    echo "¡Terminado!"
fi
