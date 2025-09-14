package javap;

public class TryCatch {
	public static void main(String [] args) {
		try {
			int data = 7/0;
			System.out.println(data);
		}
		catch(ArithmeticException e) {
			System.out.println(e);
		}
		finally {
			System.out.println("Finally block is always executed");
		}
	}
}
