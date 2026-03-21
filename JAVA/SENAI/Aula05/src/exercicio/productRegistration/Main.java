package exercicio.productRegistration;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ProductManager manager = new ProductManager();
        int op;

        do {
        	System.out.println("----------------------------------------------");
            System.out.println("""
                    !- MENU -!
                    [1] Create product
                    [2] Read product
                    [3] Update product
                    [4] Delete product
                    [5] Exit
                    """);

            System.out.print("Choose: ");
            op = sc.nextInt();
            sc.nextLine();
            System.out.println();

            switch (op) {
                case 1:
                    manager.createProduct(sc);
                    break;

                case 2:
                	manager.readProduct();
                    break;

                case 3:
                	manager.updateProduct(sc);
                    break;

                case 4:
                	manager.removeProduct(sc);
                    break;

                case 5:
                    System.out.println("Exiting program...");
                    break;

                default:
                    System.out.println("Unexpected option. Try again!");
            }

        } while (op != 5);

        sc.close();
    }
}