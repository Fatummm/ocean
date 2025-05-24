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

void OceanImpl::fillWithSand() {
    for (unsigned int i = 0; i != getRows(); ++i) {
        for (unsigned int j = 0; j != getColumns(); ++j) {
            if (j == 0 || j + 1 == getColumns() || i + 1 == getRows()) {
                field[i][j].insert(new SandImpl(Position{i, j}));
            }
        }
    }
}

template <typename T>
std::optional<Position> OceanImpl::findNearby(const Position& pos) {
    unsigned int start_x = (pos.x >= 1) ? pos.x - 1: pos.x;
    unsigned int start_y = (pos.y >= 1) ? pos.y - 1: pos.y;
    unsigned int end_x = (pos.x + 2 <= getRows()) ? pos.x + 2 : pos.x + 1;
    unsigned int end_y = (pos.y + 2 <= getColumns()) ? pos.y + 2 : pos.y + 1;
    for (unsigned int i = start_x; i != end_x; ++i) {
        for (unsigned int j = start_y; j != end_y; ++j) {
            if (i == pos.x && j == pos.y) continue;
            if (dynamic_cast<T*>(field[i][j].get())) return Position{i, j};
        }
    }
    return {};
}

void OceanImpl::generateAlgaes() {
    for (unsigned int i = 0; i != getRows(); ++i) {
        for (unsigned int j = 0; j != getColumns(); ++j) {
            if (field[i][j].isEmpty() && findNearby<SandImpl>(Position{i, j}) && rand() % ALGAE_PROBS == 0) {
                field[i][j].insert(new AlgaeImpl(Position{i, j}));
            }
        }
    }
}

void OceanImpl::generateHerbivores() {
    for (unsigned int i = 0; i != getRows(); ++i) {
        for (unsigned int j = 0; j != getColumns(); ++j) {
            if (field[i][j].isEmpty() && rand() % HERBIVORE_PROBS == 0) {
                field[i][j].insert(new Herbivore(Position{i,j}, MAX_SATURATION, MAX_AGE, this));
                //std::cout << "Yes";
                //field[i][j].insert(new AlgaeImpl(Position{i, j}));
            }
        }
    }
}

void OceanImpl::update() {
    generateAlgaes();
    generateHerbivores();
    for (unsigned int i = 0; i != getRows(); ++i) {
        for (unsigned int j = 0; j != getColumns(); ++j) {
            if (!field[i][j].isEmpty() && !field[i][j].isSwitched() && dynamic_cast<Herbivore*>(field[i][j].get())) {
                Herbivore* h = dynamic_cast<Herbivore*>(field[i][j].get());
                if (!h->update()) {
                    field[i][j].destroyObject();
                    continue;
                }
                if (std::optional<Position> pos = findNearby<AlgaeImpl>(Position{i, j}); pos) {
                    field[pos->x][pos->y].destroyObject();
                    field[pos->x][pos->y].insert(field[i][j].get());
                    field[i][j].forgetObject();
                }
            }
        }
    }

    for (unsigned int i = 0; i != getRows(); ++i) {
        for (unsigned int j = 0; j != getColumns(); ++j) {
            field[i][j].reset();
        }
    }
}
