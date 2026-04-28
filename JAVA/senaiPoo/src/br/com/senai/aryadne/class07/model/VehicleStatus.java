package br.com.senai.aryadne.class07.model;

public class VehicleStatus {
	protected boolean isOn;
	
	public boolean isOn () {
		if (isOn == false) 
			System.out.println ("is parked.");
		else 
			System.out.println ("is ready to go");
		return isOn;
	}

}
