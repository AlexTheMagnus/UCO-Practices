package model;

import java.io.Serializable;

public class User implements Serializable{
	
	private static final long serialVersionUID = 1L;
	
	private String mail;
	private String password;
	private String first;
	private String last;
	private String birth_date;
	private String affiliation;
	private String job;
	private String picture;
	private String interests;
	private String background;	
	
	//Constructor
	public User() {}
	
	//Getters
	public String getMail() {
		return mail;
	}
	
	public String getPassword() {
		return password;
	}
	
	public String getFirst() {
		return first;
	}
	
	public String getLast() {
		return last;
	}
	
	public String getBirth_date() {
		return birth_date;
	}
	
	public String getAffiliation() {
		return affiliation;
	}
	
	public String getJob() {
		return job;
	}
	
	public String getPicture() {
		return picture;
	}
	
	public String getInterests() {
		return interests;
	}
	
	public String getBackground() {
		return background;
	}
		
	//Setters
	public void setMail(String mail) {
		this.mail = mail;
	}
	
	public void setPassword(String password) {
		this.password = password;
	}
	
	public void setFirst(String first) {
		this.first = first;
	}
	
	public void setLast(String last) {
		this.last = last;
	}
	
	public void setBirth_date(String birth_date) {
		this.birth_date = birth_date;
	}
	
	public void setAffiliation(String affiliation) {
		this.affiliation = affiliation;
	}
	
	public void setJob(String job) {
		this.job = job;
	}
	
	public void setPicture(String picture) {
		this.picture = picture;
	}
	
	public void setInterests(String interests) {
		this.interests = interests;
	}
	
	public void setBackground(String background) {
		this.background = background;
	}	
}



