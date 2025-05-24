#ifndef FISH_HPP
#define FISH_HPP

#include "global.hpp"
#include "object.hpp"
class FishImpl: public Object{
private:
    Position destination;
    unsigned int saturation;
    unsigned int lives_left;
public:
    FishImpl(unsigned int, unsigned int);
    void moveTo(const Position&);
    void travel();
    void starve();
    void eat();
    void update();

    virtual void display() = 0;
    virtual ~FishImpl() = default;
};

#endif