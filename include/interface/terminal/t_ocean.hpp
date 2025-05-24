#ifndef T_OCEAN_HPP
#define T_OCEAN_HPP
#include <ocean.hpp>
#include <iostream>
#include <memory>
#include <t_sprite.hpp>

class Ocean: public Sprite {
private:
    std::unique_ptr<OceanImpl> pimpl;
public:
    Ocean(std::ostream&, unsigned int, unsigned int);
    void display();
    void displayEmptyCell();
};

void displayEmptyCell();

#endif