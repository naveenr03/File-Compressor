#include <iostream>
#include <fstream>
#include <string>

class Logger {
public:
    static void log(const std::string& message) {
        std::cout << message << std::endl;
        // Optionally log to a file
    }
};