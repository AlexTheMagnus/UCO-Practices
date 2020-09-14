<%@ page language="java" contentType="text/html; charset=UTF-8"%> <%@ page
import="java.text.*,java.util.*" %>

<% 
if(((Boolean)session.getAttribute("logged") != true) || !((session.getAttribute("CustomerType").toString()).equals("business")))
{
	response.sendRedirect("/ScienLink");
}
%>

<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <meta http-equiv="X-UA-Compatible" content="ie=edge" />
        <title>Editar perfil empresa</title>
        <link rel="stylesheet" href="../../css/global.css" />
        <script src="../../js/functions.js"></script>
    </head>
    <body>
        <%@ include file = "../../include/header.jsp" %>

        <div>
            <div class="perfil-editar">
                <!--Editar perfil empresa-->

                <div class="perfil-editar1">
                    <img
                        src="/ScienLink/img/usuario.png"
                        alt="Imagen no cargada"
                        height="200"
                        width="200"
                    />
                </div>

                <div class="perfil-editar2">
                    <h1>Nombre Empresa</h1>
                    <h1>Dedicacion Empresa</h1>
                    <h1>CorreoEmpresa@gmail.com</h1>
                    <a href="../businessProfile/businessProfileView.jsp"><h1>Pagina Empresa</h1></a>
                </div>
            </div>

            <div class="parrafo-editar">
                <h1>¿Quienes somos?</h1>
                <p>Texto vacío.</p>
            </div>

            <div class="parrafo-editar">
                <h1>¿Que buscamos?</h1>
                <p>Texto vacío.</p>
            </div>

            <div class="parrafo-editar">
                <h1>¿Que ofrecemos?</h1>
                <p>Texto vacío.</p>
            </div>

            <div id="elem" class="parrafo-editar" contenteditable="true">
                <h1>Ofertas de empleo</h1>
                <p>Texto vacío.</p>
            </div>

            <div>
                <p align="center">
                    <button
                        class="button-pressed-8"
                        id="button"
                        onclick="ToggleEdit()"
                    >
                    	Guardar
                    </button>
                    <form
                    	id="deleteBusiness"
	                	action="<%= request.getContextPath() %>/deleteAccountController" 
	                	method="get"
                    >
		                <button class="button-pressed-8" id="deleteBusinessButton">
	                    	Elminar cuenta
	                    </button>
                    </form>
                </p>
            </div>
        </div>

        <%@ include file = "../../include/footer.jsp" %>
    </body>
</html>
