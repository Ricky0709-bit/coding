#include <iostream>
#include <fstream>

int main() {
    std::ifstream inputFile("input.txt");   // Open input file for reading
    std::ofstream outputFile("output.txt"); // Open output file for writing

    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open input file\n";
        return 1;
    }

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open output file\n";
        return 1;
    }

    char ch;

    // Read character by character from input file and write to output file
    while (inputFile.get(ch)) {
        outputFile.put(ch);
    }

    std::cout << "File copied successfully\n";

    // Close both input and output files
    inputFile.close();
    outputFile.close();

    return 0;
}
