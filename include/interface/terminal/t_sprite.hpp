#ifndef T_SPRITE_HPP 
#define T_SPRITE_HPP

#include <iostream>

class Sprite {
protected:
    std::ostream& out;
public:
    Sprite(std::ostream&);
};

#endif