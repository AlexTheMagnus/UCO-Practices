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
        <title>Grupos</title>
        <link rel="stylesheet" href="../../../css/global.css" />
    </head>
    <body>
        <%@ include file = "../../../include/header.jsp" %>

        <div class="perfil-cambios">
            <!--Contenedor de los grupos-->

            <div class="cajas-editar">
                <div class="cajas-seguidores-seguidosxd">
                    <div class="perfil-editar1">
                        <img
                            src="/ScienLink/img/usuario.png"
                            alt="Imagen no cargada"
                            height="150"
                            width="150"
                        />
                    </div>

                    <div class="perfil-editar2">
                        <h1>Nombre completo</h1>
                        <h1>Afiliciación y puesto laboral</h1>
                    </div>
                </div>
                <div class="cajas-seguidores-seguidosxd">
                    <div class="perfil-editar1">
                        <img
                            src="/ScienLink/img/usuario.png"
                            alt="Imagen no cargada"
                            height="150"
                            width="150"
                        />
                    </div>

                    <div class="perfil-editar2">
                        <h1>Nombre completo</h1>
                        <h1>Afiliciación y puesto laboral</h1>
                    </div>
                </div>
                <div class="cajas-seguidores-seguidosxd">
                    <div class="perfil-editar1">
                        <img
                            src="/ScienLink/img/usuario.png"
                            alt="Imagen no cargada"
                            height="150"
                            width="150"
                        />
                    </div>

                    <div class="perfil-editar2">
                        <h1>Nombre completo</h1>
                        <h1>Afiliciación y puesto laboral</h1>
                    </div>
                </div>
            </div>

            <div class="menu-editar-2">
                <div class="cajas-seguidores-seguidosxd">
                    <div class="perfil-editar1">
                        <img
                            src="/ScienLink/img/usuario.png"
                            alt="Imagen no cargada"
                            height="150"
                            width="150"
                        />
                    </div>

                    <div class="perfil-editar2">
                        <h1>Nombre completo</h1>
                        <h1>Afiliciación y puesto laboral</h1>
                    </div>
                </div>
                <div class="cajas-seguidores-seguidosxd">
                    <div class="perfil-editar1">
                        <img
                            src="/ScienLink/img/usuario.png"
                            alt="Imagen no cargada"
                            height="150"
                            width="150"
                        />
                    </div>

                    <div class="perfil-editar2">
                        <h1>Nombre completo</h1>
                        <h1>Afiliciación y puesto laboral</h1>
                    </div>
                </div>
                <div class="cajas-seguidores-seguidosxd">
                    <div class="perfil-editar1">
                        <img
                            src="/ScienLink/img/usuario.png"
                            alt="Imagen no cargada"
                            height="150"
                            width="150"
                        />
                    </div>

                    <div class="perfil-editar2">
                        <h1>Nombre completo</h1>
                        <h1>Afiliciación y puesto laboral</h1>
                    </div>
                </div>
            </div>
        </div>

        <%@ include file = "../../../include/footer.jsp" %>
    </body>
</html>
