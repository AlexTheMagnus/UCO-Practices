package database;

import java.sql.*;
import java.util.Hashtable;

import model.Business;

public class BusinessDAO {
	public static Connection getConnection(){
		// Se crea el conector
		Connection connection=null;
		try {
		  Class.forName("com.mysql.jdbc.Driver");
		  // Se incia la conexion
		  connection= DriverManager.getConnection("jdbc:mysql://oraclepr.uco.es:3306/i72lulem","i72lulem","p3pw");
		// Se capturar el error en caso de haberlo
		} catch(Exception e) {
		  System.out.println(e);
		}
		return connection;
	  }
	
	// Método para insertar una fila
	  public static int save(Business auxBusiness) {
		int status=0;
		try{
			Connection connection=getConnection();

			PreparedStatement prepStatement=connection.prepareStatement("INSERT INTO BUSINESSES (mail,password,name,cif) values(?,?,?,?)");
			// El orden de los parámetros debe coincidir con las '?' del código SQL
			prepStatement.setString(1,auxBusiness.getMail());
			prepStatement.setString(2,auxBusiness.getPassword());
			prepStatement.setString(3,auxBusiness.getName());
			prepStatement.setString(4,auxBusiness.getCif());
			status = prepStatement.executeUpdate();
		// Se capturan las excepciones
		}catch(Exception e){System.out.println(e);}
		//Se devuelve el estado de la sentencia ejecutada
		return status;
	}
	  
	// Método para actualizar un usuario
	  public static int update(Business auxBusiness) {
	  	int status=0;
	  	try{
	  		Connection connection=getConnection();
	  		PreparedStatement prepStatement=connection.prepareStatement("update BUSINESSES set name=?, mail=?, password=?, short_description=?, website=?, description=?, searching=?, offering=?, job_offer=? where cif=?");
	  		prepStatement.setString(1,auxBusiness.getName());
	  		prepStatement.setString(2,auxBusiness.getMail());
	  		prepStatement.setString(3,auxBusiness.getPassword());
	  		prepStatement.setString(4,auxBusiness.getShort_description());
	  		prepStatement.setString(5,auxBusiness.getWebsite());
	  		prepStatement.setString(6,auxBusiness.getDescription());
	  		prepStatement.setString(7,auxBusiness.getSearching());
	  		prepStatement.setString(8,auxBusiness.getOffering());
	  		prepStatement.setString(9,auxBusiness.getJob_offer());
	  		
	  		// En este caso, 'id' va después, conforme al orden de la sentencia SQL
	  		prepStatement.setString(10,auxBusiness.getCif());
	  		status=prepStatement.executeUpdate();
	  		
	  	}catch(Exception e){System.out.println(e);}
	  	return status;
	  }

	// Para la consulta, se ha tomado una estructura Hash (columna-tabla, valor)
	  public static Hashtable<String,String> queryByCif (String cif) {
	  	Statement stmt = null; 
	  	Hashtable<String,String> resul = null;
	  	try {
	  		Connection connection=getConnection();
	  		// En consultas, se hace uso de un Statement 
	  		stmt = connection.createStatement();
	  	    ResultSet rs = stmt.executeQuery("select password, name, mail, short_description, website, description, searching, offering, job_offer from BUSINESSES where cif =  " + "\"" + cif + "\"");
	  	    while (rs.next()) {
	  	    	String name = rs.getString("name");
	  	    	String mail = rs.getString("mail");
	  	        String password = rs.getString("password");
	  	        String short_description = rs.getString("short_description");
	  	        String website = rs.getString("website");
	  	        String description = rs.getString("description");
	  	        String searching = rs.getString("searching");
	  	        String offering = rs.getString("offering");
	  	        String job_offer = rs.getString("job_offer");

	  	        
	  	        resul = new Hashtable<String,String>();
	  	        resul.put("name", name);
	  	        resul.put("mail", mail);
	  	        resul.put("password", password);
	  	        resul.put("short_description", short_description);
	  	        resul.put("website", website);
	  	        resul.put("description", description);
	  	        resul.put("searching", searching);
	  	        resul.put("offering", offering);
	  	        resul.put("job_offer", job_offer);	 
	  	        resul.put("cif", cif);	  	        
	  	    }
	  	    // Se debe tener precaución con cerrar las conexiones, uso de auto-commit, etc.
	  	    if (stmt != null) 
	  	    	stmt.close(); 
	  	} catch (Exception e) {
	  		System.out.println(e);
	  	} 
	  	return resul;
	  } 
	  
	public static int delete(String cif){
		int status=0;
		try{
			Connection connection=getConnection();
			PreparedStatement prepStatement=connection.prepareStatement("delete from BUSINESSES where cif=?");
			prepStatement.setString(1,cif);
			status=prepStatement.executeUpdate();
		}catch(Exception e){System.out.println(e);}
	
		return status;
	}
}
