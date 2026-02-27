import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Macaco {
    private String nome;
    private List<String> estomago;
    
    public Macaco(String nome) {
        this.nome = nome;
        this.estomago = new ArrayList<>(); 
    }
    
    public String getNome() {
        return this.nome;
    }
    
    public void comer(String alimento) {
        this.estomago.add(alimento);
        System.out.println(this.nome + " comeu " + alimento);
    }
    
    public void verEstomago() {
        System.out.println("Estomago do " + this.nome + ": " + this.estomago);
    }
    
    public void digerir() {
        this.estomago.clear();
        System.out.println(this.nome + " fez caca");
    }
}

public class Exercicio02 {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        Macaco meuMacaco = new Macaco("Chico");
        
        System.out.println("Macaco " + meuMacaco.getNome() + " nasceu!");
        
        meuMacaco.verEstomago();

        System.out.println(meuMacaco.getNome() + " esta com fome!");
            
        System.out.println("Alimentar com: ");

        String novoAlimento = sc.nextLine();

        meuMacaco.comer(novoAlimento);
        
        meuMacaco.verEstomago();
        
        meuMacaco.digerir();
        
        sc.close();
    }
}