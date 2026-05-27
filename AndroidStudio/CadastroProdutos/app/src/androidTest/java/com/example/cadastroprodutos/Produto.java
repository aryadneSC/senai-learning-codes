package com.example.cadastroprodutos;

public class Produto {
    private String nome;
    private double preco;

    public Produto (String nome, double preco) {
        setNome(nome);
        setPreco(preco);
    }

    public void setNome (String nome) {
        if (nome == null || nome.isEmpty())
            throw new IllegalArgumentException("Nome inválido!");
        this.nome = nome;
    }

    public void setPreco (double preco) {
        if (preco < 0)
            throw new IllegalArgumentException("Preço inválido!");
        this.preco = preco;
    }

    public String getNome () {
        return nome;
    }

    public double getPreco () {
        return preco;
    }

    @Override
    public String toString () {
        return "Nome: |" + getNome() + " Preço: R$ " + getPreco();
    }
}
