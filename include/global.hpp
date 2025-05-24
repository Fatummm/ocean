#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#define ROWS 20
#define COLUMNS 20


struct Position {
    unsigned int x;
    unsigned int y;
};

// classes that will not have inheritors
class Cell;
class Object;


// classes that will have inheritors (pimpl)
class AlgaeImpl;
class FishImpl;
class HerbivoreImpl;
class OceanImpl;
class PredatorImpl;

#endif