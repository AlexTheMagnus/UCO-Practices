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

<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <meta http-equiv="X-UA-Compatible" content="ie=edge" />
        <title>Editar perfil usuario</title>
        <link rel="stylesheet" href="../../css/global.css" />
    </head>
    <body>
        <%@ include file = "../../include/header.jsp" %>

        <div class="perfil-cambios">
            <!--Editar cambios-->

            <div class="cajas-editar">
            
        		<form
	            	id="editUser"
					action="<%= request.getContextPath() %>/editUserController"
					method="post"
				>
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
		                        <input class="sideBySide" type="text" name="first" value=<%out.print(customerBean.getFirst()); %> /> 
		                        <input class="sideBySide" type="text" name="last" value=<%out.print(customerBean.getLast()); %> />
		                        </br>
		
		                        <div class="form-group">
								    <label style="float:left;" for="job">Trabajo: </label>
								    <input style="float:right;" name="job" id="job" value=<%out.print(customerBean.getJob()); %> />
								</div>
		
		                        <div class="form-group">
								    <label style="float:left;" for="affiliation">Empresa: </label>
								    <input style="float:right;" name="affiliation" id="affiliation" value=<%out.print(customerBean.getAffiliation()); %> />
								</div>
														
		                    	<div class="form-group">
								    <input style="visibility: hidden;" name="none" id="none"/>
								</div>
		                    </div>		                    
		                    
		                </div>
		
		                <div class="parrafo-editar">
		                    <h1>Historial profesional:</h1>
	                    	<textarea name="background" cols="40" rows="10" form="editUser" > <%out.print(customerBean.getBackground());%> </textarea>
		                </div>
		
		                <div class="parrafo-editar">
		                    <h1>Mis intereses:</h1>
							<textarea name="interests" cols="40" rows="10" form="editUser"> <%out.print(customerBean.getInterests());%> </textarea>
		                </div>				

		                <div class="boton-editar">
		                    <center>
		                        <button class="button-pressed-8" id="editUserButton" type="submit">
		                            Guardar cambios
		                        </button>
		                    </center>
		                </div>
               		</form>
                
            </div>

            <div class="menu-editar">
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
