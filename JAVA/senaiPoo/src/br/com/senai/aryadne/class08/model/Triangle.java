package br.com.senai.aryadne.class08.model;

public class Triangle implements GeometricObject{
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

	@Override
	public double trianglePerimeter(double x, double y, double z) {
		if(x < 0 || y < 0 || z < 0) throw new IllegalArgumentException("X, Y and Z must be positive.");
		return x + y + z;
	}
	
	@Override
	public double triangleSemiPerimeter(double x, double y, double z) {
		if(x < 0 || y < 0 || z < 0) throw new IllegalArgumentException("X, Y and Z must be positive.");
		return (x + y + z) / 2;
	}
	
	@Override
	public double triangleArea(double x, double y, double z) {
		double s = trianglePerimeter(x, y, z);
		
		if(x < 0 || y < 0 || z < 0) throw new IllegalArgumentException("X, Y and Z must be positive.");
		return Math.sqrt(s*(s-x)*(s-y)*(s-z));
	}
}
