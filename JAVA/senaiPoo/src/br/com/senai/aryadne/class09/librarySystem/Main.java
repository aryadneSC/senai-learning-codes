package br.com.senai.aryadne.class09.librarySystem;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Library l = new Library();
		
		int op;
		do {
			System.out.println("===== MENU BIBLIOTECA =====\n"
					+ "1 - Add new book\n"
					+ "2 - Add new magazine\n"
					+ "3 - Add newspaper\n"
					+ "4 - Read all materials\n"
					+ "5 - Read by title\n"
					+ "6 – Lend material\n"
					+ "7 - Exit");
			System.out.println("\nSELECT: ");
			op = sc.nextInt();
			sc.nextLine();
			
		switch(op) {
		case 1:
			System.out.print("| Title: ");
			String bt = sc.nextLine();
			System.out.print("| Author: ");
			String ba = sc.nextLine();
			System.out.print("| Publication Year: ");
			int bpy = sc.nextInt();
			sc.nextLine();
			System.out.print("| Number of Pages: ");
			int pages = sc.nextInt();
			sc.nextLine();
			
			l.addMaterial(new Book(bt, ba, bpy, pages));
			break;
		case 2:
			System.out.print("| Title: ");
			String mt = sc.nextLine();
			System.out.print("| Author: ");
			String ma = sc.nextLine();
			System.out.print("| Publication Year: ");
			int mpy = sc.nextInt();
			sc.nextLine();
			System.out.print("| Edition: ");
			int edition = sc.nextInt();
			sc.nextLine();
			
			l.addMaterial(new Magazine(mt, ma, mpy, edition));
			break;
		case 3:
			System.out.print("| Title: ");
			String nt = sc.nextLine();
			System.out.print("| Author: ");
			String na = sc.nextLine();
			System.out.print("| Publication Year: ");
			int npy = sc.nextInt();
			sc.nextLine();
			System.out.print("| Edition Date: ");
			String editionDate = sc.nextLine();
			
			l.addMaterial(new Newspaper(nt, na, npy, editionDate));
			break;
		case 4:
			l.readMaterial();
			break;
		case 5:
			System.out.print("| Title: ");
			String title = sc.nextLine();
			LibrarySource isFound = l.readByTitle(title);
			if(isFound != null) {
				isFound.showDetails();
			} else {
				System.out.println("| Title not found!");
			}
			break;
		case 6:
			System.out.print("| Title: ");
			String lend = sc.nextLine();
			LibrarySource isAvaliable = l.readByTitle(lend);
			if(isAvaliable != null) {
				l.lendMaterial(isAvaliable);
			} else {
				System.out.println("| Title not found!");
			}
			break;
		case 7:
			System.out.println("| Exiting...");
			break;
		default:
			System.out.println("| Invalid option!");
		}
			System.out.println();
		} while (op != 7);
		
		sc.close();
	}

}
