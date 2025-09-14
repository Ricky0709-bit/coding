package javap;

public class NestedTryCatch {
	public static void main(String [] args) {
		try {
			try {
				int x[] = new int[7];
				x[9] = 7;
				System.out.println(x[9]);
			}
			catch(ArrayIndexOutOfBoundsException e) {
				System.out.println("Error:  " + e);
			}
			
			try {
				int data = 7/0;
				System.out.println(data);
			}
			catch(ArithmeticException e) {
				System.out.println("Error:  " + e);
			}
		}
		catch(Exception e) {
			System.out.println("Error:  " + e);
		}
		finally {
			System.out.println("Finally block is always executed");
		}
	}
}
