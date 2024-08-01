#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Open the text file for reading
    std::ifstream inputFile("extra.txt");

    // Check if the file is opened successfully
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open file for reading\n";
        return 1;
    }

    std::string line;
    int lineCount = 0;

    // Read the file line by line and count the number of lines
    while (std::getline(inputFile, line)) {
        ++lineCount;
    }

    // Close the file
    inputFile.close();

    // Display the number of lines
    std::cout << "The number of lines in the file: " << lineCount << std::endl;

    return 0;
}
