#ifndef LZ77_H
#define LZ77_H

#include "compression_algorithm.h"


class LZ77 : public CompressionAlgorithm {
public:
    void compress(const std::string& inputFile, const std::string& outputFile) override;
};

#endif // LZ77_H