package br.com.senai.aryadne.class05.list.activity05;

public class Car {
    private String brand;
    private int model;
    private double speed;

    public Car(String brand, int model, double initialSpeed) {
        setBrand(brand);
        setModel(model);
        if (initialSpeed < 0) initialSpeed = 0;
        this.speed = initialSpeed;
    }

    public void speedUp(double amount) {
        if (amount < 0) throw new IllegalArgumentException("Acceleration must be positive.");
        this.speed += amount; 
    }

    public void slowDown(double amount) {
        if (amount < 0) throw new IllegalArgumentException("Braking amount must be positive.");
        this.speed -= amount;
        
        if (this.speed < 0) {
            this.speed = 0;
        }
    }

    public void displayInfo() {
        System.out.println("Brand: " + brand + " | Model: " + model);
        System.out.println("Current Speed: " + speed + " km/h");
        System.out.println("----------------------------");
    }

    public void setBrand(String brand) {
        if (brand == null || brand.trim().isEmpty()) throw new IllegalArgumentException("Invalid brand.");
        this.brand = brand;
    }

    public void setModel(int model) {
        if (model < 1886) throw new IllegalArgumentException("Invalid year.");
        this.model = model;
    }
}