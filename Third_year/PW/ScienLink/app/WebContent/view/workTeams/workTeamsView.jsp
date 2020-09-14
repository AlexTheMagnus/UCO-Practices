<%@ page language="java" contentType="text/html; charset=UTF-8"%> <%@ page
import="java.text.*,java.util.*" %>

<% 
if(((Boolean)session.getAttribute("logged") != true) || !((session.getAttribute("CustomerType").toString()).equals("user")))
{
	response.sendRedirect("/ScienLink");
}
%>

<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <meta http-equiv="X-UA-Compatible" content="ie=edge" />
        <title>Grupos de trabajo</title>
        <link rel="stylesheet" href="../../css/global.css" />
    </head>
    <body>
        <%@ include file = "../../include/header.jsp" %>

        <div class="perfil-cambios">
            <!--Aqui se pueden editar los grupos-->

            <div class="cajas-editar">
                <div class="perfil-editar">
                    <div class="perfil-editar1">
                        <img
                            src="/ScienLink/img/usuario.png"
                            alt="Imagen no cargada"
                            height="200"
                            width="200"
                        />
                    </div>

                    <div class="perfil-editar2">
                        <h1>Nombre del grupo</h1>
                        <h1>Descripción corta del grupo de trabajo</h1>
                        <div class="conjunto-botones">
                            <div>
                                <button class="button-correo">
                                    <a href="#">
                                        <img
                                            src="/ScienLink/img/correo.png"
                                            alt="Imagen no cargada"
                                            height="25"
                                            width="25"
                                    /></a>
                                </button>
                            </div>
                            <div>
                                <button class="button-engranaje">
                                    <a href="#"
                                        ><img
                                            src="/ScienLink/img/engranaje.png"
                                            height="25"
                                            width="25"
                                    /></a>
                                </button>
                            </div>
                            <div>
                                <button class="button-papelera">
                                    <a href="#"
                                        ><img
                                            src="/ScienLink/img/trashcan.png"
                                            height="25"
                                            width="25"
                                    /></a>
                                </button>
                            </div>
                        </div>
                    </div>
                </div>

                <div class="boton-editar">
                    <center>
                        <button class="button-pressed-8">
                            Guardar cambios
                        </button>
                    </center>
                </div>
            </div>

            <div class="menu-editar">
                <!--Menu para editar-->
                <div class="perfil-editar">
                    <a class="ancla-menu" href="../editUserProfile/editUserProfileView.jsp">Editar perfil</a>
                </div>

                <div class="perfil-editar">
                    <a class="ancla-menu" href="../workTeams/workTeamsView.jsp">Grupos de trabajo</a>
                </div>

                <div class="perfil-editar">
                    <a class="ancla-menu" href="#">Publicaciones guardadas</a>
                </div>

                <div class="perfil-editar">
                	<form 
                	    id="deleteAccount"
	                	action="<%= request.getContextPath() %>/deleteAccountController" 
	                	method="get"
	                >
                    	<input class="deleteAccountButton" type="submit" value="Eliminar cuenta">
                    </form>
                </div>
            </div>
        </div>

        <%@ include file = "../../include/footer.jsp" %>
    </body>
</html>
