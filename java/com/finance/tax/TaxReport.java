package com.finance.tax;

public class TaxReport {
		private TaxPayer taxpayer;
		public TaxReport(TaxPayer taxpayer, GSTCalculator calculator) {
		this.taxpayer = taxpayer;
	}

	public void generateReport() {
		System.out.println("Tax Report for: " + taxpayer.getName());
		System.out.println("Total Income: Rs." + taxpayer.getIncome());
		System.out.println("Deductions: Rs." + taxpayer.getDeductions());
		double taxableIncome = taxpayer.getTaxableIncome();
		System.out.println("Taxable Income: Rs." + taxableIncome);
		
		double incomeTax = GSTCalculator.calculateIncomeTax(taxableIncome);
		double gstAmount = GSTCalculator.calculateGST(taxableIncome);
		double totalTax = incomeTax + gstAmount;
		
		System.out.println("Income Tax: Rs." + incomeTax);
		System.out.println("GST Amount: Rs." + gstAmount);
		System.out.println("Total Tax Payable: Rs." + totalTax);
		System.out.println("-----------------------------");
	}
}
