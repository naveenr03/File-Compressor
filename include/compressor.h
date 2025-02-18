// include/compressor.h
#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include <string>

class CompressionAlgorithm {
public:
    virtual void compress(const std::string& inputFile, const std::string& outputFile) = 0;
    virtual ~CompressionAlgorithm() {}
};

#endif // COMPRESSOR_H