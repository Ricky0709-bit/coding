package com.finance.tax;

public class GSTCalculator {
	private static final double GST_RATE = 0.18;
	
	public static double calculateGST(double amount) {
		if (amount < 0) {
			System.out.println("Amount must be non-negative.");
			return 0;
		}
		return amount * GST_RATE;
	}
	
	public static double calculateIncomeTax(double income) {
		if (income < 0) {
			System.out.println("Income must be non-negative.");
			return 0;
		}
		
		double tax;
		if (income <= 250000) {
			tax = 0;
		} else if (income <= 500000) {
			tax = (income - 250000) * 0.05;
		} else if (income <= 1000000) {
			tax = (income - 500000) * 0.1 + 12500;
		} else {
			tax = (income - 1000000) * 0.3 + 37500; 
		}
		return tax;
	}
	
	public double calculateTotalTax(double income, double gstAmount) {
		double incomeTax = calculateIncomeTax(income);
		return incomeTax + gstAmount;
	}
	
	public void printTaxDetails(double income, double gstAmount) {
		double incomeTax = calculateIncomeTax(income);
		System.out.println("Income: Rs." + income);
		System.out.println("GST Amount: Rs." + gstAmount);
		System.out.println("Income Tax: Rs." + incomeTax);
		System.out.println("Total Tax Payable: Rs." + (incomeTax + gstAmount));
	}
}
