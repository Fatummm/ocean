#ifndef TERMINAL_OCEAN_HPP
#define TERMINAL_OCEAN_HPP
#include <ocean.hpp>
#include <iostream>
#include <memory>
#include <chrono>

class TOcean{
private:
    std::ostream& out;
    std::unique_ptr<OceanImpl> pimpl;
public:
    TOcean(unsigned int, unsigned int, std::ostream& = std::cout);
    TOcean(const TOcean&) = delete;
    TOcean(const TOcean&&) = delete;
    TOcean& operator =(const TOcean&) = delete;
    TOcean& operator =(const TOcean&&) = delete;
    void display();
    void displayCell(Object*);
    void start();
};

#endif