package javap;

class EvenThread extends Thread {
	public void run() {
		for (int i=0;i<=10;i+=2) {
			System.out.println("Even: " + i + "(Thread ID: " + Thread.currentThread().threadId() + ")");
			try {
				Thread.sleep(100);
			}
			catch (InterruptedException e) {
				System.out.println("Even thread interrupted: " + e.getMessage());
			}
		}
	}
}

class OddThread extends Thread {	
	public void run() {
		for(int i=0;i<=10;i+=2) {
			System.out.println("Odd: " + (i+1) + "(Thread ID: " + Thread.currentThread().threadId() + ")");
			try {
				Thread.sleep(100);
			}
			catch (InterruptedException e) {
				System.out.println("Odd thread interrupted: " + e.getMessage());
			}
		}
	}
}

public class EvenOdd {
	public static void main(String[] args) {
		EvenThread even = new EvenThread();
		OddThread odd = new OddThread();
		
		even.start();
		odd.start();
		
		try {
			even.join();
			odd.join();
		}
		catch (InterruptedException e) {
			System.out.println("Main thread interrupted:" + e.getMessage());
		}
	}
}
