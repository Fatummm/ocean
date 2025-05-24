#include <iostream>
#include <t_ocean.hpp>
#include <fish.hpp>

int main() {
    srand(time(NULL));
    Ocean to(std::cout, ROWS, COLUMNS);
    to.start();
}