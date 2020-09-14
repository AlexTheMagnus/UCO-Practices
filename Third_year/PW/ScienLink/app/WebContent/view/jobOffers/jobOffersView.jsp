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
        <title>Ofertas de empresa</title>
        <link rel="stylesheet" href="../../css/global.css" />
    </head>
    <body>
        <%@ include file = "../../include/header.jsp" %>

        <section class="container-principal-empresa">
            <!--Contenedores de las ofertas-->

            <div class="caja-principal-empresa">
                <h1>Información del trabajo</h1>
                <p>
                    Lorem, ipsum dolor sit amet consectetur adipisicing elit.
                    Modi voluptates laboriosam consectetur id quae pariatur
                    maxime non adipisci porro blanditiis veniam dolorem
                    similique, nemo eos odit voluptas atque explicabo laborum.
                </p>
                <p>
                    Lorem, ipsum dolor sit amet consectetur adipisicing elit.
                    Modi voluptates laboriosam consectetur id quae pariatur
                    maxime non adipisci porro blanditiis veniam dolorem
                    similique, nemo eos odit voluptas atque explicabo laborum.
                </p>
            </div>

            <div class="caja-principal-empresa">
                <h1>Requisitos:</h1>
                <p>
                    Lorem, ipsum dolor sit amet consectetur adipisicing elit.
                    Modi voluptates laboriosam consectetur id quae pariatur
                    maxime non adipisci porro blanditiis veniam dolorem
                    similique, nemo eos odit voluptas atque explicabo laborum.
                </p>
                <p>
                    Lorem, ipsum dolor sit amet consectetur adipisicing elit.
                    Modi voluptates laboriosam consectetur id quae pariatur
                    maxime non adipisci porro blanditiis veniam dolorem
                    similique, nemo eos odit voluptas atque explicabo laborum.
                </p>
            </div>

            <div class="caja-principal-empresa">
                <h1>Descripción:</h1>
                <p>
                    Lorem ipsum dolor sit, amet consectetur adipisicing elit.
                    Beatae laudantium atque, nam placeat tempore consequatur
                    esse ipsam, ex provident quaerat tenetur fuga ipsum
                    laboriosam, alias qui ad labore repudiandae. Distinctio?.
                    Modi voluptates laboriosam consectetur id quae pariatur
                    maxime non adipisci porro blanditiis veniam dolorem
                    similique, nemo eos odit voluptas atque explicabo laborum.
                </p>
                <p>
                    Lorem, ipsum dolor sit amet consectetur adipisicing elit.
                    Modi voluptates laboriosam consectetur id quae pariatur
                    maxime non adipisci porro blanditiis veniam dolorem
                    similique, nemo eos odit voluptas atque explicabo laborum.
                </p>
            </div>

            <div>
                <center>
                    <button class="button-pressed-8" type="button">
                        Inscribirme en esta oferta
                    </button>
                </center>
            </div>
        </section>

        <%@ include file = "../../../include/footer.jsp" %>
    </body>
</html>
