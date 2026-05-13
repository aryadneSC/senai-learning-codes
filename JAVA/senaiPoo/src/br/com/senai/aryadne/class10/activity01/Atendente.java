package br.com.senai.aryadne.class10.activity01;

import java.util.ArrayList;
import java.util.List;

public class Atendente {

	public static void main(String[] args) {
		Senha atendimento = new Senha();
		
		atendimento.gerarSenhaNormal("Paula");
		atendimento.gerarSenhaNormal("Marcos");
		atendimento.gerarSenhaPrioritaria("Luisa");
		atendimento.gerarSenhaPrioritaria("Claudinei");
		atendimento.gerarSenhaPrioritaria("Josefa");
		atendimento.gerarSenhaPrioritaria("Mário");
		atendimento.gerarSenhaPrioritaria("Josefina");
		atendimento.gerarSenhaPrioritaria("Cleude");
		
		for(int i = 0; i < 8; i++) {
		System.out.println(atendimento.atender());
		}
	}
}
