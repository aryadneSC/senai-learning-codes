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
    
    public void comerMacaco(Macaco outroMacaco) {
        this.estomago.add(this.nome + " devorou " + outroMacaco.getNome() + "!");
        this.estomago.add(this.nome + " cometeu canibalismo!");
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
        Macaco meuMacaco2 = new Macaco("Jurandir");
        
        System.out.println("Macacos " + meuMacaco.getNome() + " e " + meuMacaco2.getNome() + " nasceram!");
        
        meuMacaco.verEstomago();

        System.out.println(meuMacaco.getNome() + " esta com fome!");
            
        System.out.println("Alimentar o Chico com: ");
        String novoAlimento = sc.nextLine();
        
        meuMacaco.comer(novoAlimento);
        
        meuMacaco.verEstomago();
        
        meuMacaco.digerir();

        System.out.println("Rip Jurandir :(");
        meuMacaco.comerMacaco(meuMacaco2); 
        meuMacaco.verEstomago();
        
        sc.close();
    }
}