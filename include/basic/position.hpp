#ifndef POSITION_HPP
#define POSITION_HPP

struct Position {
    unsigned int x;
    unsigned int y;
};

int distance(const Position& lhs, const Position& rhs);
bool operator == (const Position& lhs, const Position& rhs);

#endif