#include <position.hpp>

int distance(const Position& lhs, const Position& rhs) {
    return (lhs.x - rhs.x)*(lhs.x - rhs.x) + (lhs.y - rhs.y)*(lhs.y - rhs.y);
}

bool operator == (const Position& lhs, const Position& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}