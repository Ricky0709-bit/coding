package javap;

import java.util.Scanner;

class Calculator {

    public int calculate(int x, int y, String operation) {
        switch (operation) {
            case "add":
                return x + y;
            case "subtract":
                return x - y;
            default:
                System.out.println("Invalid operation!");
                return 0;
        }
    }

    public double calculate(double value, String operation) {
        switch (operation) {
            case "sin":
                return Math.sin(Math.toRadians(value));
            case "cos":
                return Math.cos(Math.toRadians(value));
            case "tan":
                return Math.tan(Math.toRadians(value));
            case "log":
            	if (value <= 0) {
                    System.out.println("Error: log is undefined for zero or negative values.");
                    return Double.NaN;
                }
                return Math.log(value);
            default:
                System.out.println("Invalid operation!");
                return 0.0;
        }
    }

    public int[][] calculate(int[][] x, int[][] y, String operation) {
        int rows = x.length;
        int cols = x[0].length;
        int[][] result = new int[rows][cols];

        switch (operation) {
            case "add":
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        result[i][j] = x[i][j] + y[i][j];
                    }
                }
                return result;
            case "subtract":
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        result[i][j] = x[i][j] - y[i][j];
                    }
                }
                return result;
            default:
                System.out.println("Invalid matrix operation!");
                return null;
        }
    }

    public double[][] calculate(double[][] a, double[][] b) {
        int r1 = a.length, c1 = a[0].length;
        int c2 = b[0].length;
        double[][] result = new double[r1][c2];

        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                for (int k = 0; k < c1; k++) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return result;
    }
}

public class ScientificCalculator {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Calculator calc = new Calculator();
        boolean running = true;

        while (running) {
            System.out.println("\n--- Scientific Calculator ---");
            System.out.println("1. Integer Operations");
            System.out.println("2. Double Operations");
            System.out.println("3. Integer Matrix Operations");
            System.out.println("4. Double Matrix Multiplication");
            System.out.println("0. Exit");
            System.out.print("Choose an option: ");
            int choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {
                case 1:
                    System.out.print("Enter first integer: ");
                    int x = sc.nextInt();
                    System.out.print("Enter second integer: ");
                    int y = sc.nextInt();
                    sc.nextLine();
                    System.out.print("Enter operation (add/subtract): ");
                    String op = sc.nextLine();
                    int intResult = calc.calculate(x, y, op);
                    System.out.println("Result: " + intResult);
                    break;

                case 2:
                    System.out.print("Enter value: ");
                    double value = sc.nextDouble();
                    sc.nextLine();
                    System.out.print("Enter operation (sin/cos/tan/log): ");
                    String dop = sc.nextLine();
                    double doubleResult = calc.calculate(value, dop);
                    System.out.println("Result: " + doubleResult);
                    break;

                case 3:
                    System.out.print("Enter matrix size (rows cols): ");
                    int rows = sc.nextInt();
                    int cols = sc.nextInt();
                    int[][] mat1 = new int[rows][cols];
                    int[][] mat2 = new int[rows][cols];

                    System.out.println("Enter first matrix:");
                    for (int i = 0; i < rows; i++)
                        for (int j = 0; j < cols; j++)
                            mat1[i][j] = sc.nextInt();

                    System.out.println("Enter second matrix:");
                    for (int i = 0; i < rows; i++)
                        for (int j = 0; j < cols; j++)
                            mat2[i][j] = sc.nextInt();

                    sc.nextLine();
                    System.out.print("Enter operation (add/subtract): ");
                    String mop = sc.nextLine();
                    int[][] intMatResult = calc.calculate(mat1, mat2, mop);

                    System.out.println("Result matrix:");
                    if (intMatResult != null) {
                        for (int[] row : intMatResult) {
                            for (int val : row) {
                                System.out.print(val + " ");
                            }
                            System.out.println();
                        }
                    }
                    break;

                case 4:
                    System.out.print("Enter size of first matrix (rows cols): ");
                    int r1 = sc.nextInt();
                    int c1 = sc.nextInt();
                    System.out.print("Enter size of second matrix (rows cols): ");
                    int r2 = sc.nextInt();
                    int c2 = sc.nextInt();

                    if (c1 != r2) {
                        System.out.println("Matrix multiplication not possible.");
                        break;
                    }

                    double[][] matD1 = new double[r1][c1];
                    double[][] matD2 = new double[r2][c2];

                    System.out.println("Enter first double matrix:");
                    for (int i = 0; i < r1; i++)
                        for (int j = 0; j < c1; j++)
                            matD1[i][j] = sc.nextDouble();

                    System.out.println("Enter second double matrix:");
                    for (int i = 0; i < r2; i++)
                        for (int j = 0; j < c2; j++)
                            matD2[i][j] = sc.nextDouble();

                    double[][] resultD = calc.calculate(matD1, matD2);
                    System.out.println("Result matrix:");
                    for (double[] row : resultD) {
                        for (double val : row) {
                            System.out.print(val + " ");
                        }
                        System.out.println();
                    }
                    break;

                case 0:
                    running = false;
                    System.out.println("Exiting... Thank you!");
                    break;

                default:
                    System.out.println("Invalid choice!");
                    break;
            }
        }
        sc.close();
    }
}
