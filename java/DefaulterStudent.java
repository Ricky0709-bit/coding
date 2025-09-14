package javap;

public class DefaulterStudent {
    public static void checkAttendance(double attendance) throws AttendanceException {
        if (attendance < 75) {
            throw new AttendanceException("Attendance below 75%");
        } else {
            System.out.println("Attendance is sufficient");
        }
    }
    
    public static void main(String[] args) {
		double attendance = 74.99;

		try {
			DefaulterStudent.checkAttendance(attendance);
		} catch (AttendanceException e) {
			System.out.println("Caught Exception: " + e.getMessage());
		}
	}
}

class AttendanceException extends Exception {
	public AttendanceException(String message) {
		super(message);
	}
}