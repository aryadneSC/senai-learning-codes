package Product;

public class Main {
        public static void main(String[] args) {
    Product p = new Product("Arroz", 10.15, 20);

    p.displayInfo();

    System.out.println("Total in Stock: R$ " + p.getTotalValueInStock());
    }
}