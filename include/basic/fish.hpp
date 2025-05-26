#ifndef FISH_HPP
#define FISH_HPP

#include "global.hpp"
#include "object.hpp"
#include <ocean.hpp>
#include <logger.hpp>
#include <position.hpp>
template <typename Food>
class Fish: public Object{
public:
    using type = Fish<Food>;

protected:
    Logger<type> lg;
    Position destination;
    unsigned int saturation;
    unsigned int lives_left;
    OceanImpl* ocean;
public:

    Fish(const Position&, unsigned int, unsigned int, OceanImpl*);
    void travel();
    void eat(const Position&);
    std::optional<Position> findEmptyCell();
    void findPartner();
    void findFood();
    void findAim();
    void starve();
    void age();
    bool update();
    bool isAlive();
};

#endif