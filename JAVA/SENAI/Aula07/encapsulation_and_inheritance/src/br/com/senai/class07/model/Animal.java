package br.com.senai.class07.model;

import java.util.List;
import java.util.ArrayList;

public class Animal {
	private String name;
	private List<Specie> race = new ArrayList<>();
	private boolean isAlive = true;
	
	public Animal (String name, Specie race, boolean isAlive) {
		setName (name);
		setRace (race);
		setIsAlive (isAlive);
	}
}