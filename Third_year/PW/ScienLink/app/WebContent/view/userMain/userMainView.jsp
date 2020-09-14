<%@ page
	language="java" 
	contentType="text/html; charset=UTF-8"
	import="java.text.*,java.util.*" 
	import="database.*"
	import="model.*"%>

<% 
if(((Boolean)session.getAttribute("logged") != true) || !((session.getAttribute("CustomerType").toString()).equals("user")))
{
	response.sendRedirect("/ScienLink");
}
%>

<%User customerBean = (User)session.getAttribute("CustomerBean"); %>

<html>
    <head>
        <link rel="stylesheet" type="text/css" href="../../css/global.css" />
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <script
            type="application/javascript"
            src="/ScienLink/js/functions.js"
        ></script>
        <title>Principal usuario</title>
    </head>
    <body>
    
        <%@ include file = "../../include/header.jsp" %>

        <div class="flex-div">
            <div class="main-colum">
                <!--Reproducir la lista con JSP-->
                <% for (int i=0;i<10;i++) { %>

                <div class="main-colum-div">
                    <div class="flex-div">
                        <div class="main-colum-tittle">
                            <a style="color: #e1820a"> Titulo </a>
                        </div>
                        <div class="main-colum-author">
                            <a class="basictext" href="../userProfile/userProfileView.jsp">Autor</a>
                        </div>
                        <div class="main-colum-date">
                            <a class="basictext">Fecha</a>
                        </div>
                    </div>
                    <div class="public-text">
                        Lorem ipsum dolor sit amet, consectetur adipisicing
                        elit, sed do eiusmod tempor incididunt ut labore et
                        dolore magna aliqua. Ut enim ad minim veniam, quis
                        nostrud exercitation ullamco laboris nisi ut aliquip ex
                        ea commodo consequat. Duis aute irure dolor in
                        reprehenderit in voluptate velit esse cillum dolore eu
                        fugiat nulla pariatur. Excepteur sint occaecat cupidatat
                        non proident, sunt in culpa qui officia deserunt mollit
                        anim id est laborum.
                    </div>
                    <div class="public-option">
                        <div>
                            <img
                                class="like"
                                type="image"
                                src="/ScienLink/img/nolike.png"
                                onclick="changeLike()"
                                id="likeButton"
                            />
                        </div>
                        <div><a class="basictext" href="#">Comentar</a></div>
                        <div><a class="basictext" href="#">Guardar</a></div>
                        <div><a class="basictext" href="#">Denunciar</a></div>
                        <div><a class="basictext" href="#">Compartir</a></div>
                    </div>
                </div>
                <% }%>
            </div>

            <div class="side-colum">
                <!--Filtro para busqueda de articulos-->
                <div class="sticky-div">
                    <form method="get" action="../createPost/createPostView.jsp">
                        <button class="button-pressed" type="submit">
                            Nueva publicación
                        </button>
                    </form>
                    <hr />
                    <div class="side-colum-div">
                        <p>Top publicaciones</p>
                        <hr />
                        <div class="side-colum-div-div">
                            <!--Reproducir la lista con JSP-->
                            <a class="side-colum-text" href="">Publicación 1</a
                            ><br />
                            <a class="side-colum-text" href="">Publicación 2</a
                            ><br />
                            <a class="side-colum-text" href="">Publicación 3</a
                            ><br />
                            <a class="side-colum-text" href="">Publicación 4</a
                            ><br />
                            <a class="side-colum-text" href="">Publicación 5</a
                            ><br />
                        </div>
                    </div>
                    <div class="side-colum-div">
                        <p>Top autores</p>
                        <hr />
                        <div class="side-colum-div-div">
                            <!--Reproducir la lista con JSP-->
                            <a class="side-colum-text" href="../userProfile/userProfileView.jsp">Autor 1</a
                            ><br />
                            <a class="side-colum-text" href="../userProfile/userProfileView.jsp">Autor 2</a
                            ><br />
                            <a class="side-colum-text" href="../userProfile/userProfileView.jsp">Autor 3</a
                            ><br />
                            <a class="side-colum-text" href="../userProfile/userProfileView.jsp">Autor 4</a
                            ><br />
                            <a class="side-colum-text" href="../userProfile/userProfileView.jsp">Autor 5</a
                            ><br />
                        </div>
                    </div>
                </div>
            </div>
        </div>

        <%@ include file = "../../include/footer.jsp" %>
        
    </body>
</html>
