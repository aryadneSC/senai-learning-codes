package br.com.senai.aryadne.class07.model;

public class Cat extends Animal {

	public Cat(String name, String race) {
		super(name, race);
		isAlive = true;
	}
	
	public void speak() {
		System.out.println("The cat goes *meow*");
		System.out.println();
	}
}
