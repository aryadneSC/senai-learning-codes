package br.com.senai.aryadne.assessments.Ass01;

import java.util.Scanner;

public class Tamagushi {
	private String nome;
	private int fome;
	private int tedio;
	private int idade;
	
	public Tamagushi (String nome, int fome, int tedio, int idade) {
		setNome(nome);
		this.fome = fome;
		this.tedio = tedio;
		setIdade(idade);
	}
	
	public void setNome (String nome) {
		if (nome == null || nome.isEmpty()) {
			throw new IllegalArgumentException("Nome inválido!");
		}
		this.nome = nome;
	}
	
	public void setFome (int fome) {
		if (fome > 100) {
			System.out.println(nome + " morreu de fome!");
			return;
		}
		this.fome = fome;
	}
	
	public void setTedio (int tedio) {
		if (tedio > 100) {
			System.out.println(nome + " morreu de tédio!");
			return;
		}
		this.tedio = tedio;
	}
	
	public void setIdade (int idade) {
		if (idade < 0) {
			throw new IllegalArgumentException("Idade inválida!");
		}
		this.idade = idade;
	}
	
	public String getNome () {
		return nome;
	}
	
	public int getFome () {
		return fome;
	}
	
	public int getTedio () {
		return tedio;
	}
	
	public int getIdade () {
		return idade;
	}
	
	public void brincar (int minutos) {
		if (minutos < 0) {
			System.out.println("Insira um valor válido!");
			return;
		} 
		tedio = tedio - minutos;
				System.out.println("Você brincou com " + nome + "!");
		System.out.println("Tédio de " + nome + ": " + tedio + "%");
		
		if (tedio < 0) tedio = 0;
	}
	
	public void alimentar (int quantidade) {
		if (quantidade < 0) {
			System.out.println("Insira um valor válido!");
			return;
		}
		fome = fome - quantidade;
				System.out.println("Você alimentou " + nome + "!");
		System.out.println("Fome de " + nome + ": " + fome + "%");
		
		if (fome < 0) fome = 0;
	}
	
	public int getHumor() {
		return 200 - (fome + tedio);
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// teste 1: criando Tamagushi
		Tamagushi t = new Tamagushi("Pitucho", 2, 2, 1);
		
		// teste 2: prints e scanner para brincar, alimentar ou ver humor
		int op;
		do {
			System.out.println("Tamagushi: " + t.getNome() 
					+   "| Fome: " + t.getFome()
					+ "% | Tédio: " + t.getTedio() 
					+ "% | Idade: " + t.getIdade() + "\n" 
					
					+ "[1] ALIMENTAR\n"
					+ "[2] BRINCAR\n"
					+ "[3] VER HUMOR");
			System.out.print("ESCOLHA: ");
			op = sc.nextInt();
			sc.nextLine();
			
			switch(op) {
			case 1:
				System.out.println("Quanto deseja alimentar (g) " + t.getNome() + "?");
				int alimentar = sc.nextInt();
				sc.nextLine();
				t.alimentar(alimentar);
				break;
			case 2:
				System.out.println("Por quanto tempo (min) vai brincar com " + t.getNome() + "?");
				int brincar = sc.nextInt();
				sc.nextLine();
				t.brincar(brincar);
				break;
			case 3:
				System.out.println("Humor: " + t.getHumor());
				break;
			case 0:
				System.out.println("Até logo!");
				break;
			default:
				System.out.println("Opção inválida!");
				return;
			}
			System.out.println("___________________________________________");
		} while (op != 0);
		
			sc.close();
	}

}
