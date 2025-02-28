#include "rle.h"
#include <iostream>
#include <fstream>
#include <string>

void RLE::compress(const std::string& inputFile, const std::string& outputFile) {
    std::cout << "Compressing " << inputFile << " using Run-Length Encoding to " << outputFile << std::endl;

    std::ifstream inFile(inputFile);
    if (!inFile) {
        std::cerr << "Error: Could not open input file " << inputFile << std::endl;
        return;
    }

    std::string encodedString;
    char currentChar;
    int count;

    while (inFile.get(currentChar)) {
        count = 1;
        while (inFile.peek() == currentChar) {
            count++;
            inFile.get(); // Consume the same character
        }
        encodedString += currentChar + std::to_string(count);
    }
    inFile.close();

    std::ofstream outFile(outputFile);
    if (outFile.is_open()) {
        outFile << encodedString;
        outFile.close();
        std::cout << "Output written to " << outputFile << std::endl;
    } else {
        std::cerr << "Error: Could not open output file " << outputFile << std::endl;
    }
}