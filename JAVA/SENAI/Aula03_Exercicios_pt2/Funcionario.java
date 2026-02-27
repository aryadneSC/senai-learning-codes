class Funcionario {
    private String nome;
    private double salario;

    public Funcionario(String nome) {
        this.nome = nome;
        // TODO set salary to 0.0 (DONE)
        this.salario = 0.0; 
    }

    public String getNome() {
        return this.nome;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    public double getSalario() {
        return this.salario;
    }

    public void aumentarSalario(double percentualAumentoSalario) {
        double valorAumento = this.salario *
(percentualAumentoSalario / 100);
        this.salario += valorAumento;
    }
}

public class Exercicio01 {
    public static void main(String[] args) {
        Funcionario meuFuncionario = new Funcionario("Ana");
        
        System.out.println("Nome do funcionario: " + meuFuncionario.getNome());

        // Atribuite Ana's actual salary
        meuFuncionario.setSalario(2000);
        System.out.println("Salario inicial R$ " + meuFuncionario.getSalario());

        // add salary increment
        meuFuncionario.aumentarSalario(10);
        System.out.println("Salario final após 10% de aumento: R$ " + meuFuncionario.getSalario());
    }
}