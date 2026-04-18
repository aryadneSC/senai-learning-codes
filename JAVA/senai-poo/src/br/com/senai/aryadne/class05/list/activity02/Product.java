package br.com.senai.aryadne.class05.list.activity02;

public class Product {
    private String name;
    private double price;
    private int quantityInStock;

    public Product(String name, double price, int quantity) {
        setName(name);
        setPrice(price);
        addStock(quantity);
    }

    public void setName(String name) {
        if(name == null || name.trim().isEmpty()) throw new IllegalArgumentException("Product name invalid.");
        this.name = name;
    }

    public String getName() {
        return this.name;
    }

    public void setPrice(double price) {
        if(price < 0) throw new IllegalArgumentException("Price cannot be negative.");
        this.price = price;
    }

    public double getPrice() {
        return this.price;
    }

    public void addStock(int quantity) {
        if(quantity < 0) throw new IllegalArgumentException("Quantity cannot be negative.");
        this.quantityInStock += quantity;
    }

    public double calculateTotalValue() {
        return this.price * this.quantityInStock;
    }

    public void displayInfo() {
        System.out.println("Product: " + this.name);
        System.out.println("Price: R$ " + this.price);
        System.out.println("Quantity: " + this.quantityInStock);
        System.out.println("Total value in stock: R$ " + calculateTotalValue());
    }
}