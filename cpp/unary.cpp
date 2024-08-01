#include <iostream>

class Counter {
private:
    int value;

public:
    // Constructor to initialize the counter
    Counter(int v = 0) : value(v) {}

    // Overload the unary ++ operator (prefix)
    Counter& operator++() {
        ++value; // Increment the value
        return *this;
    }

    // Overload the unary ++ operator (postfix)
    Counter operator++(int) {
        Counter temp = *this;
        ++value; // Increment the value
        return temp; // Return the original value before increment
    }

    // Function to display the value of the counter
    void display() const {
        std::cout << "Counter value: " << value << std::endl;
    }
};

int main() {
    Counter counter(10); // Initialize the counter with 10

    std::cout << "Initial value: ";
    counter.display();

    ++counter; // Use prefix increment
    std::cout << "After prefix increment: ";
    counter.display();

    counter++; // Use postfix increment
    std::cout << "After postfix increment: ";
    counter.display();

    return 0;
}
