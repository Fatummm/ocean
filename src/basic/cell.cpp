#include "cell.hpp"

Cell::Cell(): item(nullptr) {}


bool Cell::isEmpty() const {
    return item == nullptr;
}

void Cell::insert(Object* object) {
    if (!isEmpty()) 
    throw double_insertion("Trying to insert an object into a full cell");
    changed = true;
    item = object;
}

Object* Cell::get() {
    return item;
}

void Cell::reset() {
    changed = false;
}

void Cell::switchOn() {
    changed = true;
}

bool Cell::isSwitched() {
    return changed;
}

Cell::~Cell() {
    if (item != nullptr) delete item;
}

void Cell::destroyObject() {
    if (item != nullptr) delete item;
    item = nullptr;
}

void Cell::forgetObject() {
    item = nullptr;
}