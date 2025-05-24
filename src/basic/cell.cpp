#include "cell.hpp"

Cell::Cell(): item(std::nullopt) {}


bool Cell::isEmpty() const {
    return !item.has_value();
}

void Cell::insert(const std::shared_ptr<Object>& object) {
    if (!isEmpty()) 
    throw double_insertion("Trying to insert an object into a full cell");
}

std::shared_ptr<Object>& Cell::get() {
    return item.value();
}

