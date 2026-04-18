package br.com.senai.aryadne.class05.productRegistration;

public class Product {
    private int id;
    private String name;
    private double price;
    private int quantity;

    public Product(int id, String name, double price, int quantity) {
        setId(id);
        setName(name);
        setPrice(price);
        setQty(quantity);
    }

    public int getId() { 
    	return id; 
    	}
    public String getName() { 
    	return name; 
    	}

    public void displayProductInfo() {
        System.out.println("ID: " + id + " | Nome: " + name + " | Preço: R$ " + price + " | Qtd: " + quantity);
    }
	
	public void setId(int id) {
		if (id <= 0) throw new IllegalArgumentException("ID invalid.");
		this.id = id;
	}
	
	public void setName(String name) {
		if (name == null || name.trim().isEmpty()) throw new IllegalArgumentException("Product's name is invalid.");
		this.name = name;
	}
	
	public void setPrice(double price) {
		if (price < 0) throw new IllegalArgumentException("Price cannot be negative.");
		this.price = price;
	}
	
	public void setQty(int quantity) {
		if (quantity < 0) throw new IllegalArgumentException("Quantity cannot be negative.");
		this.quantity = quantity;
	}
	
	public String toString() {
		return name;
	}
	
}
