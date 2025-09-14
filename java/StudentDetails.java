package javap;
import java.util.Scanner;

class Account{
	int id;
	Scanner sc = new Scanner(System.in);
	
	Account(){
		System.out.print("Enter Student ID:");
		id = sc.nextInt();
	}
}

class Book extends Account{
	String book;
	
	Book(){
		System.out.print("Enter Book Name:");
		sc.nextLine();
		book = sc.nextLine();
	}
}

class Students extends Book{
	String name;
	
	Students(){
		System.out.print("Enter Name:");
		name = sc.nextLine();
	}
}
public class StudentDetails {
     public static void main(String[] args) {
    	 Students s = new Students();
    	 System.out.println("\nStudent Details:\nID:"+ s.id +"\nBook Name:"+ s.book +"\nName:"+ s.name);
     }
}

