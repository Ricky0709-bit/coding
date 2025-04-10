import java.util.Scanner;

public class OddEven {
    public static void main(String[] args) {
        @SuppressWarnings("resource")
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a number: ");
        int num = scanner.nextInt();

        if (num % 2 == 0) {
            System.out.println("Number is Even: " + num);
        } else {
            System.out.println("Number is Odd: " + num);
        }
    }
}