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
        <title>Principal empresa</title>
        <link rel="stylesheet" href="../../css/global.css" />
    </head>
    <body>
        <%@ include file = "../../../include/header.jsp" %>

        <section class="container-principal-empresa">
            <!--contenedor de empresa-->

            <div class="caja-principal-empresa">
                <h1>
                    <a class="persona-caja-empresa" href="../businessProfile/businessProfileView.jsp">Persona</a>
                </h1>
                <p>Texto sobre la formacion de la persona.</p>
            </div>

            <div class="caja-principal-empresa">
                <h1>
                    <a class="persona-caja-empresa" href="../businessProfile/businessProfileView.jsp">Persona</a>
                </h1>
                <p>Texto sobre la formacion de la persona.</p>
            </div>

            <div class="caja-principal-empresa">
                <h1>
                    <a class="persona-caja-empresa" href="../businessProfile/businessProfileView.jsp">Persona</a>
                </h1>
                <p>Texto sobre la formacion de la persona.</p>
            </div>

            <div class="caja-principal-empresa">
                <h1>
                    <a class="persona-caja-empresa" href="../businessProfile/businessProfileView.jsp">Persona</a>
                </h1>
                <p>Texto sobre la formacion de la persona.</p>
            </div>

            <div class="caja-principal-empresa">
                <h1>
                    <a class="persona-caja-empresa" href="../businessProfile/businessProfileView.jsp">Persona</a>
                </h1>
                <p>Texto sobre la formacion de la persona.</p>
            </div>

            <div class="caja-principal-empresa">
                <h1>
                    <a class="persona-caja-empresa" href="../businessProfile/businessProfileView.jsp">Persona</a>
                </h1>
                <p>Texto sobre la formacion de la persona.</p>
            </div>

            <div class="caja-principal-empresa">
                <h1>
                    <a class="persona-caja-empresa" href="../businessProfile/businessProfileView.jsp">Persona</a>
                </h1>
                <p>Texto sobre la formacion de la persona.</p>
            </div>
        </section>

        <%@ include file = "../../../include/footer.jsp" %>
    </body>
</html>
