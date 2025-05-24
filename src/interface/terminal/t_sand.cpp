#include <t_sand.hpp>

Sand::Sand(std::ostream& out, const Position& pos): 
    Sprite(out), pimpl(std::make_unique<SandImpl>(pos)) {}


void Sand::display() {
    std::cout << 
}