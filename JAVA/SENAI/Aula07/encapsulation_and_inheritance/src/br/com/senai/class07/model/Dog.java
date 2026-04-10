package br.com.senai.class07.model;

public class Dog extends Animal {
	
	public Dog(String name, String race) {
		super(name, race);
		isAlive = true;
	}
	
	public void speak() {
		System.out.println("The dog goes *woof*");
	}
}
