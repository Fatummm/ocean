#ifndef OBJECT_HPP
#define OBJECT_HPP
#include "global.hpp"

class Object {
private:
    Position position;
public:
    Object(const Position&);
    virtual void display() = 0;
    virtual ~Object() = default;
};

#endif