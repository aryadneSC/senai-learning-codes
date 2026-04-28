package br.com.senai.aryadne.class05.list.activity01;

import java.util.Scanner;
public class Main {
    public static void menu() {
        System.out.println("---------------------------------------------------------");
        System.out.println("             WELCOME TO THE WATERPARK!");
        System.out.println("---------------------------------------------------------");
        System.out.println("Please, inform the name, age and height of the person.");
        System.out.println("---------------------------------------------------------");
        System.out.println();
        System.out.println(">> WATERSLIDE RULES!! <<");
        System.out.println("* Minimum age of 18 years old.");
        System.out.println("---------------------------------------------------------");
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String choice;

        menu();

        do {
            Person p = new Person();

            System.out.print("Name: ");
            String name = sc.nextLine();
            p.setName(name);

            System.out.print("Age: ");
            int age = sc.nextInt();
            p.setAge(age);
            sc.nextLine();

            System.out.print("Height (cm): ");
            double height = sc.nextDouble();
            p.setHeight(height);
            sc.nextLine(); 

            System.out.println();
            p.displayData();
            
            if (p.isAdult()) {
                System.out.println("Age: " + p.getAge() + " years old.");
                System.out.println("You're an adult. Waterslide Allowed! :D");
            } else {
                System.out.println("Age: " + p.getAge() + " years old.");
                System.out.println("Waterslide Denied! Sorry kid :(");
            }

            System.out.print("\nDo you want to register another person? (y/n): ");
            choice = sc.nextLine();
            System.out.println();

        } while (choice.equalsIgnoreCase("y"));

        System.out.println("Have a splashy day!");
        sc.close();
    }
}