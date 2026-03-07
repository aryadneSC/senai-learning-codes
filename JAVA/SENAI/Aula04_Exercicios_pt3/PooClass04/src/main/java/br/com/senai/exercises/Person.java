package br.com.senai.exercises;

public class Person {
    private String name;
    private int age;
    private double weight, height;
    private boolean isAlive = true;
    private String[] deathCause;
    
    public void setName(String name) {
        this.name = name;
    }
    
    public String getName() {
        return this.name;
    }
    
    public void setAge(int age) {
        if(age >= 0) {
            this.age = age;
            System.out.println(this.name + " is " +this.age + " old");
        }
        if(age < 0) {
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
        return this.isAlive;
    }
    
    public void growOld() {
        if(age < 21 == 0) {
            this.height += 0.5;
            this.age++;
        } if(age > 20 && <= 21 == 0) {
            System.out.println(this.name + " is an adult!");
        }
        System.out.println("It's " + this.name + " birthday!");
    }
    
    public Person(String name, int age, double weight, double height) {
        this.name = name;
        this.age = age;
        this.weight = weight;
        this.height = height;
        this.isAlive = true;
        
        this.deathCause = new String[] {
            "Meteor",
            "Shock",
            "Drow",
            "Starvation",
            "Choke",
        };
    }
    
}p