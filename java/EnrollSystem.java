package javap;

class Course {
	private static int idCounter = 100;
    private int CourseID;
    private String CourseName;
    private int CourseDuration_month;
    private double CourseFee;
    
    public Course() {
    	this.CourseID = idCounter++;
    	this.CourseName = "DBMS";
    	this.CourseDuration_month = 6;
    	this.CourseFee = 15000.0;
    }
    
    public Course(String CourseName, int CourseDuration_month, double CourseFee) {
        this.CourseID = idCounter++;
		this.CourseName = CourseName;
		this.CourseDuration_month = CourseDuration_month;
		this.CourseFee = CourseFee;
    }
    
    public void displayCourseDetails() {
    	System.out.println("Course ID: " + CourseID);
		System.out.println("Course Name: " + CourseName);
		System.out.println("Course Duration (months): " + CourseDuration_month);
		System.out.println("Course Fee: Rs. " + CourseFee);
    }
}
public class EnrollSystem {
	public static void main(String[] args) {
		Course c1 = new Course();
		Course c2 = new Course("Java Programming", 12, 25000.0);
		Course c3 = new Course("DevOps", 8, 20000.0);
		
		System.out.println("\nCourse 1 Details:\n ");
		c1.displayCourseDetails();
		
		System.out.println("\nCourse 2 Details:\n ");
		c2.displayCourseDetails();
		
		System.out.println("\nCourse 3 Details:\n ");
		c3.displayCourseDetails();
	}

}
