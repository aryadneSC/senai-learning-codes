public class ContaInvestimento {
    int numeroDaConta;
    String nomeDoTitular;
    double saldo;
    double taxaJuros;

    public ContaInvestimento(int numeroDaConta, String nomeDoTitular, double saldoInicial, double taxaJuros) {
        this.numeroDaConta = numeroDaConta;
        this.nomeDoTitular = nomeDoTitular;
        this.saldo = saldoInitial;
        this.taxaJuros = taxaJuros;
    }

    public void adicioneJuros() {
        this.saldo += (this.saldo * (this.taxaJuros / 100));
    }

    public static void main(String[] args) {
        ContaInvestimento minhaConta = new ContaInvestimento(101, "Aryadne", 1000.0, 10.0);
        
        for (int i = 0; i < 5; i++) {
            minhaConta.adicioneJuros();
        }
        
        System.out.println("Saldo resultante: " + minhaConta.saldo);
    }
}