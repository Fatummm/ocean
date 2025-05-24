#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#define SECONDS_DELTA 1
#define MILLISECONDS_DELTA 500
#define ROWS 20
#define COLUMNS 20
#define ALGAE_PROBS 100
#define MAX_SATURATION 10
#define MAX_AGE 20
#define HERBIVORE_PROBS 1000
#define PREDATOR_PROBS 10000

struct Position {
    unsigned int x;
    unsigned int y;
};

int distance(const Position& lhs, const Position& rhs);

bool operator == (const Position& lhs, const Position& rhs);

// classes that will not have inheritors
class Cell;
class Object;


// classes that will have inheritors (pimpl)
class AlgaeImpl;

template <typename Food>
class FishImpl;

class OceanImpl;
class SandImpl;

#endif