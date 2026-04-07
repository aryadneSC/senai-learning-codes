package br.com.senai.class07.model;

import java.util.List;
import java.util.ArrayList;

public class Animal {
	private String name;
	private List<Specie> race = new ArrayList<>();
	private boolean isAlive;
	
	public Animal (String name, Specie race, boolean isAlive) {
		setName (name);
		setRace (race);
		isAlive = true;
	}
	
	public void setName (String name) {
		if (name == null || name.trim().isEmpty())
			throw new IllegalArgumentException ("Name is invalid. Please try again.");
		this.name = name;
	}
	
	public void setRace (Specie race) {
		
	}
}