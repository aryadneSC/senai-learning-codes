package br.com.senai.aryadne.class03;

class Alimento {
    private String nome;
    private double kcal;
    
    public Alimento(String nome, double kcal) {
        this.nome = nome;
        this.kcal = kcal;
    }
    
    public void setNome(String nome) {
        this.nome = nome;
    }
    
    public String getNome() {
        return this.nome;
    }
    
    public void setKcal(double kcal) {
        this.kcal = kcal;
    }
    
    public double getKcal() {
        return this.kcal;
    }
    
    @Override
    public String toString() {
        return this.nome + "  " + this.kcal + " Kcal";
    }
    
}

public class Main {
	public static void main(String[] args) {
		
		Alimento alimento1 = new Alimento("Melancia", 32.0);
		
		Alimento alimento2 = new Alimento("Maçã", 72.0);
		
		Alimento alimento3 = new Alimento("Ovo", 77.0);
		
		System.out.println(" " + alimento1.toString());
		System.out.println(" " + alimento2);
		System.out.println(" " + alimento1);
		
		alimento3.setNome("Ovo frito");
		alimento3.setKcal(98.0);
		
		System.out.println(" " + alimento3);
	}
}