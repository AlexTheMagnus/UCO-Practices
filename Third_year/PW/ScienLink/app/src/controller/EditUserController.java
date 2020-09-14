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

@WebServlet("/editUserController")
public class EditUserController extends HttpServlet {
	private static final long serialVersionUID = 1L;

	private void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		//Se obtiene la cuenta que tiene la sesión iniciada
		User userBean = (User) request.getSession().getAttribute("CustomerBean");
		//Se crea un bean auxiliar con la nueva información
		User auxBean = new User();
		request.setCharacterEncoding("UTF-8");

		if(!request.getParameter("first").equals("")) {
			auxBean.setFirst(request.getParameter("first"));
		}
		else {
			auxBean.setFirst(userBean.getFirst());
		}
		
		if(!request.getParameter("last").equals("")) {
			auxBean.setLast(request.getParameter("last"));
		}
		else {
			auxBean.setLast(userBean.getLast());
		}
		
		if(!request.getParameter("job").equals("")) {
			auxBean.setJob(request.getParameter("job"));
		}
		else {
			auxBean.setJob("Ninguno");
		}
		
		if(!request.getParameter("affiliation").equals("")) {
			auxBean.setAffiliation(request.getParameter("affiliation"));
		}
		else {
			auxBean.setAffiliation("Ninguna");
		}
		
		if(!request.getParameter("background").equals("")) {
			auxBean.setBackground(request.getParameter("background").toString());
		}
		else {
			auxBean.setBackground("Ninguno");
		}
		
		if(!request.getParameter("interests").equals("")) {
			auxBean.setInterests(request.getParameter("interests").toString());
		}
		else {
			auxBean.setInterests("Ninguno");
		}
		auxBean.setMail(userBean.getMail());
		auxBean.setPassword(userBean.getPassword());
		auxBean.setPicture(userBean.getPicture());
		auxBean.setBirth_date(userBean.getBirth_date());
		
		//Se actualiza la cuenta en la BBDD
		int resul = UserDAO.update(auxBean);
		
		//Si la actualización es exitosa
		if (resul != 0) {
			//Se asignan los nuevos valores a CustomerBean y se libera auxBean
	        request.getSession().setAttribute("CustomerBean", auxBean);
			auxBean = null;		
		}
		
		//En caso de error
		else {
			System.out.print("Erro en el sql update");
			JOptionPane.showMessageDialog(null, "Ha habido un error al editar su cuenta", "Error en la edición", JOptionPane.INFORMATION_MESSAGE);
		}
	
		response.sendRedirect("/ScienLink/view/userProfile/userProfileView.jsp");
	}
	
	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		processRequest(request, response);
	}
}
