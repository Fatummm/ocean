#ifndef TERMINAL_OCEAN_HPP
#define TERMINAL_OCEAN_HPP
#include <ocean.hpp>
#include <iostream>
#include <memory>
#include <chrono>

class Ocean{
private:
    std::ostream& out;
    std::unique_ptr<OceanImpl> pimpl;
public:
    Ocean(std::ostream&, unsigned int, unsigned int);
    Ocean(const Ocean&) = delete;
    Ocean(const Ocean&&) = delete;
    Ocean& operator =(const Ocean&) = delete;
    Ocean& operator =(const Ocean&&) = delete;
    void display();
    void displayCell(Object*);
    void start();
};

#endif