package com.finance.accounts;

public class SavingsAccount extends Account {
	private double interestRate;

	public SavingsAccount(String accountNumber, String accountHolderName, double initialBalance, double interestRate) {
		super(accountNumber, accountHolderName, initialBalance);
		this.interestRate = interestRate;
	}
	
	public void setInterestRate(double interestRate) {
		if (interestRate >= 0) {
			this.interestRate = interestRate;
		} else {
			System.out.println("Interest rate must be non-negative.");
		}
	}

	public double getInterestRate() {
		return interestRate;
	}

	public void applyInterest() {
		double interest = getBalance() * (interestRate / 100);
		deposit(interest);
		System.out.println("Interest applied: Rs." + interest + "\n");
	}

	@Override
	public void printAccountDetails() {
		super.printAccountDetails();
		System.out.println("Interest Rate: " + interestRate + "%");
		System.out.println("-----------------------------");
	}
}
