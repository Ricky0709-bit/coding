package com.finance.accounts;

public class Account {
	private String accountNumber;
	private String AccountHoldername;
	private double balance;
	public Account(String accountNumber, String accountHolderName, double initialBalance) {
		this.accountNumber = accountNumber;
		this.AccountHoldername = accountHolderName;
		this.balance = initialBalance;
	}
	
	public String getAccountNumber() {
		return accountNumber;
	}
	
	public String getAccountHolderName() {
		return AccountHoldername;
	}
	
	public double getBalance() {
		return balance;
	}
	
	public void deposit(double amount) {
		if (amount > 0) {
			balance += amount;
		} else {
			System.out.println("Deposit amount must be positive.");
		}
	}
	
	public void withdraw(double amount) {
		if (amount > 0 && amount <= balance) {
			balance -= amount;
		} else if (amount > balance) {
			System.out.println("Insufficient funds for withdrawal.");
		} else {
			System.out.println("Withdrawal amount must be positive.");
		}
	}
	
	
	public void transfer(double amount, Account targetAccount) {
		if (amount > 0 && amount <= balance) {
			this.withdraw(amount);
			targetAccount.deposit(amount);
		}
		else if (amount > balance) {
			System.out.println("Insufficient funds for transfer.");
		} else {
			System.out.println("Transfer amount must be positive.");
		}
	}
	
	public void printAccountDetails() {
		System.out.println("Account Details:");
		System.out.println("Account Number: " + accountNumber);
		System.out.println("Account Holder Name: " + AccountHoldername);
		System.out.println("Balance: Rs." + balance);
		System.out.println("-----------------------------");
	}
}
