package br.com.senai.aryadne.class08.model;

public class Circle implements GeometricObject {
	private double radius;
	
	public Circle (double r) {
		setRadius(r);
	}
	
	public void setRadius(double r) {
		this.radius = r;
	}
	
	@Override
	public double circleArea(double r) {
		return Math.PI * r * r;
	}
	
	@Override
	public double circlePerimeter(double r) {
		return 2 * Math.PI * r;
	}
}