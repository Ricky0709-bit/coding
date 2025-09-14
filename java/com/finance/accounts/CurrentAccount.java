package com.finance.accounts;

public class CurrentAccount extends Account{
	private double overdraftlimit;
	
	public CurrentAccount(String accountNumber, String accountHolderName, double initialBalance, double overdraftLimit) {
		super(accountNumber, accountHolderName, initialBalance);
		this.overdraftlimit = overdraftLimit;
	}
	
	public double getOverdraftLimit() {
		return overdraftlimit;
	}
	
	public boolean isOverdraftAvailable(double amount) {
		return amount <= (getBalance() + overdraftlimit);
	}
	
	public void withdraw(double amount) {
		if (amount > 0 && isOverdraftAvailable(amount)) {
			double newBalance = getBalance() - amount;
			if (newBalance < 0) {
				System.out.println("Overdraft used. New balance: $" + newBalance);
			}
			super.withdraw(amount);
		} else if (amount <= 0) {
			System.out.println("Withdrawal amount must be positive.");
		} else {
			System.out.println("Insufficient funds for withdrawal, even with overdraft.");
		}
	}
	
	@Override
	public void printAccountDetails() {
		super.printAccountDetails();
		System.out.println("Overdraft Limit: Rs." + overdraftlimit);
		System.out.println("Overdraft Available: " + (isOverdraftAvailable(0) ? "Yes" : "No"));
		System.out.println("-----------------------------");
	}
}
