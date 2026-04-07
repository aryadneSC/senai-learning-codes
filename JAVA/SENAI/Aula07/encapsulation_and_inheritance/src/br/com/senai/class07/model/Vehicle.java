package br.com.senai.class07.model;

public class Vehicle {
	private String brand;
	private String model;
	private boolean isOn;
	
	public Vehicle (String brand, String model) {
		setBrand (brand);
		setModel (model);
		this.isOn = true;
	}
	
	public void setBrand (String brand) {
		if (brand == null || brand.trim().isEmpty())
			throw new IllegalArgumentException ("Please inform a valid argument.");
		this.brand = brand;
	}
	
	public void setModel (String model) {
		if (model == null || model.trim().isEmpty())
			throw new IllegalArgumentException ("Please inform a valid argument.");
		this.model = model;
	}
	
	public boolean isOn () {
		if (isOn == false) 
			System.out.println ("is parked.");
		else 
			System.out.println ("is ready to go");
		return isOn;
	}
	
	public void displayVehicleInfo() {
		System.out.println("Brand: " + brand);
		System.out.println("Model: " + model);
		isOn();
	}
}
