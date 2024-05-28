#include <iostream>
#include <stdexcept> // For std::runtime_error

using namespace std;

// Function to calculate factorial
double factorial(int n) {
    if (n < 0) {
        throw invalid_argument("Factorial is not defined for negative numbers");
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    double result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int number;
    cout << "Enter a number to calculate its factorial: ";

    try {
        cin >> number;

        // Check if the input is valid
        if (cin.fail()) {
            throw invalid_argument("Invalid input. Please enter a valid integer.");
        }

        double result = factorial(number);
        cout << "Factorial of " << number << " is " << result << endl;
    } 
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
