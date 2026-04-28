package br.com.senai.aryadne.class08;

import java.math.*;

public class Main {

	public static void main(String[] args) {
		BigDecimal value = new BigDecimal("10.00");
		value.setScale(2);
		
		Rectangle rectangle = new Rectangle(10,4);
		Circle circle = new Circle(15);
		Triangle triangle = new Triangle(10, 6, 4);
		
		GeometricObject[] geometricObject = {rectangle};
		
		for(GeometricObject r : geometricObject) {
			System.out.println("Rectangle Area: " + r.calcArea(10,4));
			System.out.println("Rectangle Perimeter: " + r.calcArea(10,4));
		}
		
		System.out.println();
		
		for(GeometricObject c : geometricObject) {
			System.out.println("Circle Area: " + c.circleArea(15));
			System.out.println("Circle Perimeter: " + c.circlePerimeter(15));
		}
		
		System.out.println();
		
		for(GeometricObject t : geometricObject) {
			System.out.println("Triangle Area: " + t.triangleArea(10, 6, 4));
			System.out.println("Triangle Semiperimeter: " + t.triangleSemiPerimeter(10, 6, 4));
			System.out.println("Triangle Perimeter: " + t.trianglePerimeter(10, 6, 4));
		}
	}
}