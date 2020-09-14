package controller;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.swing.JOptionPane;

import database.BusinessDAO;
import database.UserDAO;
import model.Business;
import model.User;

@WebServlet("/deleteAccountController")
public class DeleteAccount  extends HttpServlet {
	private static final long serialVersionUID = 1L;
	
private void logout(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		//Cierra la sesion
		request.getSession().setAttribute("logged", false);

		if(request.getSession().getAttribute("CustomerType").toString().equals("user")) {
			request.getSession().setAttribute("CustomerBean", null);
		}
		
		else if(request.getSession().getAttribute("CustomerType").toString().equals("business")) {
			request.getSession().setAttribute("BusinessBean", null);
		}
		
		else {
			//Este caso no deberia ocurrir
			System.out.print("Error con el tipo de sesion");
		}
		
		request.getSession().setAttribute("CustomerType", null);
	}
	
	private void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		//Se guarda el id de la cuenta
		String accountType = request.getSession().getAttribute("CustomerType").toString();
		String accountId = "";
		
		if(accountType.equals("user")) {
			User userBean = (User) request.getSession().getAttribute("CustomerBean");
			accountId = userBean.getMail().toString();			
		}
		else if(accountType.equals("business")){
			Business businessBean = (Business) request.getSession().getAttribute("BusinessBean");
			accountId = businessBean.getCif();
		}
		
		else {
			//Este caso no deberia ocurrir
			System.out.print("Error con el tipo de sesion");
		}
		
		//Cierra la sesion
		logout(request,response);
		//Comprueba que el usuario existe y lo elimina
		if(accountType.equals("user")) {
			java.util.Hashtable<String, String> resul = UserDAO.queryByMail(accountId);
			if (resul!=null) {
				UserDAO.delete(accountId);
			}
			else {
				System.out.print("El usuario no existe");//
			}
		}
		else if(accountType.equals("business")){
			java.util.Hashtable<String, String> resul = BusinessDAO.queryByCif(accountId);
			if (resul!=null) {
				BusinessDAO.delete(accountId);				
			}
			else {
				System.out.print("El usuario no existe");//
			}
		}

		//Informamos al usuario
        JOptionPane.showMessageDialog(null, "Cuenta eliminada con éxito", ":(", JOptionPane.INFORMATION_MESSAGE);		
		
		//Redirige a la pagina de login
		response.sendRedirect("/ScienLink");
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		processRequest(request, response);
	}
}
