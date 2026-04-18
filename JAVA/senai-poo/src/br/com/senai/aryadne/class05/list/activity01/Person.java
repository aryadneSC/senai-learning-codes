package br.com.senai.aryadne.class05.list.activity01;

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

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return this.name;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public int getAge() {
        return this.age;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public double getHeight() {
        return this.height;
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