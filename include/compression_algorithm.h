// include/compression_algorithm.h
#ifndef COMPRESSION_ALGORITHM_H
#define COMPRESSION_ALGORITHM_H

#include <string>

class CompressionAlgorithm {
public:
    virtual void compress(const std::string& inputFile, const std::string& outputFile) = 0;
    virtual ~CompressionAlgorithm() = default;
};

#endif // COMPRESSION_ALGORITHM_H