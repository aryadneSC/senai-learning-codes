package br.com.senai.class07;

import br.com.senai.class07.model.Vehicle;
import br.com.senai.class07.model.Animal;
import br.com.senai.class07.model.Cat;
import br.com.senai.class07.model.Dog;
import br.com.senai.class07.model.Car;
import br.com.senai.class07.model.Motocycle;

public class Main {

	public static void main(String[] args) {	
	
		Car car = new Car("Honda", "Civic", 5);
		Motocycle moto = new Motocycle("Yamaha", "YZF-R1", 1000);
		
		car.displayVehicleInfo();
		System.out.println("Doors: " + car.getDoors());
		car.isOn();
		
		System.out.println();
		
		moto.displayVehicleInfo();
		System.out.println("Cylinder capacity: " + moto.getCC() + " cc");
		moto.isOn();
	}
}