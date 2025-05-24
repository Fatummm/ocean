#ifndef FISH_HPP
#define FISH_HPP

#include "global.hpp"
#include "object.hpp"
#include <ocean.hpp>

template <typename Food>
class FishImpl: public Object{
protected:
    Position destination;
    unsigned int saturation;
    unsigned int lives_left;
    OceanImpl* ocean;
public:

    using type = FishImpl<Food>;

    FishImpl(const Position&, unsigned int, unsigned int, OceanImpl*);
    void travel();
    void eat(const Position&);
    void findPartner();
    void findFood();
    void findAim();
    void starve();
    void age();
    bool update();
    bool isAlive();
};

using Herbivore = FishImpl<AlgaeImpl>;
using Predator = FishImpl<Herbivore>;

#endif