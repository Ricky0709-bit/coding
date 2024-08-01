#include <iostream>

// Class template to find maximum of two numbers
template<typename T>
class MaxFinder {
private:
    T num1;
    T num2;

public:
    MaxFinder(T a, T b) : num1(a), num2(b) {}

    T maximum() const {
        return (num1 > num2) ? num1 : num2;
    }
};

// Class template to find minimum of two numbers
template<typename T>
class MinFinder {
private:
    T num1;
    T num2;

public:
    MinFinder(T a, T b) : num1(a), num2(b) {}

    T minimum() const {
        return (num1 < num2) ? num1 : num2;
    }
};

int main() {
    char choice;

    do {
        std::cout << "Menu:\n";
        std::cout << "1. Find maximum of two numbers\n";
        std::cout << "2. Find minimum of two numbers\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1': {
                int num1, num2;
                std::cout << "Enter two numbers: ";
                std::cin >> num1 >> num2;
                MaxFinder<int> maxFinder(num1, num2);
                std::cout << "Maximum of the two numbers: " << maxFinder.maximum() << std::endl;
                break;
            }
            case '2': {
                float num1, num2;
                std::cout << "Enter two numbers: ";
                std::cin >> num1 >> num2;
                MinFinder<float> minFinder(num1, num2);
                std::cout << "Minimum of the two numbers: " << minFinder.minimum() << std::endl;
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
