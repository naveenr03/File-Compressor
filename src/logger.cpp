#include "logger.h"

// Define the static mutex
std::mutex Logger::log_mutex;

// Implement the log function
void Logger::log(const std::string& message) {
    std::lock_guard<std::mutex> lock(log_mutex);
    std::cout << "[LOG] " << message << std::endl;
}