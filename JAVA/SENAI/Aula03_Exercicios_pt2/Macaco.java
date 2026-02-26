import java.util.ArrayList;
import java.util.List;

class Macaco {
    private String nome;
    private List<String> estomago;
    
    public Macaco(String nome) {
        this.nome = nome;
    }
    
    public String getNome() {
        return this.nome;
    }
}

public class Main {
	public static void main(String[] args) {
		
		Macaco meuMacaco = new Macaco("Chico");
		System.out.println("Macaco " + meuMacaco.getNome() + " nasceu!");
		
		//TODO add comer(String alimento), verEstomago()
	}
}