package br.com.senai.class07.model;

public class Animal {
	private String name;
	private String race;
	private boolean isAlive;
	
	public Animal (String name, String race) {
		setName (name);
		setRace (race);
		this.isAlive = true;
	}
	
	public void setName (String name) {
		if (name == null || name.trim().isEmpty())
			throw new IllegalArgumentException ("Name is invalid. Please try again.");
		this.name = name;
	}
	
	public String getName () {
		return name;
	}
	
	public void setRace(String race) {
		if (race == null || race.trim().isEmpty())
			throw new IllegalArgumentException ("Race type is invalid. Please try again.");
		this.race = race;
	}
	
	public String getRace () {
		return race;
	}
	
	public boolean isAlive () {
		if (isAlive == false)
			System.out.println ("is unalived");
		else
			System.out.println ("is alive.");
		return isAlive;
	}
	
	public void walk () {
		System.out.println (getName() + ", the " 
				+ getRace() + ", is walking...");
	}
	
	public void eat () {
		System.out.println (getName() + ", the " 
				+ getRace() + ", is eating ");
	}		
	
	public void displayAnimalInfo () {
		System.out.println("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
		System.out.println ("Name: " + name);
		System.out.println ("Race: " + race);
		isAlive();
		System.out.println("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
	}
}