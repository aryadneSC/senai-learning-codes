package br.com.senai.aryadne.class07.model;

public class Motocycle extends Vehicle {
	private int cylinderCapacity;
	
	public Motocycle (String brand, String model, int cylinderCapacity) {
		super(brand, model);
		setCC(cylinderCapacity);
		isOn = false;
	}
	
	public void setCC(int cylinderCapacity) {
		if (cylinderCapacity <= 0)
	        throw new IllegalArgumentException("Invalid.");
	    this.cylinderCapacity = cylinderCapacity;
	}
	
	public int getCC() {
		return cylinderCapacity;
		
	}
}
