#ifndef T_SAND_HPP
#define T_SAND_HPP

#include <sand.hpp>
#include <memory>
#include <t_sprite.hpp>

class Sand: public Sprite {
private:
    std::unique_ptr<SandImpl> pimpl;
public:
    Sand(std::ostream&, const Position&);
    void display();
};

#endif