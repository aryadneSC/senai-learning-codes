package br.com.senai.aryadne.class08.model;

public class Rectangle implements GeometricObject {
	private double height, width;
	
	public Rectangle(double height, double width) {
		setHeight(height);
		setWidth(width);
	}
	
	public void setHeight(double height) {
		this.height = height;
	}
	
	public void setWidth(double width) {
		this.width = width;
	}

	@Override
	public double calcArea(double height, double width) {
		if(height < 0 || width < 0) 
			throw new IllegalArgumentException("X and Y must be positive.");
		return height * width;
	}
	
	@Override
	public double calcPerimeter(double height, double width) {
		if(height < 0 || width < 0) 
			throw new IllegalArgumentException("X and Y must be positive.");
		return 2 * (height + width);
	}
}