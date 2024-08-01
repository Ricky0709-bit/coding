#include <iostream>

// Class representing a number
class Number {
private:
    int value;

public:
    // Constructor
    Number(int val) : value(val) {}

    // Unary operator overloading for increment (++num)
    void operator++() {
        ++value;
    }

    // Binary operator overloading for addition (num1 + num2)
    Number operator+(const Number& other) const {
        return Number(value + other.value);
    }

    // Function to get the value of the number
    int getValue() const {
        return value;
    }
};

int main() {
    Number num1(5), num2(10);

    char choice;

    do {
        std::cout << "Menu:\n";
        std::cout << "1. Increment a number\n";
        std::cout << "2. Add two numbers\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                ++num1;
                std::cout << "Incremented number: " << num1.getValue() << std::endl;
                break;
            case '2':
                std::cout << "Sum of the two numbers: " << (num1 + num2).getValue() << std::endl;
                break;
            case '3':
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '3');

    return 0;
}
