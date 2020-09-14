<%@ page language="java" contentType="text/html; charset=UTF-8"%> <%@ page
import="java.text.*,java.util.*" %>
<html>
<head>
    <link rel="stylesheet" type="text/css" href="./css/global.css">
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Inicio sesion</title>
</head>
<body>
    <div class="tittlediv">
        <img class="img-inicio" src="./img/ScienLink.png" alt="Imagen no cargada">
    </div>
    <div class="square">    <!--Inicio sesión usuario-->
        <span class="squared-text">Usuarios</span>
        <form action="<%= request.getContextPath() %>/userLoginController" method="post" style="clear:left" id="inicioSesionUsuario">
            <label class="basictext" for="mail"/>
            <input name="mail" required type="email" placeholder="Correo electrónico"><br>
            <label class="basictext" for="password"/>
            <input name="password" required form="inicioSesionUsuario" type="password" placeholder="Contraseña"><br>
            <button class="button-slider" id="userLoginButton" type="submit">
                <span>Iniciar sesión</span>
            </button><br>
            <a style="color: #99a3a4" href="./view/userRegister/userRegisterView.jsp">¿No tienes cuenta? Registrate</a>
        </form>
    </div>
    <div class="square">    <!--Inicio sesión empresas-->
        <span class="squared-text">Empresas</span>
        <form action="<%= request.getContextPath() %>/businessLoginController"  method="post" style="clear:left" id="inicioSesionEmpresa">
            <label class="basictext" for="username"/>
            <input name="cif" required type="text" placeholder="CIF"><br>
            <label class="basictext" for="password"/>
            <input name="password" required type="password" placeholder="Contraseña"><br>
            <button class="button-slider" id="businessLoginButton" type="submit">
                <span>Iniciar sesión</span>
            </button><br>
            <a style="color: #99a3a4" href="./view/businessRegister/businessRegisterView.jsp">¿No tienes cuenta? Registrate</a>
        </form>

    </div>
</body>
