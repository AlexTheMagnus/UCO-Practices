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

@WebServlet("/businessLoginController")
public class BusinessLoginController extends HttpServlet {
	private static final long serialVersionUID = 1L;
		
	private void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		{
			//Comprobamos si el usuario ya existe
			java.util.Hashtable<String, String> resul = BusinessDAO.queryByCif(request.getParameter("cif"));
			if (resul==null) {
				//No existe el usuario introducido
				
				//Imprime un mensaje error en el html
		        JOptionPane.showMessageDialog(null, "No existe ninguna empresa registrada con el CIF introducido", "Error: CIF incorrecto", JOptionPane.INFORMATION_MESSAGE);
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
					Business businessBean = new Business();
			        businessBean.setMail(resul.get("mail"));
			        businessBean.setPassword(resul.get("password"));
			        businessBean.setName(resul.get("name"));
			        businessBean.setCif(resul.get("cif"));
			        businessBean.setDescription(resul.get("description"));
			        businessBean.setJob_offer(resul.get("offer"));
			        businessBean.setOffering(resul.get("offering"));
			        businessBean.setSearching(resul.get("searching"));
			        businessBean.setShort_description(resul.get("short_description"));
			        businessBean.setWebsite(resul.get("website"));
			        
			 
			        // Almacena el BusinessBean con la informacion del usuario en la session
			        request.getSession().setAttribute("BusinessBean", businessBean);
			        request.getSession().setAttribute("logged", true);
			        request.getSession().setAttribute("CustomerType", "business");
			        
			        System.out.print(businessBean.getMail());
			        System.out.print(businessBean.getName());
			        System.out.print(businessBean.getShort_description());
			        System.out.print(businessBean.getPassword());
			        System.out.print(businessBean.getWebsite());
			        
			        //Redirige a la pagina principal
					response.sendRedirect("./view/businessMain/businessMainView.jsp");
				}
				
			}}
			
		}
	
 
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
	 
			processRequest(request, response);
	    }
}