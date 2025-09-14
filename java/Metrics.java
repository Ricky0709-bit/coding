package javap;

import java.util.Scanner;

class Circle{
	double radius;
	Circle(double radius){
		this.radius = radius;
	}
	
	double calculateArea() {
		return Math.PI * radius * radius;
	}
	                                                                                                             
	double calculatePerimeter() {
		return 2 * Math.PI * radius;
	}	
}

public class Metrics {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the radius of circle: ");
		double radius = sc.nextDouble();
		Circle cir = new Circle(radius);
		System.out.println("Area of circle: " + cir.calculateArea());
		System.out.println("Perimeter of circle: " + cir.calculatePerimeter());
		sc.close();
	}
}
