package br.com.senai.aryadne.class05.list.activity02;

public class Main {
    public static void main(String args) {
        Product p = new Product("Arroz", 25.50, 10);

        p.displayInfo();
        
        System.out.println("Total no estoque: R$ " + p.calculateTotalValue());
    }
}