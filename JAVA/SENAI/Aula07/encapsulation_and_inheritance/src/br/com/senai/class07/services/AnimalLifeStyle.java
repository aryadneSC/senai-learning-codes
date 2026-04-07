package br.com.senai.class07.services;

import br.com.senai.class07.model.Animal;

public class AnimalLifeStyle {
	private Animal animal;
	
	public AnimalLifeStyle(Animal animal) {
		this.animal = animal;
	}
	
	public void walk () {
		System.out.println (animal.getName() + ", the " 
				+ animal.getRace() + " is walking...");
	}
	
	public void eat () {
		System.out.println (animal.getName() + ", the " 
				+ animal.getRace() + " is eating ");
	}		
}