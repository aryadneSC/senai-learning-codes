package br.com.senai.aryadne.class07.model;

public class Car extends Vehicle {
	private int doors;
	
	public Car (String brand, String model, int doors) {
		super(brand, model);
		setDoors(doors);
		isOn = true;
	}
	
	public void setDoors(int doors) {
	    if (doors <= 0)
	        throw new IllegalArgumentException("Invalid.");
	    this.doors = doors;
	}
	
	public int getDoors() {
		return doors;
	}
}