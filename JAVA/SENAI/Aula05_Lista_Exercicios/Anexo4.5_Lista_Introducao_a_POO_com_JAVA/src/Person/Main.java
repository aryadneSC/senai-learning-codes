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

            System.out.print("Name: ");
            String name = sc.nextLine();

            System.out.print("Age: ");
            int age = sc.nextInt();

            System.out.print("Height (cm): ");
            double height = sc.nextDouble();
            sc.nextLine(); 

            Person p = new Person(name, age, height);

            p.displayData();
            System.out.println();
            
            if (p.isAdult()) {
                System.out.println("You're an adult. Waterslide Allowed! :D");
            } else {
                System.out.println("Waterslide Denied! Sorry kid :(");
            }

            System.out.print("\nDo you want to register another person? (y/n): ");
            choice = sc.nextLine();

        } while (choice.equalsIgnoreCase("y"));

        System.out.println("Have a splashy day!");
        sc.close();
    }
}