package controller;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.swing.JOptionPane;

import database.BusinessDAO;
import model.Business;

@WebServlet("/businessRegisterController")
public class BusinessRegisterController extends HttpServlet {
	private static final long serialVersionUID = 1L;
		
	private void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

			//Comprobamos si el usuario ya existe
			java.util.Hashtable<String, String> resul = BusinessDAO.queryByCif(request.getParameter("cif"));
			if (resul==null) {
				//No existe, asi que lo creo
				Business auxBusiness = new Business();
								
				auxBusiness.setMail(request.getParameter("mail"));
				auxBusiness.setPassword(request.getParameter("password"));
				auxBusiness.setCif(request.getParameter("cif"));
				auxBusiness.setName(request.getParameter("name"));
				
				try {
					BusinessDAO.save(auxBusiness);
				} catch (Exception e) {
		            e.printStackTrace();
		        }

				//Se informa al usuario y se reenvia al login
				JOptionPane.showMessageDialog(null, "Su cuenta ha sido creada con éxito", "Cuenta creada", JOptionPane.INFORMATION_MESSAGE);
				response.sendRedirect("/ScienLink");
				
			}
			else {
				//Muestra mensaje de error
		        JOptionPane.showMessageDialog(null, "Ya existe una cuenta registrada con este CIF", "Error: CIF ya registrado", JOptionPane.INFORMATION_MESSAGE);
		        response.sendRedirect("/ScienLink/view/businessRegister/businessRegisterView.jsp");
			}
			
		}
	
 
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
	 
			processRequest(request, response);
	    }
}
