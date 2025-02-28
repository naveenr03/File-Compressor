// include/huffman.h
#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "compression_algorithm.h"

class Huffman : public CompressionAlgorithm {
public:
    void compress(const std::string& inputFile, const std::string& outputFile) override;
};

#endif // HUFFMAN_H