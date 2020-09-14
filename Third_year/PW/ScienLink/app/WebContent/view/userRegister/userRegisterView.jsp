<%@ page language="java" contentType="text/html; charset=UTF-8"%>
<html>
    <head>
        <link rel="stylesheet" type="text/css" href="../../css/global.css" />
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <script
            type="application/javascript"
            src="../../js/functions.js"
        ></script>
        <title>Crear usuario</title>
    </head>
    <body>
        <div class="tittlediv">
            <img class="img-inicio" src="../../img/ScienLink.png" alt="" />
        </div>
        <div class="rectangle">
            <form
            	id="userRegister"
				action="<%= request.getContextPath() %>/userRegisterController"
				method="post"
				onsubmit="return(validateEqualPassword());"
            >
                <input
                    required
                    name="mail"
                    type="email"
                    placeholder="Correo electrónico"
                /><br />
                <input
                    required
                    name="first"
                    type="text"
                    placeholder="Nombre"
                /><br />
                <input
                    required
                    name="last"
                    type="text"
                    placeholder="Apellidos"
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
                        name="repet_password"
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
                <input
                    required
                    name="birth_date"
                    placeholder="Fecha de nacimiento"
                    class="textbox-n"
                    type="text"
                    onmouseover="(this.type='date')"
                    onfocusout="(this.type='text')"
                />
                <br />

                <a style="color: #99a3a4" href="/ScienLink"
                    >¿Ya tienes cuenta? Inicia sesión</a
                ><br />
                <button class="button-slider" style="margin-top: 8px"
                id="registerButton" type="submit"
                >Registrarse</button>
                <br />
            </form>
        </div>
    </body>
</html>
