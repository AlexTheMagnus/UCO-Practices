#! /bin/bash
#  arg1 = carpeta

function listar_archivos() {
    echo "<ul>"
    for x in $(find $1 -maxdepth 1)
        echo "<li><strong>$x</strong></li>"
    done
}

echo "<html>"
echo "<head>"
echo "<title><h3>listardo de dependencias de $1 </h3></title>"
echo "</head>"
echo "<body>"
listar_archivos($1)
echo "</body>"
echo "</html>"
