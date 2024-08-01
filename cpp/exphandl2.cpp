#include <iostream>

using namespace std;

// Function to divide two numbers
double divide(double numerator, double denominator) {
    if (denominator == 0) {
        throw runtime_error("Error: Division by zero is not allowed.");
    }
    return numerator / denominator;
}

int main() {
    double num, denom;

    cout << "Enter the numerator: ";
    cin >> num;

    cout << "Enter the denominator: ";
    cin >> denom;

    try {
        double result = divide(num, denom);
        cout << "Result: " << result << endl;
    } 
    catch (const runtime_error& e) 
    {
        cerr << e.what() << endl;
    }

    return 0;
}
