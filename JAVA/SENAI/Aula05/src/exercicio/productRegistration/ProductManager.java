package exercicio.productRegistration;

import java.util.ArrayList;
import java.util.Scanner;

import exercicio.productRegistration.Product;

public class ProductManager {
	private ArrayList<Product> stock = new ArrayList<>();
	
	Scanner sc = new Scanner(System.in);
	
	public void createProduct(Scanner productName) {
		if (stock == null) throw new IllegalArgumentException("Unexpected action.");
		
		System.out.println("Enter ID: ");
		int id = sc.nextInt();
		sc.nextLine();
		
		System.out.println("Enter name: ");
		String name = sc.nextLine();
		sc.nextLine();
		
		System.out.println("Enter price: ");
		double price = sc.nextInt();
		sc.nextLine();
		
		System.out.println("Enter quantity: ");
		int quantity = sc.nextInt();
		sc.nextLine();
		
		Product newProduct = new Product(id, name, price, quantity);
		
		stock.add(newProduct);
		System.out.println(newProduct + " was added!");
		System.out.println("------------------------------------------");
	}
	
	public void updateProduct(Scanner sc) {
	    System.out.print("Enter the Product ID to update: ");
	    int idToFind = sc.nextInt();
	    sc.nextLine();

	    boolean found = false;

	    for (Product p : stock) {
	        if (p.getId() == idToFind) {
	            System.out.print("Enter the new name: ");
	            String newName = sc.nextLine();
	            
	            p.setName(newName); 
	            
	            System.out.println("Product updated successfully!");
	            found = true;
	            break; 
	        }
	    }

	    if (!found) {
	        System.out.println("Product with ID " + idToFind + " not found.");
	    }
	}
	
	public void removeProduct() {
		System.out.println("Enter the ID to remove: ");
		int idInput = sc.nextInt();
		
		boolean removed = stock.removeIf(newProduct -> newProduct.getId() == idInput);
		
		if (removed) System.out.println(idInput + " was removed");
		else System.out.println(idInput + " not found");
	}
	
	public void readProduct() {
	    if (stock.isEmpty()) {
	        System.out.println("List is empty.");
	        return;
	    }
	    for (Product p : stock) {
	        p.displayProductInfo();
	    }
	    System.out.println("------------------------------------------");
	}
}
