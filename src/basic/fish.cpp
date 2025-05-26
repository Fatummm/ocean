#include "fish.hpp"

template <typename Food>
Fish<Food>::Fish(const Position& pos, unsigned int sat, unsigned int lives, OceanImpl* oc): 
    Object(pos), saturation(sat), lives_left(lives),
    destination(Position{static_cast<unsigned>(rand() % ROWS), static_cast<unsigned>(rand() % COLUMNS)}), ocean(oc) {}

template <typename Food>
void Fish<Food>::travel() {
    Position last = destination;
    (*ocean)[position.x][position.y].switchOn();
    // eat
    if (abs(destination.x - position.x) <= 1 && abs(destination.x - position.x) <= 1 && 
        dynamic_cast<Food*>((*ocean)[destination.x][destination.y].get())) {
        (*ocean)[destination.x][destination.y].destroyObject();
        (*ocean)[destination.x][destination.y].insert(this);
        (*ocean)[position.x][position.y].forgetObject();
        position = destination;
        saturation += 5;
        return;
    } 

    // reproduce
    if (abs(destination.x - position.x) <= 1 && abs(destination.x - position.x) <= 1 && 
        dynamic_cast<type*>((*ocean)[destination.x][destination.y].get())) {
        if (std::optional<Position> pos = findEmptyCell(); pos) {
            (*ocean)[pos->x][pos->y].insert(new type(Position{pos->x, pos->y}, 
            (dynamic_cast<Herbivore*>(this)) ? HERBIVORE_SATURATION : PREDATOR_SATURATION, 
            (dynamic_cast<Herbivore*>(this)) ? HERBIVORE_AGE : PREDATOR_AGE, ocean));
        }
        lg.Produce();
        return;
    } 

    if (destination.x > position.x && (*ocean)[position.x + 1][position.y].isEmpty()) {
        (*ocean)[position.x+1][position.y].insert(this);
        (*ocean)[position.x][position.y].forgetObject();
        ++position.x;
    }
    else if (destination.x < position.x && (*ocean)[position.x - 1][position.y].isEmpty()) {
        (*ocean)[position.x-1][position.y].insert(this);
        (*ocean)[position.x][position.y].forgetObject();
        --position.x;
    }
    
    if (destination.y > position.y && (*ocean)[position.x][position.y+1].isEmpty()) {
        (*ocean)[position.x][position.y+1].insert(this);
        (*ocean)[position.x][position.y].forgetObject();
        ++position.y;

    }
    else if (destination.y < position.y && (*ocean)[position.x][position.y-1].isEmpty()) {
        (*ocean)[position.x][position.y-1].insert(this);
        (*ocean)[position.x][position.y].forgetObject();
        --position.y;
    }
    if (destination == position) {
        destination = Position{static_cast<unsigned int>(rand() % ROWS), static_cast<unsigned int>(rand() % COLUMNS)};
        travel();
    }
    starve();
    age();
    (*ocean)[position.x][position.y].switchOn();
    
}

template <typename Food>
void Fish<Food>::starve() {
    if (saturation != 0) --saturation;
}

template <typename Food>
void Fish<Food>::findPartner() {
    Position tmp = destination;
    for (unsigned int i = 0; i != ROWS; ++i) {
        for (unsigned int j = 0; j != COLUMNS; ++j) {
            if (dynamic_cast<type*>((*ocean)[i][j].get())) {
                if (distance(destination, position) > distance(position, Position{i, j})) 
                destination = Position{i, j};
            }
        }
    }
    if (tmp == destination && !dynamic_cast<type*>((*ocean)[tmp.x][tmp.y].get())) 
    findFood();
}

template <typename Food>
void Fish<Food>::findFood() {
    Position tmp = destination;
    for (unsigned int i = 0; i != ROWS; ++i) {
        for (unsigned int j = 0; j != COLUMNS; ++j) {
            if (dynamic_cast<Food*>((*ocean)[i][j].get())) {
                if (distance(destination, position) > distance(position, Position{i, j})) 
                destination = Position{i, j};
            }
        }
    }
    if (tmp == destination && !dynamic_cast<Food*>((*ocean)[tmp.x][tmp.y].get())) 
    destination = Position{static_cast<unsigned>(rand() % ROWS), static_cast<unsigned>(rand() % COLUMNS)};
}

template <typename Food>
void Fish<Food>::findAim() {
    if (saturation >= SATURATION_TO_REPRODUCE && lives_left >= AGE_TO_REPRODUCE) {
        findPartner();
    } else {
        findFood();
    }
}

template <typename Food>
void Fish<Food>::age() {
    if (lives_left != 0) --lives_left;
}


template <typename Food>    
bool Fish<Food>::update() {
    findAim();
    travel();
    starve();
    age();
    return isAlive();
}

template <typename Food>
void Fish<Food>::eat(const Position& pos) {
    (*ocean)[pos.x][pos.y].destroyObject();
    (*ocean)[pos.x][pos.y].insert(this);
    (*ocean)[position.x][position.y].forgetObject();
    ++saturation;
    position = pos;
}

template <typename Food>
bool Fish<Food>::isAlive() {
    return lives_left > 0 && saturation > 0;
}

template <typename Food>
std::optional<Position> Fish<Food>::findEmptyCell() {
    unsigned int start_x = (position.x >= 1) ? position.x - 1: position.x;
    unsigned int start_y = (position.y >= 1) ? position.y - 1: position.y;
    unsigned int end_x = (position.x + 2 <= (*ocean).getRows()) ? position.x + 2 : position.x + 1;
    unsigned int end_y = (position.y + 2 <= (*ocean).getColumns()) ? position.y + 2 : position.y + 1;
    for (unsigned int i = start_x; i != end_x; ++i) {
        for (unsigned int j = start_y; j != end_y; ++j) {
            if (i == position.x && j == position.y) continue;
            if ((*ocean)[i][j].isEmpty()) return Position{i, j};
        }
    }
    return {};
}

OceanImpl impl(2, 2);
Herbivore h(Position{0, 3}, 2, 2, &impl);
Predator p(Position{0, 3}, 2, 2, &impl);
