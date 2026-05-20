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
		if (pessoa <= 0) {
		System.out.println("Elevador vazio!");
		return;
		}
		pessoa--;
		System.out.println("Uma pessoa saiu!");
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
		
		// teste 1: Adicione o máximo de pessoas no elevador 
		// 			e depois tente adicionar mais uma
		System.out.println("Pessoas dentro do elevador: " + e.getPessoa());
		e.entrar();
		e.entrar();
		System.out.println("Pessoas dentro do elevador: " + e.getPessoa());
		e.entrar(); // Capacidade máxima
		System.out.println(); 
		
		// teste 2: Suba até o último andar e depois tente subir mais um andar
		System.out.println("Andar atual: " + e.getTerreo());
		e.subir();
		e.subir();
		System.out.println("Andar atual: " + e.getTerreo()); // último andar
		e.subir(); // último andar
		System.out.println();
		
		// teste 3: Desça até o térreo e depois tente descer mais um andar
		System.out.println("Andar atual: " + e.getTerreo());
		e.descer();
		e.descer();
		System.out.println("Andar atual: " + e.getTerreo()); // térreo
		e.descer(); // térreo
		System.out.println();
		
		// teste 4: Removas todas as pessoas do elevador 
		// 			e depois tente remover mais uma
		System.out.println("Pessoas dentro do elevador: " + e.getPessoa());
		e.sair();
		e.sair();
		e.sair(); // elevador vazio
		System.out.println("Pessoas dentro do elevador: " + e.getPessoa());
	}

}
