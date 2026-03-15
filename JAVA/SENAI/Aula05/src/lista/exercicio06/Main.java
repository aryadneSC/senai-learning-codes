package lista.exercicio06;

public class Main {

	public static void main(String[] args) {
		Library book1 = new Library("Dom Casmurro", "Machado de Assis", 256, true);

		book1.displayInfo();
		
		book1.borrowBook();
		book1.borrowBook();
		book1.returnBook();
		
		book1.displayInfo();
	}

}
