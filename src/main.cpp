#include <iostream>
#include <thread>
#include <vector>
#include <memory> // For std::unique_ptr
#include "compression_algorithm.h"
#include "huffman.h"
#include "lz77.h"
#include "rle.h"

// Function to compress a file using the specified algorithm
void compressFile(const std::string& inputFile, const std::string& outputFile, CompressionAlgorithm* algorithm) {
    try {
        algorithm->compress(inputFile, outputFile);
        std::cout << "Compression completed: " << inputFile << " -> " << outputFile << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error compressing " << inputFile << ": " << e.what() << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <algorithm> <input_file> <output_file>" << std::endl;
        return 1;
    }

    std::string algorithmType = argv[1];
    std::string inputFile = argv[2];
    std::string outputFile = argv[3];

    // Use std::unique_ptr for automatic memory management
    std::unique_ptr<CompressionAlgorithm> algorithm;

    // Select the compression algorithm
    if (algorithmType == "huffman") {
        algorithm = std::make_unique<Huffman>();
    } else if (algorithmType == "lz77") {
        algorithm = std::make_unique<LZ77>();
    } else if (algorithmType == "rle") {
        algorithm = std::make_unique<RLE>();
    } else {
        std::cerr << "Unknown algorithm: " << algorithmType << std::endl;
        return 1;
    }

    // Create a thread to compress the file
    std::thread compressionThread(compressFile, inputFile, outputFile, algorithm.get());

    // Wait for the thread to finish
    compressionThread.join();

    // No need to manually delete the algorithm; std::unique_ptr handles it
    return 0;
}