#include <iostream>

// Class with member function template to multiply two numbers
class Multiplier {
public:
    // Member function template to multiply two numbers
    template<typename T>
    T multiply(T a, T b) {
        return a * b;
    }
};

int main() {
    char choice;

    do {
        std::cout << "Menu:\n";
        std::cout << "1. Multiply two integers\n";
        std::cout << "2. Multiply two floats\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1': {
                int num1, num2;
                std::cout << "Enter two integers: ";
                std::cin >> num1 >> num2;
                Multiplier multiplier;
                std::cout << "Product of the two integers: " << multiplier.multiply(num1, num2) << std::endl;
                break;
            }
            case '2': {
                float num1, num2;
                std::cout << "Enter two floats: ";
                std::cin >> num1 >> num2;
                Multiplier multiplier;
                std::cout << "Product of the two floats: " << multiplier.multiply(num1, num2) << std::endl;
                break;
            }
            case '3':
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '3');

    return 0;
}
