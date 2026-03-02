package br.com.senai.exercises;

public class Person {
    private String name;
    private int age;
    private double weight, height;
    private boolean isAlive = true;
    private String deathCause;
    
    public void setName(String name) {
        this.name = name;
    }
    
    public String getName() {
        return this.name;
    }
    
    public void setAge(int age) {
        if(this.age >= 0) {
            System.out.println(this.name + " is " +this.age + " old");
            this.age = age;
        } else if(this.age < 0) {
            System.out.println("Please set a valid age!");
        }
    }
    
    public int getAge() {
        return this.age;
    }
    
    public void setWeight(double weight) {
        this.weight = weight;
    }
    
    public double getWeight() {
        return this.weight;
    }
    
    public double getHeight() {
        return this.height;
    }
    
    public void setheight(double height) {
        this.height = height;
    }
}