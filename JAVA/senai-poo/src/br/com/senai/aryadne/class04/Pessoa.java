package br.com.senai.aryadne.class04;

public class Pessoa {
    private String nome;
    private int idade;
    private double peso;
    private double altura;

    public Pessoa(String nome, int idade, double peso, double altura) {
        this.nome = nome;
        this.idade = idade;
        this.peso = peso;
        this.altura = altura;
    }

    public void envelhecer() {
        if (this.idade < 21) {
            this.crescer(0.5);
        }
        this.idade++;
    }

    public void engordar(double peso) {
        this.peso += peso;
    }

    public void emagrecer(double peso) {
        this.peso -= peso;
    }

    public void crescer(double altura) {
        this.altura += altura;
    }
}

public class Main {
	public static void main(String[] args) {
        Pessoa p1 = new Pessoa("Ana", 18, 60.0, 1.65);

        p1.envelhecer();
        p1.envelhecer();
        p1.envelhecer();
        
        p1.engordar(2.5);
        p1.emagrecer(1.0);

        System.out.println("Nome: " + p1.nome);
        System.out.println("Idade: " + p1.idade);
        System.out.println("Peso: " + p1.peso);
        System.out.println("Altura: " + p1.altura);
    }
}