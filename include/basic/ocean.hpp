#ifndef OCEAN_HPP
#define OCEAN_HPP

#include "global.hpp"
#include "object.hpp"
#include "cell.hpp"
#include <vector>
#include <memory>

class OceanImpl {
protected:
    unsigned int rows;
    unsigned int columns;
    std::vector<std::vector<Cell>> field;
public:
    unsigned int getRows() const;
    unsigned int getColumns() const;
    OceanImpl(unsigned int, unsigned int);
    std::vector<Cell>& operator[](unsigned int);
    void fillWithSand();
    void update();
};

#endif