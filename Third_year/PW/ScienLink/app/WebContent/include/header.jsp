<%@ page language="java" contentType="text/html; charset=UTF-8"%> <%@ page
import="java.text.*,java.util.*" %>

<header class="box-header">
    <!--Cabezera del header para todos los wireframes-->
    <div class="img-logo">
    	<%
   	 	//En caso de estar loggeado como usuario
       	if((session.getAttribute("CustomerType").toString()).equals("user")){%>
        	<a href="../userMain/userMainView.jsp">
       	<%}
       	//En caso de estar loggeado como empresa
       	else if((session.getAttribute("CustomerType").toString()).equals("business")){%>
        	<a href="../businessMain/businessMainView.jsp">		
       	<%}
           %>
            <img
                src="/ScienLink/img/ScienLink.png"
                alt="Imagen no cargada"
                height="125"
                width="450"
            />
        </a>
    </div>

    <div class="inputheader">
        <input class="input" type="text" placeholder="Buscar..." />
        <img
            class="lupa"
            type="image"
            src="/ScienLink/img/lupa.png"
            href="../search/searchView.jsp"
            onclick=""
        />
    </div>

    <div class="img-balanza">
        <div>
	        <%
	   	 	//En caso de estar loggeado como usuario
	       	if((session.getAttribute("CustomerType").toString()).equals("user")){%>
	        	<a href="../userMain/userMainView.jsp">
	       	<%}
	       	//En caso de estar loggeado como empresa
	       	else if((session.getAttribute("CustomerType").toString()).equals("business")){%>
	        	<a href="../businessMain/businessMainView.jsp">		
	       	<%}
	           %>
		            <img
		                src="/ScienLink/img/balanza.png"
		                alt="Imagen no cargada"
		                height="100"
		                width="160"
		            />
				</a>
        </div>
        <div>
	        <%
	   	 	//En caso de estar loggeado como usuario
	       	if((session.getAttribute("CustomerType").toString()).equals("user")){%>
	        	<a class="header-ancla"  href="../userMain/userMainView.jsp">Principal</a>
	       	<%}
	       	//En caso de estar loggeado como empresa
	       	else if((session.getAttribute("CustomerType").toString()).equals("business")){%>
	        	<a class="header-ancla"  href="../businessMain/businessMainView.jsp">Principal</a>
	       	<%}
	           %>
        </div>
    </div>

    <div class="img-user">
        <div>
        	<%
	   	 	//En caso de estar loggeado como usuario
	       	if((session.getAttribute("CustomerType").toString()).equals("user")){%>
	        	<a href="../userProfile/userProfileView.jsp">
	       	<%}
	       	//En caso de estar loggeado como empresa
	       	else if((session.getAttribute("CustomerType").toString()).equals("business")){%>
	        	<a href="../businessProfile/businessProfileView.jsp">		
	       	<%}
	           %>
		            <img
		                src="/ScienLink/img/usuario.png"
		                alt="Imagen no cargada"
		                height="90"
		                width="90"
		            />
	    		</a>
        </div>
        <div>
        	<%
        	//En caso de estar loggeado como usuario
        	if((session.getAttribute("CustomerType").toString()).equals("user")){%>
                <button class="button-header">
                	<a class="ancla-sinlink" href="../userProfile/userProfileView.jsp"> Perfil </a>
            	</button>
        	<%}
        	//En caso de estar loggeado como empresa
        	else if((session.getAttribute("CustomerType").toString()).equals("business")){%>
                <button class="button-header">
                	<a class="ancla-sinlink" href="../businessProfile/businessProfileView.jsp"> Perfil </a>
           		</button>        		
        	<%}
            %>
            <form action="<%= request.getContextPath() %>/logoutController" method="get">
	           <button class="button-header">
	               <a class="ancla-sinlink" id="logoutButton" type="submit"> Cerrar sesión </a>
	           </button>
            </form>
        </div>
    </div>
</header>
