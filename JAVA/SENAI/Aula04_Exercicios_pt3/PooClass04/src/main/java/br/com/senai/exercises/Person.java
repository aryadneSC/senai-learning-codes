package br.com.senai.exercises;

public class Person {
    private String name;
    private int age;
    private double weight, height;
    private boolean isAlive = true;
    private String List<String>deathCause;
    
    public void setName(String name) {
        this.name = name;
    }
    
    public String getName() {
        return this.name;
    }
    
    public void setAge(int age) {
        if(age >= 0) {
            System.out.println(this.name + " is " +this.age + " old");
        } 
        this.age = age;
        else(age < 0) {
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
    
    public void setHeight(double height) {
        this.height = height;
    }
    
    public double getHeight() {
        return this.height;
    }
    
    public boolean isAlive() {
        
    }
    
    public String deathCause() {
        // random death
    }
    
    public String toString() {
        // is it necessary? why?
    }
    
}