package br.com.senai.aryadne.class05.list.activity03;

public class BankAccount {
    private String holder;
    private int accountNumber;
    private double balance;

    public BankAccount(String holder, int accountNumber, double initialBalance) {
    	if (holder == null || holder.trim().isEmpty()) throw new IllegalArgumentException("Invalid name.");
        
    	this.holder = holder;
        this.accountNumber = accountNumber;
        deposit(initialBalance); 
    }

    public void deposit(double amount) {
        if (amount < 0) throw new IllegalArgumentException("Deposit must be positive.");
        this.balance += amount;
    }

    public void withdraw(double amount) {
        if (amount < 0) throw new IllegalArgumentException("Withdraw must be positive.");
        if (amount > this.balance) throw new IllegalArgumentException("Insufficient balance.");
        this.balance -= amount; 
    }

    public double getBalance() {
        return this.balance; 
    }

    public void displayAccountInfo() {
        System.out.println("Holder: " + holder);
        System.out.println("Account Number: " + accountNumber);
        System.out.println("Current Balance: R$ " + balance);
    }
}