<%@ page language="java" contentType="text/html; charset=UTF-8"%> <%@ page
import="java.text.*,java.util.*" %>

<% 
if(((Boolean)session.getAttribute("logged") != true))
{
	response.sendRedirect("/ScienLink");
}
%>

<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <meta http-equiv="X-UA-Compatible" content="ie=edge" />
        <title>Busqueda</title>
        <link rel="stylesheet" href="../../css/global.css" />
    </head>
    <body>
        <%@ include file = "../../include/header.jsp" %>

        <div class="columnas">
            <!--Contenedor de busquedas-->

            <div class="columna1">
                <div class="cajas-columna1">
                    <div class="cajas-columna1-header">
                        <div><h2>Titulo</h2></div>
                        <div>
                            <h2>
                                <a class="ancla-cajas-columna1" href="../userProfile/userProfileView.jsp"
                                    >Autor</a
                                >
                            </h2>
                        </div>
                        <div><h2>Fecha</h2></div>
                    </div>

                    <div>
                        <p>
                            Lorem ipsum dolor sit amet consectetur adipisicing
                            elit. Est magnam illum itaque minima deleniti
                            similique eius possimus totam expedita natus porro
                            non, modi consequuntur harum veritatis reprehenderit
                            voluptates sunt velit.
                        </p>
                    </div>

                    <div class="cajas-columna1-footer">
                        <div>
                            <a class="ancla-cajas-columna1" href="#">Like</a>
                        </div>
                        <div>
                            <a class="ancla-cajas-columna1" href="#"
                                >Comentar</a
                            >
                        </div>
                        <div>
                            <a class="ancla-cajas-columna1" href="#">Guardar</a>
                        </div>
                        <div>
                            <a class="ancla-cajas-columna1" href="#"
                                >Denunciar</a
                            >
                        </div>
                        <div>
                            <a class="ancla-cajas-columna1" href="#"
                                >Compartir</a
                            >
                        </div>
                    </div>
                </div>

                <div class="cajas-columna1">
                    <div class="cajas-columna1-header">
                        <div><h2>Titulo</h2></div>
                        <div>
                            <h2>
                                <a class="ancla-cajas-columna1" href="../userProfile/userProfileView.jsp"
                                    >Autor</a
                                >
                            </h2>
                        </div>
                        <div><h2>Fecha</h2></div>
                    </div>

                    <div>
                        <p>
                            Lorem ipsum dolor sit amet consectetur adipisicing
                            elit. Est magnam illum itaque minima deleniti
                            similique eius possimus totam expedita natus porro
                            non, modi consequuntur harum veritatis reprehenderit
                            voluptates sunt velit.
                        </p>
                    </div>

                    <div class="cajas-columna1-footer">
                        <div>
                            <a class="ancla-cajas-columna1" href="#">Like</a>
                        </div>
                        <div>
                            <a class="ancla-cajas-columna1" href="#"
                                >Comentar</a
                            >
                        </div>
                        <div>
                            <a class="ancla-cajas-columna1" href="#">Guardar</a>
                        </div>
                        <div>
                            <a class="ancla-cajas-columna1" href="#"
                                >Denunciar</a
                            >
                        </div>
                        <div>
                            <a class="ancla-cajas-columna1" href="#"
                                >Compartir</a
                            >
                        </div>
                    </div>
                </div>

                <div class="cajas-columna1">
                    <div class="cajas-columna1-header">
                        <div><h2>Titulo</h2></div>
                        <div>
                            <h2>
                                <a class="ancla-cajas-columna1" href="../userProfile/userProfileView.jsp"
                                    >Autor</a
                                >
                            </h2>
                        </div>
                        <div><h2>Fecha</h2></div>
                    </div>

                    <div>
                        <p>
                            Lorem ipsum dolor sit amet consectetur adipisicing
                            elit. Est magnam illum itaque minima deleniti
                            similique eius possimus totam expedita natus porro
                            non, modi consequuntur harum veritatis reprehenderit
                            voluptates sunt velit.
                        </p>
                    </div>

                    <div class="cajas-columna1-footer">
                        <div>
                            <a class="ancla-cajas-columna1" href="#">Like</a>
                        </div>
                        <div>
                            <a class="ancla-cajas-columna1" href="#"
                                >Comentar</a
                            >
                        </div>
                        <div>
                            <a class="ancla-cajas-columna1" href="#">Guardar</a>
                        </div>
                        <div>
                            <a class="ancla-cajas-columna1" href="#"
                                >Denunciar</a
                            >
                        </div>
                        <div>
                            <a class="ancla-cajas-columna1" href="#"
                                >Compartir</a
                            >
                        </div>
                    </div>
                </div>

                <div class="cajas-columna1">
                    <div class="cajas-columna1-header">
                        <div><h2>Titulo</h2></div>
                        <div>
                            <h2>
                                <a class="ancla-cajas-columna1" href="../userProfile/userProfileView.jsp"
                                    >Autor</a
                                >
                            </h2>
                        </div>
                        <div><h2>Fecha</h2></div>
                    </div>

                    <div>
                        <p>
                            Lorem ipsum dolor sit amet consectetur adipisicing
                            elit. Est magnam illum itaque minima deleniti
                            similique eius possimus totam expedita natus porro
                            non, modi consequuntur harum veritatis reprehenderit
                            voluptates sunt velit.
                        </p>
                    </div>

                    <div class="cajas-columna1-footer">
                        <div>
                            <a class="ancla-cajas-columna1" href="#">Like</a>
                        </div>
                        <div>
                            <a class="ancla-cajas-columna1" href="#"
                                >Comentar</a
                            >
                        </div>
                        <div>
                            <a class="ancla-cajas-columna1" href="#">Guardar</a>
                        </div>
                        <div>
                            <a class="ancla-cajas-columna1" href="#"
                                >Denunciar</a
                            >
                        </div>
                        <div>
                            <a class="ancla-cajas-columna1" href="#"
                                >Compartir</a
                            >
                        </div>
                    </div>
                </div>
            </div>

            <div class="columna2">
                <center><h3>Filtrar por título:</h3></center>
                <input type="radio" name="eleccion" value="1" />Ascendente
                <input type="radio" name="eleccion" value="1" />Descendente
                <hr />
                <center><h3>Filtrar por autor:</h3></center>
                <input type="radio" name="eleccion" value="2" />Ascendente
                <input type="radio" name="eleccion" value="2" />Descendente
                <hr />
                <center><h3>Filtrar por seguidores:</h3></center>
                <input type="radio" name="eleccion" value="3" />Mayor número
                <input type="radio" name="eleccion" value="3" />Menor número
                <hr />
                <button>Filtrar</button>
            </div>
        </div>

        <%@ include file = "../../include/footer.jsp" %>
    </body>
</html>
