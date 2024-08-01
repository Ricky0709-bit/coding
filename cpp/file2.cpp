#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Open an existing text file for reading
    std::ifstream inputFile("input.txt");

    // Check if the file is opened successfully
    if (!inputFile.is_open()) 
    {
        std::cerr << "Error: Unable to open file for reading\n";
        return 1;
    }

    std::string line;

    // Read the file line by line and display its contents on the console
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }

    // Close the file
    inputFile.close();

    return 0;
}
