package com;
import com.finance.accounts.*;
import com.finance.tax.*;

public class Main {
    public static void main(String[] args) {
    	
        System.out.println("\n======= ACCOUNT OPERATIONS =======");
    	Account acc = new Account("67111983413", "Ritesh", 50000.0);
    	acc.deposit(75000.0);
    	acc.printAccountDetails();
    	acc.transfer(20000.0, new Account("67111981305", "Hitesh", 25000.0));
    	
    	System.out.println("\n======= CURRENT ACCOUNT =======");
    	CurrentAccount c_acc = new CurrentAccount("67111983413", "Ritesh", 150000.0, 30000.0);
    	c_acc.isOverdraftAvailable(20000.0);
    	c_acc.withdraw(20000.0);
    	c_acc.printAccountDetails();
    	
    	System.out.println("\n======= SAVINGS ACCOUNT =======");
    	SavingsAccount s_acc = new SavingsAccount("67111983413", "Ritesh", 250000.0, 0.12);
    	s_acc.deposit(50000.0);
    	s_acc.applyInterest();
    	s_acc.printAccountDetails();
    	
    	System.out.println("\n======= TAX CALCULATIONS =======");
    	double income = 600000.0;
    	double gstAmount = GSTCalculator.calculateGST(20000.0);
    	
    	GSTCalculator calculator = new GSTCalculator();
    	calculator.printTaxDetails(income, gstAmount);
    	
    	System.out.println("\n======= TAXPAYER DETAILS =======");
    	TaxPayer taxpayer = new TaxPayer("Ritesh", income);
    	taxpayer.printTaxDetails();
    	System.out.println("------------------------------");
    	
    	
    	taxpayer.setIncome(700000.0);
    	taxpayer.printTaxDetails();
    	System.out.println("Taxable Income: Rs." + taxpayer.getTaxableIncome());
    	System.out.println("------------------------------");
    	
    	taxpayer.setDeductions(40000.0);
    	taxpayer.printTaxDetails();
    	System.out.println("Updated Taxable Income: Rs." + taxpayer.getTaxableIncome());
    	
    	System.out.println("\n======= TAX REPORT =======");
    	TaxReport taxReport = new TaxReport(taxpayer, calculator);
    	taxReport.generateReport();
    }
}
