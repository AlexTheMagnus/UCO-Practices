/**
* Autor/es: Manuel Alejandro Luque León, Martin Paez Anguita, Juan Miguel Rivas Velasco
* Fichero: Fichero utilizado para las funciones de js utilizadas en la parte del cliente.
* Histórico:
* 12/11/2019 - Martin Paez Anguita: Añadidas funciones "Cambio()1,2,3,4".
* 12/11/2019 - Manuel Alejandro Luque León: Añadidas funciones "repetShowPassword" y "showPassword".
* 14/11/2019 - Martin Paez Anguita: Añadida funcion "ToggleEdit()".
* 15/11/2019 - Manuel Alejandro Luque León: Añadida función "validateEqualPassword".
* 21/11/2019 - Manuel Alejandro Luque León: Añadida función "changeLike".
* 21/11/2019 - Juan Miguel Rivas : Añadida función "mostrar_Titulo_ascendente", "mostrar_Seguidores_descendente", "elegir_Filtrado"
*/

//-----------Funciones #2 y #3---------------------------

/**
 * Permite variar entre visible/oculto el contenido
 *  del campo repetir contraseña en el registro.
 * @returns nothing
 */
function repetShowPassword() {
  var x = document.getElementById("repetPassword");
  if (x.type === "password") {
    x.type = "text";
  } else {
    x.type = "password";
  }
}

/**
 * Permite variar entre visible/oculto el contenido
 *  del campo contraseña en el registro.
 * @returns nothing
 */
function showPassword() {
    var x = document.getElementById("password");
    if (x.type === "password") {
        x.type = "text";
    } else {
        x.type = "password";
    }
}

/**
 * Comprueba que el valor de los campos contraseña y repetir contraseña sea
 *  el mismo en el registro.
 * @returns nothing
 */
function validateEqualPassword() {
    var password = document.getElementById("password").value;
    var repetedPassword = document.getElementById("repetPassword").value;

    if (repetedPassword === password) {
        document.getElementById('password').style.borderColor = "#ccc";
        document.getElementById('repetPassword').style.borderColor = "#ccc";

        return( true );
    }

    document.getElementById('password').style.borderColor = "red";
    document.getElementById('repetPassword').style.borderColor = "red";

    alert("La contraseña no coincide");

    return( false );
}

//-------------------------------------------------------


//-----------Funciones #4---------------------------

/**
 * Permite variar entre activo/inactivo el botón
 *  de "like" de las publicaciones.
 * @returns nothing
 */
function changeLike() {
    var x = document.getElementById("likeButton");
    if (x.getAttribute("src") === "/ScienLink/img/nolike.png") {
        x.src = "/ScienLink/img/like.png";
    } else {
        x.src = "/ScienLink/img/nolike.png";
    }
}


//---------------------------Funcion #10---------------------------
/**
 * @abstract Funcion para cambiar texto al pulsar un botton
 * @param {var} texto1,2,3,4: asigna un texto a la variable.
 * @function {Cambio()1,2,3,4} : Funciones que recogen una cadena de un variable y la asigna a un elemento para reemplazar el codigo html.
 * @returns nothing
 */
var texto = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
var texto2= "Es un hecho establecido hace demasiado tiempo que un lector se distraerá con el contenido del texto de un sitio mientras que mira su diseño. El punto de usar Lorem Ipsum es que tiene una distribución más o menos normal de las letras, al contrario de usar textos como por ejemplo . Estos textos hacen parecerlo un español que se puede leer. Muchos paquetes de autoedición y editores de páginas web usan el Lorem Ipsum como su texto por defecto, y al hacer una búsqueda.";
var texto3= "Neque porro quisquam est qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit...";
var texto4= "Todas las ofertas de empleo";
function cambio1() {
    document.getElementById('parrafo').innerHTML = texto;
}
function cambio2() {
    document.getElementById('parrafo').innerHTML = texto2;
}
function cambio3() {
    document.getElementById('parrafo').innerHTML = texto3;
}
function cambio4() {
    document.getElementById('parrafo').innerHTML = texto4;
}
/**
 * No funciona
 * @function {ToggleEdit()}
 * @abstract Funcion que deberia guardar un elmento modificado en el html para poder editarlo.
 */
function ToggleEdit() {

    var elem = document.getElementById ("elem");

    elem.contentEditable = elem.contentEditable == "true" ? "false" : "true";

}

//---------------------------Funciones Filtrado ---------------------------
/**
 * @abstract Funcion para mostrar en orden ascendente los elementos de un array
 * @param {var} lista_titulos: array que contiene los elementos a mostrar.
 * @returns nothing
 */

function mostrar_Titulo_ascendente(lista_titulos){
  lista_titulos.sort();
  for (let i = 0; i < lista_titulos.length; i++) {
    document.write( lista_titulos[i] + "<br/>")
  }
}

/**
 * @abstract Funcion para mostrar cientificos por seguidores de forma descendente
 * @param {var} lista_cientificos: array que almacena los cientificos
 * @function {(anterior, posterior)} : funcion usada dentro de sort() para comparar de forma descendente
 * @returns nothing
 * No funciona correctamente
 */
function mostrar_Seguidores_descendente(lista_cientificos) {
  lista_cientificos.sort(function (anterior, posterior) {
    if (anterior.seguidores < posterior.seguidores) {
      return 1;
    }
    if (prev.name > next.name) {
      return -1;
    }
    return 0;
  })
  for (let i = 0; i < lista_cientificos.length; i++) {
    document.write(lista_cientificos[i] + "<br/>")
  }
}

/**
 * @abstract Funcion que elige que filtrado usar
 * @param {var} filtro: variable que elige que casos se usa
 * @function mostrar_titulo_ascendente, ... : funciones para cada tipo de filtrado
 * @returns nothing
 */

function elegir_Filtrado(filtro)
{
  switch(filtro) {
    case 1:
      mostrar_Titulo_ascendente(lista_titulos);
      break;
    case 2:
     mostrar_Titulo_descendente(lista_titulos);
      break;
    case 3:
      mostrar_Autores_ascendente(lista_Cientificos);
      break;
    case 4:
      mostrar_Autores_descendente(lista_Cientificos);
      break;
    case 5:
      mostrar_Seguidores_ascendente(lista_Cientificos);
      break;
    case 6:
      mostrar_Seguidores_descendente(lista_Cientificos);
  }
  
}
