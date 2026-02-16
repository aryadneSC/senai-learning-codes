package exercicio02;

import java.util.Scanner;

public class Quadrado {
	public int lado;
	
	int getLado() {
		return lado;
	}
	
	public void setLado(int lado) {
		this.lado = lado;
	}
	
	int calcularArea() {
		return lado * lado;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		Quadrado quadrado = new Quadrado();
		
		System.out.println("Valor:");
		int v = sc.nextInt();
		
		quadrado.setLado(v);

		System.out.println("Area do quadrado: " + quadrado.calcularArea());
		
		sc.close();
		
	}

}