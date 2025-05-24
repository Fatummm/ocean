#include <t_ocean.hpp>

Ocean::Ocean(std::ostream& out, unsigned int rows, unsigned int columns): 
    Sprite(out), pimpl(std::make_unique<OceanImpl>(rows, columns)) {}

void Ocean::display() {
    for (unsigned int i = 0; i != pimpl->getRows(); ++i) {
        for (unsigned int j = 0; j != pimpl->getColumns() + 2; ++j) {
            if (i == 0 || i + 1 == pimpl->getRows()) {
                out << "-----";
                continue;
            }
            out << '|';
            if (!(*pimpl)[i][j].isEmpty()) (*pimpl)[i][j].get()->display();
            else displayEmptyCell();
            out << '|';
        }
        out << '\n';
    }
}

void Ocean::displayEmptyCell() {
    out << "   ";
}