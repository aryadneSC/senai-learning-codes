/*
 * 1- FILA: Escreva um programa que simule a distribuição de senhas 
 * de atendimento a um grupo de pessoas. 
Cada pessoa pode receber uma senha prioritária ou uma senha normal.
Existe apenas 1 atendente, 
1 pessoa com senha normal deve ser atendida a cada 3
pessoas com senha prioritária. 
Classes: Atendente(main) e Senha.
 * */

package br.com.senai.aryadne.class10.activity01;

import java.util.List;
import java.util.LinkedList;

public class Senha {
	Integer fila = 0;
	
	LinkedList<String> normal = new LinkedList<>();
	LinkedList<String> prioritaria = new LinkedList<>();
	
	public String gerarSenhaNormal(String senha) {
		normal.add(senha);
		return senha;
	}
	
	public String gerarSenhaPrioritaria(String senha) {
		prioritaria.add(senha);
		return senha;
	}
	
	public String atender() {
		LinkedList<String> atendimento;
		String senha;
		
		if(fila.equals(3) || prioritaria.isEmpty()) {
			atendimento = normal;
			fila = 0;
		} else {
			atendimento = prioritaria;
			fila++;
		}
		
		senha = atendimento.removeFirst();
		return senha;
	}
}
