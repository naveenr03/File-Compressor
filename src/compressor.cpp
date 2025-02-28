#include "compressor.h"
#include "huffman.h"
#include "logger.h"
#include <iostream>
#include <fstream>
#include "logger.h"

void Compressor::compress(const std::string& inputFile, const std::string& outputFile) {
    Logger::log("Starting compression...");

    // Use Huffman encoding to compress the file
    Huffman huffman;
    huffman.compress(inputFile, outputFile);

    Logger::log("Compression completed.");
}