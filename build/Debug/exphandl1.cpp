#include <iostream>
using namespace std;

// Function to divide two numbers
double divide(double numerator, double denominator) {
    if (denominator == 0) {
        throw runtime_error("Division by zero error");
    }
    return numerator / denominator;
}

int main() {
    double num1, num2;
    cout << "Enter two numbers to divide (numerator and denominator): ";

    try {
        cin >> num1 >> num2;

        // Check if the input is valid
        if (cin.fail()) 
        {
            throw invalid_argument("Invalid input. Please enter valid numbers.");
        }

        double result = divide(num1, num2);
        cout << "Result: " << result << endl;
    } 
    catch (const runtime_error& e) 
    {
        cout << "Error: " << e.what() << endl;
    } 
    catch (const invalid_argument& e) 
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
