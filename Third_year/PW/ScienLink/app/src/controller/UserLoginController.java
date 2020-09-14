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

@WebServlet("/userLoginController")
public class UserLoginController extends HttpServlet {
	private static final long serialVersionUID = 1L;
		
	private void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
	
		//Comprobamos si el usuario ya existe
		java.util.Hashtable<String, String> resul = UserDAO.queryByMail(request.getParameter("mail"));
		if (resul==null) {
			//No existe el usuario introducido
			
			//Imprime un mensaje error en el html
	        JOptionPane.showMessageDialog(null, "No existe ninguna cuenta registrada con el correo introducido", "Error: Correo incorrecto", JOptionPane.INFORMATION_MESSAGE);
	        //Te manda de nuevo a la pagina de login
	        response.sendRedirect("/ScienLink");

		}
		else {
			String passToCheck = resul.get("password");
			String passIntroduced = request.getParameter("password");
			if(!passToCheck.equals(passIntroduced)) {
				//Contraseña incorrecta
				
				//Imprime mensaje error en el html
		        JOptionPane.showMessageDialog(null, "La contraseña introducida es incorrecta", "Error: Contraseña incorrecta", JOptionPane.INFORMATION_MESSAGE);
		        //Te manda de nuevo a la pagina de login
		        response.sendRedirect("/ScienLink");

			}
			else {
				//Logeo correcto
				User userBean = new User();
		        userBean.setMail(resul.get("mail"));
		        userBean.setPassword(resul.get("password"));
		        userBean.setFirst(resul.get("first"));
		        userBean.setLast(resul.get("last"));
		        userBean.setBirth_date(resul.get("birth_date"));
		        userBean.setAffiliation(resul.get("affiliation"));
		        userBean.setJob(resul.get("job"));
		        userBean.setPicture(resul.get("picures"));
		        userBean.setInterests(resul.get("interests"));
		        userBean.setBackground(resul.get("background"));
		        
		 
		        // Almacena el CustomerBean con la informacion del usuario en la session
		        request.getSession().setAttribute("CustomerBean", userBean);
		        request.getSession().setAttribute("logged", true);
		        request.getSession().setAttribute("CustomerType", "user");

		        //Redirige a la pagina principal
				response.sendRedirect("./view/userMain/userMainView.jsp");
			}
		}		
	}
 
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		processRequest(request, response);
	}
}