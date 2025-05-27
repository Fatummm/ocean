#ifndef LOGGER_HPP
#define LOGGER_HPP
#include <global.hpp>

#include <iostream>
#include <chrono>
#include <fstream>
template <typename T>
class Logger {
private:
public:
    static unsigned int overall;
    static unsigned int produced;
    Logger();
    void Produce();
};

template <>
class Logger<OceanImpl> {
private:
    std::ostream& out;
    std::chrono::high_resolution_clock::time_point start;
public:
    Logger(std::ostream&);

    Logger(const Logger&) = delete;
    Logger(const Logger&&) = delete;

    Logger& operator =(const Logger& other) = delete;
    Logger& operator =(const Logger&& other) = delete;

    ~Logger();
};

#endif