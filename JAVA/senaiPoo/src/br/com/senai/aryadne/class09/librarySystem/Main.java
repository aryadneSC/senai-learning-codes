package br.com.senai.aryadne.class09.librarySystem;

import java.util.Scanner;
import br.com.senai.aryadne.class09.librarySystem.model.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Library library = new Library();
		
		int op;
		
		do {
			System.out.println("===== MENU BIBLIOTECA =====\n"
					+ "1 - Add new book\n"
					+ "2 - Add new magazine\n"
					+ "3 - Add new newspaper\n"
					+ "4 - List source material\n"
					+ "5 - Search by title\n"
					+ "6 – Lend source material\n"
					+ "7 - Exit");
			
			System.out.println("Select: ");
			op = sc.nextInt();
			sc.nextLine();
			
			switch(op) {
			case 1:
				library.addSource(null);
				break;
				
			case 2:
				library.addSource(null);
				break;
				
			case 3:
				library.addSource(null);
				break;
				
			case 4:
				library.readSources();
				break;
				
			case 5:
				library.findByTitle(null);
				break;
				
			case 6:
				library.lendSource(null);
				break;
			
			case 7:
				System.out.println("Exiting program...");
				
			default:
				System.out.println("Unexpected option. Try again!");
			}
			
			
		} while (op != 7);
		
		sc.close();
		
	}

}
