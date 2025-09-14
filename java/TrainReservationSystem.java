package javap;

class Reservation implements Runnable {
    private static int availableSeats = 100;
    private final String passengerName;

    public Reservation(String passengerName) {
        this.passengerName = passengerName;
    }

    private static synchronized void bookSeat(String passengerName) {
        if (availableSeats > 0) {
            System.out.println(passengerName + " has booked a seat.\nRemaining seats: " + --availableSeats);
        } else {
            System.out.println("No seats available for " + passengerName);
        }
    }

    @Override
    public void run() {
        try {
            Thread.sleep(100);
        } catch (InterruptedException e) {
            System.out.println("Thread interrupted: " + e.getMessage());
        }
        bookSeat(passengerName);
    }
}

public class TrainReservationSystem {
    public static void main(String[] args) {
        Thread passenger1 = new Thread(new Reservation("Ritesh"));
        Thread passenger2 = new Thread(new Reservation("Hitesh"));
        Thread passenger3 = new Thread(new Reservation("Manthan"));


        try {
        	passenger1.start();
        	passenger1.join();
            passenger2.start();
            passenger2.join();
            passenger3.start();
            passenger3.join();
        } catch (InterruptedException e) {
            System.out.println("Thread interrupted: " + e.getMessage());
        }

        System.out.println("Reservation process completed.");
    }
}
