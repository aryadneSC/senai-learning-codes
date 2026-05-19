/*4- SET: Faça um programa que leia uma frase 
 * e informe o número de palavras não repetidas da frase.*/
package br.com.senai.aryadne.class10.activity04;

import java.util.HashSet;
import java.util.Set;

public class PalavraUnica {
	
	public static int contarPalavras(String s) {
		String[] palavras = s.split(" ");
		Set<String> naoRepetida = new HashSet<String>();
		
		for (String p : palavras) {
			naoRepetida.add(p);
		}
		return naoRepetida.size();
	}

	public static void main(String[] args) {
		String frase = "O carro para para estacionar";
		PalavraUnica p = new PalavraUnica();
		
		System.out.println("'" + frase + "'" + " | Palavras não repetidas: ["
				+ p.contarPalavras(frase) + "]");
	}
}