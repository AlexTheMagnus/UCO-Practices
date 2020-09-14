package model;

import java.io.Serializable;


public class Business implements Serializable{
	
	private static final long serialVersionUID = 1L;

	private String mail;
	private String name;
	private String cif;
	private String password;
	private String short_description;
	private String description;
	private String website;
	private String searching;
	private String offering;
	private String job_offer;
	
	//Constructor
	public Business() {}
	
	//Getters and Setters

	public String getMail() {
		return mail;
	}

	public void setMail(String mail) {
		this.mail = mail;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getCif() {
		return cif;
	}

	public void setCif(String cif) {
		this.cif = cif;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}

	public String getShort_description() {
		return short_description;
	}

	public void setShort_description(String short_description) {
		this.short_description = short_description;
	}

	public String getDescription() {
		return description;
	}

	public void setDescription(String description) {
		this.description = description;
	}

	public String getWebsite() {
		return website;
	}

	public void setWebsite(String website) {
		this.website = website;
	}

	public String getSearching() {
		return searching;
	}

	public void setSearching(String searching) {
		this.searching = searching;
	}

	public String getOffering() {
		return offering;
	}

	public void setOffering(String offering) {
		this.offering = offering;
	}

	public String getJob_offer() {
		return job_offer;
	}

	public void setJob_offer(String job_offer) {
		this.job_offer = job_offer;
	}
	

}
