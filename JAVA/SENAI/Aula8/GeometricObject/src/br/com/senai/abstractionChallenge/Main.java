package br.com.senai.abstractionChallenge;

public class Main {

	public static void main(String[] args) {
		
		Rectangle rectangle = new Rectangle(10,4);
		
		GeometricObject[] geometricObject = {rectangle};
		
		for(GeometricObject geometricObjects : geometricObject) {
			System.out.println("Rectangle Area: " + geometricObjects.calcArea(10,4));
			System.out.println("Rectangle Perimeter: " + geometricObjects.calcArea(10,4));
		}
		
	}
}