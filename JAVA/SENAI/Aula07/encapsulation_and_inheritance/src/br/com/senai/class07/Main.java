package br.com.senai.class07;

import br.com.senai.class07.model.Vehicle;
import br.com.senai.class07.model.Animal;
import br.com.senai.class07.model.Cat;
import br.com.senai.class07.model.Dog;

public class Main {

	public static void main(String[] args) {	
	
		Dog dog = new Dog("Coulomb", "Labrator");
		Cat cat = new Cat("Mimi", "Calico");
		
		dog.displayAnimalInfo();
		dog.eat();
		dog.walk();
		
		System.out.println();
		
		cat.displayAnimalInfo();
		cat.eat();
		cat.walk();
	}
}