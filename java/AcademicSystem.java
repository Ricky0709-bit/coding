package javap;

class Person{
	String name;
	int id;
	
	Person(String name, int id){
		this.name = name;
		this.id = id;
	}
	
	void display() {
		System.out.println("\nName:" +name +"\nID:"+id);
	}
}

class Student extends Person{
	String course;
	
	Student(String name, int id, String course){
		super(name,id);
		this.course = course;
	}
	
	void enroll() {
		System.out.println(name+ " has enrolled in " +course);
	}
	
	void display() {
		super.display();
		System.out.println("Role: Student, Course: "+course);
	}
}

class Faculty extends Person{
	String subject;
	
	Faculty(String name, int id, String subject){
		super(name,id);
		this.subject = subject;
	}
	
	void grades(Student student, String grade) {
		System.out.println("Faculty "+name+ " graded student "+ student.name +" with "+grade );
	}
	
	void display() {
		super.display();
		System.out.println("Role: Faculty, Subject:"+subject);
	}
}

class Admin extends Person {
	String department;
	
	Admin(String name, int id, String department){
		super(name, id);
		this.department = department;
	}
	
	void records() {
		System.out.println("Admin Staff "+name+" manages records for department "+department);
	}
	
	void display() {
		super.display();
		System.out.println("Role: Admin Staff, Department: "+department);
	}
}
public class AcademicSystem {
	public static void main(String[] args) {
		Person p1 = new Student("Ritesh", 105,"IT");
		Person p2 = new Faculty("S. Adhav", 303,"DAA");
		Person p3 = new Admin("Shivani", 409, "IT ");
		
		p1.display();
		((Student)p1).enroll();

	    System.out.println();

	    p2.display();
	    ((Faculty)p2).grades((Student)p1, "A+");

	    System.out.println();

	    p3.display();
	    ((Admin)p3).records();
	}

}
