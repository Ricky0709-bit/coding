#include <iostream>
#include <stdexcept>

using namespace std;

// Function to check if a number is even or odd
void checkEven(int number) {
    if (number % 2 != 0) {
        throw runtime_error("The number is odd.");
    } else {
        cout << "The number is even." << endl;
    }
}

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    try {
        checkEven(num);
    } catch (const runtime_error& e) {
        cerr << "Exception caught: " << e.what() << endl;
    }

    return 0;
}
