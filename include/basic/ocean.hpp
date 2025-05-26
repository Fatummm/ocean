#ifndef OCEAN_HPP
#define OCEAN_HPP

#include "global.hpp"
#include "object.hpp"
#include "cell.hpp"
#include "sand.hpp"
#include <algae.hpp>
#include <fish.hpp>
#include <vector>
#include <memory>
#include <optional>
#include <position.hpp>


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

    template <typename T>
    std::optional<Position> findNearby(const Position&);

    void generateAlgaes();
    void generateHerbivores();
    void generatePredators();
    void update();
};

#endif