package exercicio03;

import java.util.Scanner;

import exercicio02.Quadrado;

public class Retangulo {
	public int base;
	public int altura;
	
	int getBase() {
		return base;
	}
	
	public void setBase(int base) {
		this.base = base;
	}
	
	int getAltura() {
		return altura;
	}
	
	public void setAltura(int altura) {
		this.altura = altura;
	}
	
	int calcularArea() {
		return base * altura;
	}
	
	int calcularPerimetro() {
		return base + altura;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		Retangulo retangulo = new Retangulo();
		
		System.out.println("Base do retângulo:");
		int base = sc.nextInt();
		retangulo.setBase(base);
		
		System.out.println("ALtura do retângulo:");
		int altura = sc.nextInt();
		retangulo.setAltura(altura);
		
		System.out.println("Area = " + retangulo.calcularArea() +
					" Perimetro = " + retangulo.calcularPerimetro()
					);
		
		
		
	}

}
