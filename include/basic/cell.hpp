#ifndef CELL_HPP
#define CELL_HPP

#include "global.hpp"
#include "object.hpp"
#include "double_insertion.hpp"
#include <optional>
#include <memory>

class Cell {
private:
    Position position;
    Object* item;
    bool changed = false;
public:
    void reset();
    void switchOn();
    bool isSwitched();
    Cell();
    bool isEmpty() const;
    void insert(Object*);
    Object* get();
    void destroyObject();
    void forgetObject();
    ~Cell();
};

#endif