package database;

import java.sql.*;
import java.util.Hashtable;

import model.User;

public class UserDAO {
  public static Connection getConnection(){
	// Se crea una instancia del conector
	Connection connection=null;
	try {
	  Class.forName("com.mysql.jdbc.Driver");
	  // Se crea la conexion
	  connection= DriverManager.getConnection("jdbc:mysql://oraclepr.uco.es:3306/i72lulem","i72lulem","p3pw");
	// Se capturaran las excepciones 
	} catch(Exception e) {
	  System.out.println(e);
	}
	return connection;
  }
  
  // Método para insertar una fila
	  public static int save(User auxUser) {
		int status=0;
		try{
			Connection connection=getConnection();
	
			PreparedStatement prepStatement=connection.prepareStatement("INSERT INTO USERS (mail,password,last,first,birth_date) values(?,?,?,?,?)");
			// El orden de los parámetros debe coincidir con las '?' del código SQL
			prepStatement.setString(1,auxUser.getMail());
			prepStatement.setString(2,auxUser.getPassword());
			prepStatement.setString(3,auxUser.getLast());
			prepStatement.setString(4,auxUser.getFirst());
			prepStatement.setString(5,auxUser.getBirth_date());
			status = prepStatement.executeUpdate();
		// Se capturan las excepciones
		} catch(Exception e){System.out.println(e);}
		//Se devuelve el estado de la sentencia ejecutada
		return status;
	  }
	  
	  // Método para actualizar un usuario
	  public static int update(User auxUser) {
		int status=0;
		try{
			Connection connection=getConnection();
			PreparedStatement prepStatement=connection.prepareStatement("update USERS set last=?, first=?, affiliation=?, job=?, interests=?, background=?  where mail=?");
			prepStatement.setString(1,auxUser.getLast());
			prepStatement.setString(2,auxUser.getFirst());
			prepStatement.setString(3,auxUser.getAffiliation());
			prepStatement.setString(4,auxUser.getJob());
			prepStatement.setString(5,auxUser.getInterests());
			prepStatement.setString(6,auxUser.getBackground());
	
			// En este caso, 'id' va después, conforme al orden de la sentencia SQL
			prepStatement.setString(7,auxUser.getMail());
			status = prepStatement.executeUpdate();

		}catch(Exception e){System.out.println(e);}
		return status;
	}

	// Para la consulta, se ha tomado una estructura Hash (columna-tabla, valor)
	public static Hashtable<String,String> queryByMail (String mail) {
		Statement stmt = null; 
		Hashtable<String,String> resul = null;
		try {
			Connection connection=getConnection();
			// En consultas, se hace uso de un Statement 
			stmt = connection.createStatement();
		    ResultSet rs = stmt.executeQuery("select password, last, first, birth_date, affiliation, job, picture, interests, background from USERS where mail =  " + "\"" + mail + "\"");
		    while (rs.next()) {
		    	String password = rs.getString("password");
		    	String last = rs.getString("last");
		        String first = rs.getString("first");
		        String birth_date = rs.getString("birth_date");
		        String affiliation = rs.getString("affiliation");
		        String job = rs.getString("job");
		        String picture = rs.getString("picture");
		        String interests = rs.getString("interests");
		        String background = rs.getString("background");
	
		        
		        resul = new Hashtable<String,String>();
		        resul.put("password", password);
		        resul.put("mail", mail);
		        resul.put("last", last);
		        resul.put("first", first);
		        resul.put("birth_date", birth_date.toString());
		        resul.put("affiliation", affiliation);
		        resul.put("job", job);
		        resul.put("picture", picture);
		        resul.put("interests", interests);
		        resul.put("background", background);
	
		    }
		    // Se debe tener precaución con cerrar las conexiones, uso de auto-commit, etc.
		    if (stmt != null) 
		    	stmt.close(); 
		} catch (Exception e) {
			System.out.println(e);
		} 
		return resul;
	} 
	
	public static int delete(String mail){
		int status=0;
		try{
			Connection connection=getConnection();
			PreparedStatement prepStatement=connection.prepareStatement("delete from USERS where mail=?");
			prepStatement.setString(1,mail);
			status=prepStatement.executeUpdate();
		}catch(Exception e){System.out.println(e);}
	
		return status;
	}
}
