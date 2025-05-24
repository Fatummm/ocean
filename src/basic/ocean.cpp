#include <ocean.hpp>

unsigned int OceanImpl::getRows() const {
    return rows;
}

unsigned int OceanImpl::getColumns() const {
    return columns;
}

OceanImpl::OceanImpl(unsigned int row, unsigned int column): 
    rows(row), columns(column), field(row, std::vector<Cell>(column)) {}

std::vector<Cell>& OceanImpl::operator[] (unsigned int row) {
    return field[row];
}

void OceanImpl::update() {

}
