#include <iostream>
#include <thread>
#include <vector>
#include "huffman.h"
#include "lz77.h"

void compressFile(const std::string& inputFile, const std::string& outputFile, CompressionAlgorithm* algorithm) {
    algorithm->compress(inputFile, outputFile);
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <algorithm> <input_file> <output_file>" << std::endl;
        return 1;
    }

    std::string algorithmType = argv[1];
    std::string inputFile = argv[2];
    std::string outputFile = argv[3];

    CompressionAlgorithm* algorithm = nullptr;

    if (algorithmType == "huffman") {
        algorithm = new Huffman();
    } else if (algorithmType == "lz77") {
        algorithm = new LZ77();
    } else {
        std::cerr << "Unknown algorithm: " << algorithmType << std::endl;
        return 1;
    }

    std::thread compressionThread(compressFile, inputFile, outputFile, algorithm);
    compressionThread.join();

    delete algorithm;
    return 0;
}