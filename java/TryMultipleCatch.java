package javap;

public class TryMultipleCatch {
	private static String s;

	public static void main(String [] args) {
		try {
			int x[] = new int[7];
			x[9] = 7;
			s = null;
			System.out.println(s.length());
		}
		catch(ArithmeticException e) {
			System.out.println("Error:  " + e);
		}
		catch(ArrayIndexOutOfBoundsException e) {
			System.out.println("Error:  " + e);
		}
		catch(NullPointerException e) {
			System.out.println("Error:  " + e);
		}
		finally {
			System.out.println("Finally block is always executed");
		}
	}
}
