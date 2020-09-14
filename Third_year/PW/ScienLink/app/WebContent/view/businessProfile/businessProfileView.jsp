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

<%Business customerBean = (Business)session.getAttribute("BusinessBean"); %>

<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <meta http-equiv="X-UA-Compatible" content="ie=edge" />
        <title>Perfil Empresa</title>
        <script src="/ScienLink/js/functions.js"></script>
        <link rel="stylesheet" href="../../css/global.css" />
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
                    <h1><%out.print(customerBean.getName()); %></h1>
                    
                    <%if(! ((customerBean.getShort_description()).toString().equals("Ninguna"))){%>
                    	<%out.print(customerBean.getShort_description()); %>
                    <%}%>
                    
                    <h1><%out.print(customerBean.getMail()); %></h1>
                    
                    <%if(! ((customerBean.getWebsite()).toString().equals("Ninguna"))){%>
                    	<%out.print(customerBean.getWebsite()); %>
                    <%}%>
                </div>

                <div class="img-engranaje">
                    <a href="../editBusinessProfile/editBusinessProfileView.jsp"
                        ><img src="/ScienLink/img/engranaje.png" height="40" width="40"
                    /></a>
                </div>
            </div>

            <div class="nav-editar">
                <div>
                    <button class="button-pressed" onclick="cambio1()">
                        ¿Quienes somos?
                    </button>
                </div>
                <div>
                    <button class="button-pressed" onclick="cambio2()">
                        ¿Que buscamos?
                    </button>
                </div>
                <div>
                    <button class="button-pressed" onclick="cambio3()">
                        ¿Que ofrecemos?
                    </button>
                </div>
                <div>
                    <form method="get" action="../jobOffers/jobOffersView.jsp">
                        <button class="button-pressed" type="submit">
                            Ofertas de empleo
                        </button>
                    </form>
                </div>
            </div>

            <div class="parrafo-editar">
                <h1 id="parrafo">¿Quieres saber más?</h1>
            </div>
        </div>

        <%@ include file = "../../include/footer.jsp" %>
    </body>
</html>
