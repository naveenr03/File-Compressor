#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iostream>
#include <mutex>

class Logger {
public:
    static void log(const std::string& message);

private:
    static std::mutex log_mutex;
};

#endif // LOGGER_H