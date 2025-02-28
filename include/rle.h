#ifndef RLE_H
#define RLE_H

#include "compression_algorithm.h"

class RLE : public CompressionAlgorithm {
public:
    void compress(const std::string& inputFile, const std::string& outputFile) override;
};

#endif // RLE_H 