package controller;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/logoutController")
public class LogoutController extends HttpServlet {
	private static final long serialVersionUID = 1L;
	
	private void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		//Cierra la sesion
		request.getSession().setAttribute("logged", false);

		if(request.getSession().getAttribute("CustomerType").toString().equals("user")) {
			request.getSession().setAttribute("CustomerBean", null);
			request.getSession().setAttribute("BusinessBean", null);
		}

		else if(request.getSession().getAttribute("CustomerType").toString().equals("business")) {
			request.getSession().setAttribute("BusinessBean", null);
			request.getSession().setAttribute("CustomerBean", null);
		}

		else {
			//Este caso no deberia ocurrir
			System.out.print("Error con el tipo de sesion");
		}
		request.getSession().setAttribute("CustomerType", null);
		
		//Redirige a la pagina de login
		response.sendRedirect("/ScienLink");		
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		processRequest(request, response);
	}
}