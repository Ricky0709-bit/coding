#include <iostream>

// Function to add three integers
int Adder(int a, int b, int c) {
    return a + b + c;
}

// Function to add two floats
float Adder(float a, float b) {
    return a + b;
}

int main() {
    char choice;
    
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add three integers\n";
        std::cout << "2. Add two floats\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case '1': {
                int num1, num2, num3;
                std::cout << "Enter three integers: ";
                std::cin >> num1 >> num2 >> num3;
                std::cout << "Sum of three integers: " << Adder(num1, num2, num3) << std::endl;
                break;
            }
            case '2': {
                float num1, num2;
                std::cout << "Enter two floats: ";
                std::cin >> num1 >> num2;
                std::cout << "Sum of two floats: " << Adder(num1, num2) << std::endl;
                break;
            }
            case '3':
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != '3');

    return 0;
}
