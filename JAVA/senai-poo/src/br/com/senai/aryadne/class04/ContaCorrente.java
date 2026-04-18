package br.com.senai.aryadne.class04;

public class ContaCorrente {
    private int numeroDaConta;
    private String nomeDoTitular;
    private double saldo;

    public ContaCorrente(int numeroDaConta, String nomeDoTitular) {
        this.numeroDaConta = numeroDaConta;
        this.nomeDoTitular = nomeDoTitular;
        this.saldo = 0;
    }

    public void depositar(double valor) {
        this.saldo += valor;
    }

    public void sacar(double valor) {
        if (valor <= this.saldo) {
            this.saldo -= valor;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        ContaCorrente minhaConta = new ContaCorrente(1234, "Aryadne");

        minhaConta.depositar(500.0);
        minhaConta.sacar(150.0);
        minhaConta.sacar(50.0);

        System.out.println("Titular: " + minhaConta.nomeDoTitular);
        System.out.println("Número: " + minhaConta.numeroDaConta);
        System.out.println("Saldo Atual: " + minhaConta.saldo);
    }
}
