<%@ page
	language="java" 
	contentType="text/html; charset=UTF-8"
	import="java.text.*,java.util.*" 
	import="database.*"
	import="model.*"%>

<% 
if(((Boolean)session.getAttribute("logged") != true))
{
	response.sendRedirect("/ScienLink");
}
%>

<%User customerBean = (User)session.getAttribute("CustomerBean"); %>

<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <meta http-equiv="X-UA-Compatible" content="ie=edge" />
        <title>Perfil usuario</title>
        <link rel="stylesheet" href="../../css/global.css" />
    </head>
    <body>
        <%@ include file = "../../include/header.jsp" %>

        <div>
            <div class="perfil-editar">
                <!--Editar perfil usuario-->

                <div class="perfil-editar1">
                    <img
                        src="/ScienLink/img/usuario.png"
                        alt="Imagen no cargada"
                        height="200"
                        width="200"
                    />
                </div>

                <div class="perfil-editar2">
                	<!-- Se muestra el nombre completo -->
                    <h1><%out.print(customerBean.getFirst()); %> <%out.print(customerBean.getLast()); %></h1>
                    
                    <!-- Se muestra el trabajao y afiliacion si las ha configurado -->
                    <%if(! ((customerBean.getJob()).toString().equals("Ninguno")) ||  ! ((customerBean.getAffiliation()).toString().equals("Ninguna"))){%>
                    	<h1>Trabaja 
                    <%}%>
                    <%if(! ((customerBean.getJob()).toString().equals("Ninguno"))){%>
                    	como <%out.print(customerBean.getJob()); %>
                    <%}%>
					<%if(! ((customerBean.getAffiliation()).toString().equals("Ninguna"))){%>
                    	en <%out.print(customerBean.getAffiliation()); %>
                    <%}%>
                   	<%if(! ((customerBean.getJob()).toString().equals("Ninguno")) ||  ! ((customerBean.getAffiliation()).toString().equals("Ninguna"))){%>
                    	</h1> 
                    <%}%>
                    
					<!-- Se muestra el mail -->
                    <h1><%out.print(customerBean.getMail()); %></h1>
                </div>

                <div class="img-engranaje">
                    <a href="../editUserProfile/editUserProfileView.jsp"
                        ><img src="/ScienLink/img/engranaje.png" height="40" width="40"
                    /></a>
                </div>
            </div>

            <div class="nav-editar">
                <div>
                    <a class="ancla-nav" href="../recentActivity/recentActivityView.jsp">Actividad Reciente</a>
                </div>
                <div><a class="ancla-nav" href="../users/usersView.jsp">Grupos</a></div>
                <div><a class="ancla-nav" href="../users/usersView.jsp">Seguidores</a></div>
                <div><a class="ancla-nav" href="../users/usersView.jsp">Seguidos</a></div>
                <div>
                    <a class="ancla-nav" href="#">Publicaciones guardadas</a>
                </div>
            </div>

			<!-- Se muestra el historial profesional si lo ha configurado -->
			<%if(! ((customerBean.getBackground()).toString().equals("Ninguno"))) {%>
	           	<div class="parrafo-editar">
	            	<h1>Historial profesional:</h1>
	            	<p><%out.print(customerBean.getBackground()); %></p>
	           	</div>
            <%}%>

			<!-- Se muestra el historial profesional si lo ha configurado -->
			<%if(! ((customerBean.getBackground()).toString().equals("Ninguno"))) {%>
	           	<div class="parrafo-editar">
	            	<h1>Mis intereses:</h1>
	            	<p><%out.print(customerBean.getInterests()); %></p>
	           	</div>
            <%}%>

        </div>

        <%@ include file = "../../include/footer.jsp" %>
    </body>
</html>
