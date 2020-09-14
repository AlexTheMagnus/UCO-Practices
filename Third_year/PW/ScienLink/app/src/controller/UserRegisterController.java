package controller;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.swing.JOptionPane;

import database.UserDAO;
import model.User;

@WebServlet("/userRegisterController")
public class UserRegisterController extends HttpServlet {
	private static final long serialVersionUID = 1L;
		
	private void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

			//Comprobamos si el usuario ya existe
			java.util.Hashtable<String, String> resul = UserDAO.queryByMail(request.getParameter("mail"));
			if (resul==null) {
				//No existe, asi que lo creo
				User auxUser = new User();

				auxUser.setMail(request.getParameter("mail"));
				auxUser.setPassword(request.getParameter("password"));
				auxUser.setFirst(request.getParameter("first"));
				auxUser.setLast(request.getParameter("last"));
				auxUser.setBirth_date(request.getParameter("birth_date"));

				try {
					UserDAO.save(auxUser);
				} catch (Exception e) {
		            e.printStackTrace();
		        }

				//Se informa al usuario y se reenvia al login
				JOptionPane.showMessageDialog(null, "Su cuenta ha sido creada con éxito", "Cuenta creada", JOptionPane.INFORMATION_MESSAGE);		
				response.sendRedirect("/ScienLink");
				
			}
			else {
				//Muestra mensaje de error
		        JOptionPane.showMessageDialog(null, "Ya existe una cuenta registrada con este correo", "Error: Correo ya registrado", JOptionPane.INFORMATION_MESSAGE);
		        response.sendRedirect("/ScienLink/view/userRegister/userRegisterView.jsp");
			}
			
		}
	
 
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
			processRequest(request, response);
	}
}
