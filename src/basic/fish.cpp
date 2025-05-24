#include "fish.hpp"

template <typename Food>
FishImpl<Food>::FishImpl(const Position& pos, unsigned int sat, unsigned int lives, OceanImpl* oc): 
    Object(pos), saturation(sat), lives_left(lives),
    destination(Position{static_cast<unsigned>(rand() % ROWS), static_cast<unsigned>(rand() % COLUMNS)}), ocean(oc) {}

template <typename Food>
void FishImpl<Food>::travel() {
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
}

template <typename Food>
void FishImpl<Food>::starve() {
    if (saturation != 0) --saturation;
}

template <typename Food>
void FishImpl<Food>::findPartner() {
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
    destination = Position{static_cast<unsigned>(rand() % ROWS), static_cast<unsigned>(rand() % COLUMNS)};
}

template <typename Food>
void FishImpl<Food>::findFood() {
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
void FishImpl<Food>::findAim() {
    if (saturation >= MAX_SATURATION/2 && lives_left >= MAX_AGE/4) {
        findPartner();
    } else {
        findFood();
    }
}

template <typename Food>
void FishImpl<Food>::age() {
    --lives_left;
}


template <typename Food>    
bool FishImpl<Food>::update() {
    findAim();
    travel();
    starve();
    age();
    return isAlive();
}

template <typename Food>
void FishImpl<Food>::eat(const Position& pos) {
    (*ocean)[pos.x][pos.y].destroyObject();
    (*ocean)[pos.x][pos.y].insert(this);
    (*ocean)[position.x][position.y].forgetObject();
    ++saturation;
    position = pos;
}

template <typename Food>
bool FishImpl<Food>::isAlive() {
    return lives_left > 0 && saturation > 0;
}


OceanImpl impl(2, 2);
Herbivore h(Position{0, 3}, 2, 2, &impl);
Predator p(Position{0, 3}, 2, 2, &impl);
