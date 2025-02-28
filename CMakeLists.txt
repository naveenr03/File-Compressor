cmake_minimum_required(VERSION 3.10)    
project(MultiThreadedCompressor)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

# Explicitly list all source files
add_executable(MultiThreadedCompressor 
    src/compressor.cpp 
    src/huffman.cpp 
    src/lz77.cpp 
    src/rle.cpp  # Ensure this is included
    src/main.cpp 
    src/utils.cpp
    src/logger.cpp)
    