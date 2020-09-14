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
        <title>Crear publicacion</title>
        <link rel="stylesheet" href="../../css/global.css" />
    </head>
    <body>
        <%@ include file = "../../include/header.jsp" %>

        <section class="container-principal-publicar">
            <div class="input-publicar">
                <input
                    class="publicar-input"
                    type="text"
                    placeholder="Título"
                />
            </div>

            <div class="parrafo-publicar">
                <p>
                    Lorem ipsum dolor sit amet, consectetur adipisicing elit.
                    Impedit ea, perspiciatis quia, architecto qui, accusamus
                    minus molestias debitis exercitationem obcaecati omnis quae
                    assumenda rem reiciendis alias veritatis accusantium. Sunt,
                    quas?
                </p>
                <p>
                    Lorem ipsum dolor sit amet, consectetur adipisicing elit.
                    Impedit ea, perspiciatis quia, architecto qui, accusamus
                    minus molestias debitis exercitationem obcaecati omnis quae
                    assumenda rem reiciendis alias veritatis accusantium. Sunt,
                    quas?
                </p>
                <p>
                    Lorem ipsum dolor sit amet, consectetur adipisicing elit.
                    Impedit ea, perspiciatis quia, architecto qui, accusamus
                    minus molestias debitis exercitationem obcaecati omnis quae
                    assumenda rem reiciendis alias veritatis accusantium. Sunt,
                    quas?
                </p>
                <p>
                    Lorem ipsum dolor sit amet, consectetur adipisicing elit.
                    Impedit ea, perspiciatis quia, architecto qui, accusamus
                    minus molestias debitis exercitationem obcaecati omnis quae
                    assumenda rem reiciendis alias veritatis accusantium. Sunt,
                    quas?
                </p>
                <p>
                    Lorem ipsum dolor sit amet, consectetur adipisicing elit.
                    Impedit ea, perspiciatis quia, architecto qui, accusamus
                    minus molestias debitis exercitationem obcaecati omnis quae
                    assumenda rem reiciendis alias veritatis accusantium. Sunt,
                    quas?
                </p>
                <p>
                    Lorem ipsum dolor sit amet, consectetur adipisicing elit.
                    Impedit ea, perspiciatis quia, architecto qui, accusamus
                    minus molestias debitis exercitationem obcaecati omnis quae
                    assumenda rem reiciendis alias veritatis accusantium. Sunt,
                    quas?
                </p>
                <p>
                    Lorem ipsum dolor sit amet, consectetur adipisicing elit.
                    Impedit ea, perspiciatis quia, architecto qui, accusamus
                    minus molestias debitis exercitationem obcaecati omnis quae
                    assumenda rem reiciendis alias veritatis accusantium. Sunt,
                    quas?
                </p>
                <p>
                    Lorem ipsum dolor sit amet, consectetur adipisicing elit.
                    Impedit ea, perspiciatis quia, architecto qui, accusamus
                    minus molestias debitis exercitationem obcaecati omnis quae
                    assumenda rem reiciendis alias veritatis accusantium. Sunt,
                    quas?
                </p>
            </div>

            <div class="publicar-cancelar">
                <button class="button-pressed">Publicar</button>
                <button class="button-pressed">Cancelar</button>
            </div>
        </section>

        <%@ include file = "../../include/footer.jsp" %>
    </body>
</html>
