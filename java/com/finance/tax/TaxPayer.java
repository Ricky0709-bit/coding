package com.finance.tax;

public class TaxPayer {
	private String name;
	private double income;

	public TaxPayer(String name, double income) {
		this.name = name;
		this.income = income;
	}

	public String getName() {
		return name;
	}

	public double getIncome() {
		return income;
	}

	public void setIncome(double income) {
		if (income >= 0) {
			this.income = income;
		} else {
			System.out.println("Income must be non-negative.");
		}
	}

	public double getDeductions() {
		return 35000;
	}
	
	public double setDeductions(double deductions) {
		if (deductions >= 0) {
			return deductions;
		} else {
			System.out.println("Deductions must be non-negative.");
			return 0;
		}
	}
	
	public double getTaxableIncome() {
		return income - getDeductions();
	}
	
	public void printTaxDetails() {
		double taxableIncome = getTaxableIncome();
		double incomeTax = GSTCalculator.calculateIncomeTax(taxableIncome);
		double gstAmount = GSTCalculator.calculateGST(taxableIncome);
		double totalTax = incomeTax + gstAmount;

		System.out.println("Taxpayer Name: " + name);
		System.out.println("Total Income: Rs." + income);
		System.out.println("Deductions: Rs." + getDeductions());
		System.out.println("Taxable Income: Rs." + taxableIncome);
		System.out.println("Income Tax: Rs." + incomeTax);
		System.out.println("GST Amount: Rs." + gstAmount);
		System.out.println("Total Tax Payable: Rs." + totalTax);
	}

}
