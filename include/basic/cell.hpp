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
    std::optional<std::shared_ptr<Object>> item;
public:
    Cell();
    bool isEmpty() const;
    void insert(const std::shared_ptr<Object>&);
    std::shared_ptr<Object>& get();
};

#endif