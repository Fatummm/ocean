#ifndef OBJECT_HPP
#define OBJECT_HPP
#include "global.hpp"
#include <iostream>
#include <position.hpp>
class Object {
protected:
    Position position;
public:
    Object(const Position&);
    virtual bool update();
    virtual ~Object() = default;
};

#endif