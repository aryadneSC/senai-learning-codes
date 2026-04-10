package br.com.senai.class07.model;

public class Organism {
	protected boolean isAlive;
	
	public boolean isAlive () {
		if (isAlive == false)
			System.out.println ("is unalived");
		else
			System.out.println ("is alive.");
		return isAlive;
	}
}
