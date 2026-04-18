package br.com.senai.aryadne.class05.list.extra;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Cellphone c = new Cellphone("Samsung", "Galaxy s10");
		c.turnOn();
		
		int password;
		int op;
		do {
			System.out.println("Password: ");	
			password = sc.nextInt();
			sc.nextLine();
			
			System.out.println("""
					! INITIAL MENU !
					[1] Read e-mails;
					[2] Make a call; // list contacts
					[0] Turn off;					
					""");
			
			System.out.println("Choose: ");
			op = sc.nextInt();
			sc.nextLine();
			
			switch (op) {
			case 1:
				c.readEmail();
				break;
			case 2:
				c.showContacts();
				System.out.println(" Call to: ");
				int contactChoice = sc.nextInt();
				sc.nextLine();
				
				String name = c.getContactName(contactChoice);
				
				if (name != null) {
					c.makeCall(name);
				} else {
					System.out.println("Invalid contact.");
				}
				break;
			case 0:
				System.out.println("Turning off...");
				break;
			default:
				System.out.println("Unexpected error. Try again.");
			}
		} while (op != 0);
		
		sc.close();
	}
	
}