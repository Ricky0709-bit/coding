#include <iostream>

using namespace std;

// Function template to find the maximum of two numbers
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

// Function template to find the minimum of two numbers
template <typename T>
T findMin(T a, T b) {
    return (a < b) ? a : b;
}

int main() {
    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Find maximum of two numbers\n";
        cout << "2. Find minimum of two numbers\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2) {
            cout << "Enter two numbers: ";
            double num1, num2;
            cin >> num1 >> num2;

            if (choice == 1) {
                cout << "Maximum: " << findMax(num1, num2) << endl;
            } else if (choice == 2) {
                cout << "Minimum: " << findMin(num1, num2) << endl;
            }
        }
    } while (choice != 3);

    return 0;
}
