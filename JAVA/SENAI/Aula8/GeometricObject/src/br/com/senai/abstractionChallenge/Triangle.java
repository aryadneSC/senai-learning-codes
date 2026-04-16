package br.com.senai.abstractionChallenge;

public class Triangle {
private double height, width, base;
	
	public Triangle(float x, double y, double z) {
		setHeight(x);
		setWidth(y);
		setBase(z);
	}
	
	private void setBase(double z) {
		this.base = z;
		
	}

	public void setHeight(double x) {
		this.height = x;
	}
	
	public void setWidth(double y) {
		this.width = y;
	}

	
}
