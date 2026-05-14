package br.com.senai.aryadne.class10.activity05;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Ocorrencias {
	// Indagação: como posso mapear a relação Strings e contagem das palavras

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Digite uma frase: ");
		String frase = sc.nextLine().toLowerCase();
		
		String[] palavras = frase.split(" ");
		
		// Resposta: instanciar Map com generics p poder somar
		// String, Integer p trabalhar com expressão matemática e evitar casting
		Map <String, Integer> ocorrencias = new HashMap<>();
		
		for (String palavra : palavras) {
			if (ocorrencias.containsKey(palavra)) {
				// se existir, o valor atual é incrementado
				ocorrencias.put(palavra, ocorrencias.get(palavra) + 1);
			} else {
				// se não, começa com 1
				ocorrencias.put(palavra, 1);
			}
		}
		
		System.out.println("!-Ocorrências por palavra-!");
		for (Map.Entry<String, Integer>entry : ocorrencias.entrySet()) {
			System.out.println(entry.getKey() + ": " + entry.getValue());
		}
		sc.close();

	}
}