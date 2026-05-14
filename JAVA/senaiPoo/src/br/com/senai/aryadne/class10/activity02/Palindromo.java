/*
 * 2- PILHA: Crie um programa que recebe uma palavra 
 * e reconhece se ela é ou não um palíndromo.
 * */

package br.com.senai.aryadne.class10.activity02;

import java.util.Scanner;
import java.util.Stack;

public class Palindromo {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Digite uma palavra: ");
		String palavra = sc.nextLine().toLowerCase();
		
		Stack pilha = new Stack<>();
		
		for (char letra : palavra.toCharArray()) {
			pilha.push(letra);
		}
		
		String invertida = "";
		while (!pilha.isEmpty()) {
			invertida += pilha.pop();
		}
		
		if (palavra.equals(invertida)) {
			System.out.println("'" + palavra + "' é um palíndromo");
		} else {
			System.out.println("'" + palavra + "' não é um palíndromo");
		}
		
		sc.close();
		
	}
}