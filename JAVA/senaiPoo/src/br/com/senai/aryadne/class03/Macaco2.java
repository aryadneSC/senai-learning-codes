package br.com.senai.aryadne.class03;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Macaco {
    private String nome;
    private List<String> estomago;
    
    public Macaco(String nome) {
        this.nome = nome;
        this.estomago = new ArrayList<>(); 
    }
    
    public String getNome() {
        return this.nome;
    }
    
    public void comer(String alimento) {
        this.estomago.add(alimento);
        System.out.println(this.nome + " comeu " + alimento);
    }
    
    public void comerMacaco(Macaco outroMacaco) {
        this.estomago.add(this.nome + " devorou " + outroMacaco.getNome() + "!");
        this.estomago.add(this.nome + " cometeu canibalismo!");
        System.out.println("Rip " + outroMacaco.getNome() + " :(");
    }
    
    public void verEstomago() {
        System.out.println("Estomago do " + this.nome + ": " + this.estomago);
    }
    
    public void digerir() {
        this.estomago.clear();
        System.out.println(this.nome + " fez caca");
    }
}

public class Exercicio02 {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        Macaco meuMacaco = new Macaco("Chico");
        Macaco meuMacaco2 = new Macaco("Jurandir");
        
        System.out.println("Macacos " + meuMacaco.getNome() + " e " + meuMacaco2.getNome() + " nasceram!\n");
        
        System.out.println(meuMacaco.getNome() + " esta com fome!");
        System.out.println("Alimentar o Chico com: ");
        String novoAlimento = sc.nextLine();
        
        if (novoAlimento.equalsIgnoreCase(meuMacaco2.getNome())) {
            meuMacaco.comerMacaco(meuMacaco2); 
            meuMacaco.verEstomago();
        } else {
            meuMacaco.comer(novoAlimento);
            meuMacaco.verEstomago();
            meuMacaco.digerir();
            
            System.out.println("\nAgora o " + meuMacaco2.getNome() + " esta com fome!");
            System.out.println("Alimentar o Jurandir com: ");
            String alimentoJurandir = sc.nextLine();
            
            if (alimentoJurandir.equalsIgnoreCase(meuMacaco.getNome())) {
                meuMacaco2.comerMacaco(meuMacaco);
                meuMacaco2.verEstomago();
            } else {
                meuMacaco2.comer(alimentoJurandir);
                meuMacaco2.verEstomago();
                meuMacaco2.digerir();
            }
        }
        
        sc.close();
    }
}