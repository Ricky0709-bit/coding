package javap;

import java.util.Scanner;

interface ControllableDevice {
    void powerOn();
    void powerOff();
    void statusReport();
}

interface InternetEnabled {
    void connectWifi();
}

class SmartTV implements ControllableDevice, InternetEnabled {
    @Override
    public void powerOn() {
        System.out.println("Smart TV powered on.");
    }

    @Override
    public void powerOff() {
        System.out.println("Smart TV powered off.");
    }

    @Override
    public void statusReport() {
        System.out.println("Smart TV status: Online.");
    }

    @Override
    public void connectWifi() {
        System.out.println("Smart TV connected to WiFi.");
    }
}

class SmartFridge implements ControllableDevice, InternetEnabled {
    @Override
    public void powerOn() {
        System.out.println("Smart Fridge is powered on.");
    }

    @Override
    public void powerOff() {
        System.out.println("Smart Fridge is powered off.");
    }

    @Override
    public void statusReport() {
        System.out.println("Smart Fridge status: Cooling.");
    }

    @Override
    public void connectWifi() {
        System.out.println("Smart Fridge is connected to WiFi.");
    }
}

class SmartAC implements ControllableDevice {
    @Override
    public void powerOn() {
        System.out.println("Smart AC is powered on.");
    }

    @Override
    public void powerOff() {
        System.out.println("Smart AC is powered off.");
    }

    @Override
    public void statusReport() {
        System.out.println("Smart AC status: Running.");
    }
}

public class SmartDeviceInterfaceSystem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        ControllableDevice tv = new SmartTV();
        ControllableDevice fridge = new SmartFridge();
        ControllableDevice ac = new SmartAC();

        while (true) {
            System.out.println("\n--- Smart Device Menu ---");
            System.out.println("1. Smart TV");
            System.out.println("2. Smart Fridge");
            System.out.println("3. Smart AC");
            System.out.println("4. Exit");
            System.out.print("Choose a device: ");
            int deviceChoice = sc.nextInt();

            if (deviceChoice == 4) {
                System.out.println("Exiting...");
                break;
            }

            ControllableDevice device = null;

            switch (deviceChoice) {
                case 1: device = tv; break;
                case 2: device = fridge; break;
                case 3: device = ac; break;
                default:
                    System.out.println("Invalid device choice!");
                    continue;
            }

            System.out.println("\n--- Operations ---");
            System.out.println("1. Power On");
            System.out.println("2. Power Off");
            System.out.println("3. Status Report");
            System.out.println("4. Connect to WiFi (if available)");
            System.out.print("Choose an operation: ");
            int opChoice = sc.nextInt();

            switch (opChoice) {
                case 1: device.powerOn(); break;
                case 2: device.powerOff(); break;
                case 3: device.statusReport(); break;
                case 4:
                    if (device instanceof InternetEnabled) {
                        ((InternetEnabled) device).connectWifi();
                    } else {
                        System.out.println("This device does not support WiFi.");
                    }
                    break;
                default:
                    System.out.println("Invalid operation!");
            }
        }

        sc.close();
    }
}
