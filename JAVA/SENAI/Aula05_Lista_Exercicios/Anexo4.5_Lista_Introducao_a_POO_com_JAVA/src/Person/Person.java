/*Exercício 2 — Classe Pessoa
Crie uma classe chamada Pessoa.
Requisitos
A classe deve possuir os seguintes atributos:
• nome
• idade
• altura
Métodos
• método para exibir os dados da pessoa
• método para verificar se a pessoa é maior de idade*/

public class Person {
    private String name;
    private int age;
    private double height;

    public Person(String name, int age, double height) {
        this.name = name;
        this.age = age;
        this.height = height;
    }

    public void displayData() {
        System.out.println("Name: " + this.name);
        System.out.println("Age: " + this.age);
        System.out.println("Height: " + this.height + " cm");
    }

    public boolean isAdult() {
        return this.age >= 18; 
    }
}