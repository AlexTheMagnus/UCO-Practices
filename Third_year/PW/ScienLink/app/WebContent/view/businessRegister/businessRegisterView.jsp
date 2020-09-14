<%@ page language="java" contentType="text/html; charset=UTF-8"%> <%@ page
import="java.text.*,java.util.*" %>
<html>
    <head>
        <link rel="stylesheet" type="text/css" href="../../css/global.css" />
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <script
            type="application/javascript"
            src="../../js/functions.js"
        ></script>
        <title>Crear usuario empresa</title>
    </head>
    <body>
        <div class="tittlediv">
            <img
                class="img-inicio"
                src="../../img/ScienLink.png"
                alt="Imagen no cargada"
            />
        </div>
        <div class="rectangle">
            <form
                action="<%= request.getContextPath() %>/businessRegisterController"
                id="businessRegister"
                method="post"
                onsubmit="return(validateEqualPassword());"
            >
                <input
                    required
                    name="mail"
                    type="email"
                    placeholder="Correo de empresa"
                /><br />
                <input
                    required
                    name="name"
                    type="text"
                    placeholder="Nombre de la empresa"
                /><br />
                <input
                    required
                    name="cif"
                    type="text"
                    placeholder="CIF"
                /><br />
                <div>
                    <input
                        required
                        name="password"
                        type="password"
                        placeholder="Contraseña"
                        id="password"
                    />
                    <img
                        class="visiblePassword"
                        type="image"
                        src="../../img/eye.png"
                        onclick="showPassword()"
                    /><br />
                </div>
                <div>
                    <input
                        required
                        name="repetPassword"
                        type="password"
                        placeholder="Repetir contraseña"
                        id="repetPassword"
                    />
                    <img
                        class="visiblePassword"
                        type="image"
                        src="../../img/eye.png"
                        onclick="repetShowPassword()"
                    /><br />
                </div>
                <a style="color: #99a3a4" href="/ScienLink"
                    >¿Ya tienes cuenta? Inicia sesión</a
                ><br />
                <button class="button-slider" style="margin-top: 8px" id="registerButton" type="submit">
                    <span>Registrarse</span></button
                ><br />
            </form>
        </div>
    </body>
</html>
