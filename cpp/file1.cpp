#include <iostream>
#include <fstream>

int main() {
    // Create and open a text file
    std::ofstream outputFile("output.txt");

    // Check if the file is opened successfully
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file for writing\n";
        return 1;
    }

    // Write some text into the file
    outputFile << "This is the first line of text.\n";
    outputFile << "This is the second line of text.\n";
    outputFile << "This is the third line of text.\n";

    // Close the file
    outputFile.close();

    std::cout << "Text written to file successfully\n";

    return 0;
}
