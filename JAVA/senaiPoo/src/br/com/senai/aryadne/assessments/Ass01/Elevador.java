package br.com.senai.aryadne.assessments.Ass01;

public class Elevador {
	private int andarAtual;
	private int capacidade;
	private int totalAndares;
	private int pessoa;
	
	public Elevador (int capacidade, int totalAndares) {
		setCapacidade(capacidade);
		setTotalAndares(totalAndares);
		this.andarAtual = 0; // começa no térreo
		this.pessoa = 0;
	}
	
	public void setCapacidade (int capacidade) {
		this.capacidade = capacidade;
	}
	
	public void setTotalAndares (int totalAndares) {
		this.totalAndares = totalAndares;
	}
	
	public void setTerreo (int terreo) {
		this.andarAtual = terreo;
	}
	
	public void setPessoa (int qtdPessoas) {
		this.pessoa = qtdPessoas;
	}
	
	public int getCapacidade () {
		return capacidade;
	}
	
	public int getTotalAndares () {
		return totalAndares;
	}
	
	public int getPessoa () {
		return pessoa;
	}
	
	public int getTerreo() {
		return andarAtual;
	}
	
	public void entrar () {
		if (pessoa >= capacidade) {
			System.out.println("Capacidade máx atingida. Elevador fechando...");
			return;
		}
		pessoa++;
	}
	
	public void sair () {
		if (pessoa <= capacidade) {
		System.out.println("Elevador liberado!");
		return;
		}
		pessoa--;
	}
	
	public void subir () {
		if (andarAtual >= totalAndares) {
			System.out.println("Último andar!");
			return;
		}
		andarAtual++;
		System.out.println("Subindo... Andar atual: " + andarAtual);
	}
	
	public void descer () {
		if (andarAtual <= 0) {
			System.out.println("Já está no térreo!");
			return;
		} 
		andarAtual--;
		System.out.println("Descendo... Andar atual: " + andarAtual);
	}
	
	public static void main(String[] args) {
		Elevador e = new Elevador(2, 2);
		
		System.out.println("Pessoas dentro do elevador: " + e.getPessoa());
		System.out.println("Capacidade: " + e.getCapacidade());
		
		e.entrar();
		System.out.println("Pessoas dentro do elevador: " + e.getPessoa());
		
		e.entrar();
		System.out.println("Pessoas dentro do elevador: " + e.getPessoa());
		
		e.entrar(); // Capacidade máxima
		System.out.println(); // pula linha
		
		e.subir();
		System.out.println("Andar atual: " + e.getTerreo());
		e.subir();
		System.out.println("Andar atual: " + e.getTerreo()); // último andar
		
		e.descer();
		System.out.println("Andar atual: " + e.getTerreo());
		e.descer();
		System.out.println("Andar atual: " + e.getTerreo()); // térreo
		
		e.descer();
		System.out.println("Andar atual: " + e.getTerreo()); // já esta no térreo
	}

}
