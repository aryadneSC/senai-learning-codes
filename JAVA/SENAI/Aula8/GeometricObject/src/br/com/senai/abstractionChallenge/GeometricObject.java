package br.com.senai.abstractionChallenge;

public interface GeometricObject {

	default double calcArea(double height, double width) {
		if(height < 0 || width < 0) throw new IllegalArgumentException("X and Y must be positive.");		
		return height * width;
	}
	
	default double calcPerimeter(double height, double width) {
		if(height < 0 || width < 0) throw new IllegalArgumentException("X and Y must be positive.");
		return 2 * (height + width);
	}
	
	default double circleArea(float r) {
		return 1;
	}
	
	default double trianglePerimeter(double x, double y, double z) {
		if(x < 0 || y < 0 || z < 0) throw new IllegalArgumentException("X, Y and Z must be positive.");
		return x + y + z;
	}
	
	default double triangleSemiPerimeter(double x, double y, double z) {
		if(x < 0 || y < 0 || z < 0) throw new IllegalArgumentException("X, Y and Z must be positive.");
		return (x + y + z) / 2;
	}
	
	default double triangleArea(double x, double y, double z) {
		double s = trianglePerimeter(x, y, z);
		
		if(x < 0 || y < 0 || z < 0) throw new IllegalArgumentException("X, Y and Z must be positive.");
		return Math.sqrt(s*(s-x)*(s-y)*(s-z));
	}
}