package exercicio01;

import java.util.Scanner;

public class Bola {
	private String cor;
	
	String getCor() {
		return cor;
	}
	
	public void setCor(String c) {
		this.cor = c;
	}

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		Bola bola_1 = new Bola();
		
		bola_1.cor = "Verde";
		
		System.out.println("Nomeie a bola: ");
		String c_bola_1 = sc.nextLine();

		System.out.println("A cor da bola '" + c_bola_1 + "' eh = " + bola_1.cor);

	}

}