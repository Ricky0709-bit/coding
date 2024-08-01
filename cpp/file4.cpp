#include <iostream>
#include <fstream>
#include <string>

// Define a structure for Employee information
struct Employee {
    int empId;
    std::string name;
    double salary;
};

int main() {
    // Open the input file for reading
    std::ifstream inputFile("employee_input.txt");

    // Check if the input file is opened successfully
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open input file for reading\n";
        return 1;
    }

    // Open the output file for writing
    std::ofstream outputFile("employee_output.txt");

    // Check if the output file is opened successfully
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open output file for writing\n";
        inputFile.close(); // Close the input file before returning
        return 1;
    }

    Employee employee;

    // Read employee information from the input file and write to the output file
    while (inputFile >> employee.empId >> employee.name >> employee.salary) {
        outputFile << "Emp ID: " << employee.empId << "\n";
        outputFile << "Name: " << employee.name << "\n";
        outputFile << "Salary: " << employee.salary << "\n\n";
    }

    // Close both input and output files
    inputFile.close();
    outputFile.close();

    std::cout << "Employee information has been read from the input file and stored in the output file successfully.\n";

    return 0;
}
